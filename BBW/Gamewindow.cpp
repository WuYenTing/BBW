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
    //srand(time(NULL));
    
    
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
    }else if(window == SELECT_CHARATER){
        select_character.draw();
    }else if(window == CAPTURE_MAP){
        capture_map.draw();
        
        p1->Draw();
        p2->Draw();
        it->Draw();
        cr->Draw();
        bx->Draw();
         
        mg->Draw();
        mk->Draw();
        li->Draw();
        sh->Draw();
        wa->Draw();
        ob->Draw();
    }
    al_flip_display();
}

void
Gamewindow::game_update()
{
    printf("game update\n");
    if(next_window && window == MENU){
        printf("next window\n");
        menu.destroy();
        select_character.init();
        next_window = false;
        window = SELECT_CHARATER;
       
    }else if(next_window && window == SELECT_CHARATER){
        select_character.destroy();
        capture_map.init();
        
        p1->player_init(W,S,A,D,X,1);
        p2->player_init(I,K,J,L,M,2);
        cr->cross_init(p1, p2, p3, p4);
        it->item_init(p1, p2, p3, p4);
        bx->boxinggloves_init(p1, p2, p3, p4);
            
        mg->maxdrug_init(p1, p2, p3, p4);
        mk->magicdrink_init(p1, p2, p3, p4);
        li->lightning_init(p1, p2, p3, p4);
        sh->shield_init(p1, p2, p3, p4);
        wa->waterbomb_init(p1, p2, p3, p4);
        ob->obstacle_init(p1, p2, p3, p4);
         
        next_window = false;
        window = CAPTURE_MAP;
    }else if(window == CAPTURE_MAP){
        
        p1->player_update();
        p2->player_update();
        it->item_update();
        cr->cross_update();
        bx->boxinggloves_update();
           
        mg->maxdrug_update();
        mk->magicdrink_update();
        li->lightning_update();
        sh->shield_update();
        wa->waterbomb_update();
        ob->obstacle_update();
         
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
        if(error == CAPTURE ||error == DEATHMATCH ){
            draw = true;
        }
    }else if (window == SELECT_CHARATER){
        error = select_character.process(event);
        draw = true;
        
    }else if(window == CAPTURE_MAP){
        
        p1 ->player_process(event,timer);
        p2 ->player_process(event,timer);
         
        
    }else if(window == DEATHMATCH_MAP){
        
        p1 ->player_process(event,timer);
        p2 ->player_process(event,timer);
    }
    
    if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
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
    x = new Boxinggloves(300,500);
    printf("creat Boxinggloves success\n");
    return x;
}

Cross*
Gamewindow::create_cross()
{
    Cross *cr = NULL;
    printf("creat cross cr\n");
    cr = new Cross(500,500);
    printf("creat cross cr success\n");
    return cr;
}

Magicdrink*
Gamewindow::create_magicdrink()
{
    Magicdrink* x = NULL;
           printf("creat Magicdrink \n");
           x = new Magicdrink(300,300);
           printf("creat Magicdrink success\n");
           return x;
       }

       Maxdrug*
       Gamewindow::create_maxdrug()
       {
           Maxdrug* x = NULL;
           printf("creat Maxdrug \n");
           x = new Maxdrug(300,700);
           printf("creat Maxdrug success\n");
           return x;
       }


       Lightning*
       Gamewindow::create_lightning()
       {
           Lightning* x = NULL;
           printf("creat Lightning \n");
           x = new Lightning(700,700);
           printf("creat Lightning success\n");
           return x;
       }

       Shield*
       Gamewindow::create_shield()
       {
           Shield* x = NULL;
           printf("creat Shield \n");
           x = new Shield(900,700);
           printf("creat Shield success\n");
           return x;
       }

       Waterbomb*
       Gamewindow::create_waterbomb(int x,int y)
       {
           Waterbomb* wa = NULL;
           printf("creat Waterbomb \n");
           wa = new Waterbomb(x,y);
           printf("creat Waterbomb success\n");
           return wa;
       }

       Item*
       Gamewindow::create_item()
       {
           Item *i = NULL;
           printf("creat item i\n");
           i = new Item(100,100);
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

