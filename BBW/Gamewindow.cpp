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
    if(window == 0){
        menu.draw();
    }else if(window == 1){
        select_character.draw();
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
        window = 1;
       
    }else if(next_window && window == SELECT_CHARATER){
        //
        
    }

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
        if(error == CAPTURE || error == CLASSIC || error == DEATHMATCH ){
            draw = true;
        }
    }else if (window == SELECT_CHARATER){
        error = select_character.process(event);
    }else if(window == CAPTURE_MAP){
        
    }else if(window == CLASSIC_MAP){
        
    }else if(window == DEATHMATCH){
        
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


