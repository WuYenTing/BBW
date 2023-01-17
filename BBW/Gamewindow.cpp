#include "Gamewindow.h"
#include "global.h"

#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define button_width 890
#define button_height 171

Gamewindow::~Gamewindow(){}
Gamewindow::Gamewindow()
{
    if(!al_init())
    {
        show_err_msg(-1);
    }
    printf("Game Initializing...\n");
    
    display = al_create_display(window_width, window_height);//window_widthh,window_height, define in global.h
    event_queue = al_create_event_queue();
    
    timer = al_create_timer(1.0/60);//FPS
    
    if(display == NULL ||event_queue == NULL)
    {
        show_err_msg(-1);
    }
    
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_acodec_addon();
    
    al_install_audio();
    al_install_mouse();
    al_install_keyboard();
    
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    
    game_init();
    
}

void
Gamewindow::game_init()
{
    icon = al_load_bitmap("./picture/explosion.png");
    al_set_display_icon(display, icon);
    
    //sample = al_load_sample("");//click sound
    //click_sound = al_create_sample_instance(sample);
    
}
/*
void
Gamewindow::game_reset()
{
    
}
*/
void
Gamewindow::game_play()
{
    printf("game play\n");
    int msg;
    srand(time(NULL));
    
    
    msg = -1;
    //game_reset();
    game_begin();
    
    while (msg != GAME_EXIT)
    {
        msg = game_run();
        if(msg == GAME_EXIT /*|| msg == CLASSIC || msg == CAPTURE || msg == DEATHMATCH* only for testing*/){
            printf("Game over\n");
            //msg = GAME_EXIT;
        }
    }
    
    show_err_msg(msg);
}

void
Gamewindow::game_begin()
{
    printf("Game begin\n");
    al_reserve_samples(20);//set mixer
    al_start_timer(timer);
    menu.init();
    
}

int Gamewindow::game_run()
{
    printf("game_run\n");
    int error = GAME_CONTINUE;
    if(draw){
        game_draw();
        draw = false;
    }
    if (!al_is_event_queue_empty(event_queue))
    {
        error = process_event();
    }
    
    return error;
}
void
Gamewindow::game_draw(){
    printf("game draw\n");
    if(window == MENU){
        menu.draw();
    }else if(window == ITEM_INTRO ){
        item_intro.draw();
    }else if(window == SELECT_CHARATER){
        select_character.draw();
    }else if(window == CAPTURE_MAP){
        capture_map.draw();
        
        p1->Draw();
        p1->Draw_waterbomb();
        p2->Draw();
        p2->Draw_waterbomb();
        //it->Draw();
        cr->Draw();
        bx->Draw();
         
        mg->Draw();
        mk->Draw();
        li->Draw();
        sh->Draw();
        
        //ob->Draw();
    }else if (window == PLAYER1_WIN){
        player1_win.draw();
    }else if (window == PLAYER2_WIN){
        player2_win.draw();
    }else if (window == PLAYER_TIE){
        player1_win.draw();
    }
    al_flip_display();
}

void
Gamewindow::game_update()
{
    printf("game update\n");
    if(next_window && window == MENU){
        //printf("next window\n");
        menu.destroy();
        item_intro.init();
        next_window = false;
        window = ITEM_INTRO;
    }else if(next_window && window == ITEM_INTRO){
        item_intro.destroy();
        select_character.init();
        next_window = false;
        window = SELECT_CHARATER;
       
    }else if(next_window && window == SELECT_CHARATER){
        select_character.destroy();
      
            capture_map.init();
            ts = al_get_time();
        
        
            window = CAPTURE_MAP;
        
        
        p1->player_init(W,S,A,D,X,1);
        p1->waterbomb_init();
        p2->player_init(I,K,J,L,M,2);
        p2->waterbomb_init();
        cr->cross_init(p1, p2, p3, p4);
        //it->item_init(p1, p2, p3, p4);
        bx->boxinggloves_init(p1, p2, p3, p4);
            
        mg->maxdrug_init(p1, p2, p3, p4);
        mk->magicdrink_init(p1, p2, p3, p4);
        li->lightning_init(p1, p2, p3, p4);
        sh->shield_init(p1, p2, p3, p4);
        //ob->obstacle_init(p1, p2, p3, p4);
        sprintf(p1_life_string, "P1 LIFE : %.2f", p1->life );
        sprintf(p2_life_string, "P2 LIFE : %.2f", p2->life );
        sprintf(time_string, "time = %3d", 181);
        next_window = false;
        
    }else if(window == CAPTURE_MAP /*|| window == DEATHMATCH_MAP*/){
        
        p1->player_update();
        p1->waterbomb_update(p2->getX(),p2->getY());
        if(p1->waterbomb_trigger(p2->getX(),p2->getY())){
            (p2->life)=(p2->life)-(0.1);
            printf("p2 life %f\n",p2->life);
        }
        p2->player_update();
        p2->waterbomb_update(p1->getX(),p1->getY());
        if(p2->waterbomb_trigger(p1->getX(),p1->getY())){
            (p1->life)=(p1->life)-(0.1);
            printf("p1 life %f\n",p1->life);
        }
        //it->item_update();
        cr->cross_update();
        bx->boxinggloves_update();
           
        mg->maxdrug_update();
        mk->magicdrink_update();
        li->lightning_update();
        sh->shield_update();
        //ob->obstacle_update();
        elapsed_time = 181 - (al_get_time() - ts);
        game_time = (int) elapsed_time;
        
        sprintf(p1_life_string, "P1 LIFE : %.2f", p1->life);
        sprintf(p2_life_string, "P2 LIFE : %.2f", p2->life);
        sprintf(time_string, "time = %3d", game_time);
        
        if(game_time == 0 || p1->life <= 0 || p2->life <= 0){
            if(p1->life > p2->life){
                next_window = true;
                window = PLAYER1_WIN;
            }else if(p1->life < p2->life){
                next_window = true;
                window = PLAYER2_WIN;
            }else if(p1->life == p2->life){
                next_window = true;
                window = PLAYER_TIE;
            }
        }
         
    }
    
    if(next_window && window == PLAYER1_WIN){
        //if(select_capture){
            capture_map.destroy();

        //}else if(select_deathmatch){
            //deathmatch_map.destroy();
        //}
        player1_win.init();
        next_window = false;
        
    }else if (next_window && window == PLAYER2_WIN){
        //if(select_capture){
            capture_map.destroy();
        /*}else if(select_deathmatch){
            deathmatch_map.destroy();
        }*/
        player2_win.init();
        next_window = false;
    }else if (next_window && window == PLAYER_TIE){
        //if(select_capture){
            capture_map.destroy();
        /*}else if(select_deathmatch){
            deathmatch_map.destroy();
        }*/
        player_tie.init();
        next_window = false;
    }

}

// process of updated event
int
Gamewindow::process_event()
{
    int error = GAME_CONTINUE;
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    printf("process event\n");
    
    if(window == MENU){
        error = menu.process(event);
        if(error == CAPTURE /*||error == DEATHMATCH */){
            draw = true;
        }
        if(error == GAME_EXIT) return GAME_EXIT;
    }else if(window == ITEM_INTRO){
        error = item_intro.process(event);
    }
    else if (window == SELECT_CHARATER){
        error = select_character.process(event);
        draw = true;
        
    }else if(window == CAPTURE_MAP){
        
        p1 ->player_process(event,timer);
        p2 ->player_process(event,timer);
        
    }else if (window == PLAYER1_WIN){
        error = player1_win.process(event);
        if(error == GAME_EXIT || next_window) return GAME_EXIT;
        
    }else if (window == PLAYER2_WIN){
        error = player2_win.process(event);
        if(error == GAME_EXIT|| next_window) return GAME_EXIT;
    }else if (window == PLAYER_TIE){
        error = player_tie.process(event);
        if(error == GAME_EXIT|| next_window)return  GAME_EXIT;
    }
    
    if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || event.type == ALLEGRO_KEY_ESCAPE){
        printf("ESC\n");
        error = GAME_EXIT;
    }else if(event.type == ALLEGRO_EVENT_TIMER){
        if(event.timer.source == timer)
            printf("timer\n");
                draw = true;
    }
    if(draw) game_update();
    //printf("GAME_CONTINUE\n");
    return error;
}

void
Gamewindow::show_err_msg(int msg)
{
    if (!al_init())
    {
        fprintf(stderr, "Game Terinamted...");
    }
    else
    {
        fprintf(stderr, "unexpected msg: %d\n", msg);
    }
    game_destroy();
    exit(9);
}
void
Gamewindow::game_destroy()
{
    printf("Game destroy\n");
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);
    al_destroy_bitmap(icon);
    player1_win.destroy();
    player_tie.destroy();
    player2_win.destroy();
     //for testing
    
}

// detect if mouse hovers over a rectangle
bool
Gamewindow::mouse_hover(int startx, int starty, int width, int height)
{
    if(mouse_x >= startx && mouse_x <= startx + width)
    {
        if(mouse_y >= starty && mouse_y <= starty + height)
        {
            return true;
        }
    }

    return false;
}
// detect if a tower will be constructed on road
Player*
Gamewindow::create_player(int x,int y){
    Player *p = NULL;
    p = new Player(x,y);
    return p;
}
Boxinggloves*
Gamewindow::create_boxinggloves()
{
    Boxinggloves* x = NULL;
    printf("creat Boxinggloves \n");
    x = new Boxinggloves(74,350);
    printf("creat Boxinggloves success\n");
    return x;
}

Cross*
Gamewindow::create_cross()
{
    Cross *cr = NULL;
    printf("creat cross cr\n");
    cr = new Cross(702,558);
    printf("creat cross cr success\n");
    return cr;
}

Magicdrink*
Gamewindow::create_magicdrink()
{
    Magicdrink* x = NULL;
           printf("creat Magicdrink \n");
           x = new Magicdrink(1260,264);
           printf("creat Magicdrink success\n");
           return x;
       }

       Maxdrug*
       Gamewindow::create_maxdrug()
       {
           Maxdrug* x = NULL;
           printf("creat Maxdrug \n");
           x = new Maxdrug(1648,1192);
           printf("creat Maxdrug success\n");
           return x;
       }


       Lightning*
       Gamewindow::create_lightning()
       {
           Lightning* x = NULL;
           printf("creat Lightning \n");
           x = new Lightning(584,1300);
           printf("creat Lightning success\n");
           return x;
       }

       Shield*
       Gamewindow::create_shield()
       {
           Shield* x = NULL;
           printf("creat Shield \n");
           x = new Shield(1066,850);
           printf("creat Shield success\n");
           return x;
       }

       Item*
       Gamewindow::create_item()
       {
           Item *i = NULL;
           printf("creat item i\n");
           i = new Item(-100,-100);
           printf("creat item i success\n");
           return i;
       }

       Obstacle*
       Gamewindow::create_obstacle(int x,int y,int t)
       {
           Obstacle *ob = NULL;
           printf("creat item i\n");
           ob = new Obstacle(x,y,t);
           printf("creat item i success\n");
           return ob;
       }

       void
       Gamewindow::create_wall()
       {
           
       }

