#include "Mode_capture.h"
#include "global.h"
Mode_capture::~Mode_capture()
{
    
}
 Mode_capture::Mode_capture()
 {
     if(!al_init())
     {
         show_err_msg(-1);
     }
     printf("Capture Initializing...\n");
     
     capture_display = al_create_display(window_width, window_height);
     capture_event_queue = al_create_event_queue();
     capture_timer = al_create_timer(1.0/60);
     
     if(capture_display == NULL || capture_event_queue == NULL){
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
     
     al_register_event_source(capture_event_queue, al_get_display_event_source(capture_display));
     al_register_event_source(capture_event_queue, al_get_mouse_event_source());
     al_register_event_source(capture_event_queue, al_get_keyboard_event_source());
     al_register_event_source(capture_event_queue, al_get_timer_event_source(capture_timer));
     
     Mode_init();
     
 }

void
Mode_capture::Mode_init(){
    icon = al_load_bitmap("./picture/explosion.png");
    al_set_display_icon(capture_display, icon);
    select_character.init();
}
/*
void
Mode_capture::Mode_reset(){
    
}
 */
void
Mode_capture::Mode_play(){
    printf("capture play\n");
    int msg;
    srand(time(NULL));
    
    msg = -1;
    //game_reset();
    Mode_begin();
    
    while (msg != GAME_EXIT)
    {
        msg = Mode_run();
        if(msg == MODE_EXIT){
            printf("Capture game over\n");
            //msg = GAME_EXIT;
        }
    }
    
    show_err_msg(msg);
}

void
Mode_capture::Mode_begin(){
    printf("Mode begin\n");
    al_reserve_samples(20);
    al_start_timer(capture_timer);
}

int
Mode_capture::Mode_run(){
    printf("Mode run\n");
    int error = MODE_CONTINUE;
    if(draw){
        Mode_draw();
        draw = false;
        if(!al_is_event_queue_empty(capture_event_queue)){
            error = Mode_process_event();
        }
        
    }
    return error;
}
void
Mode_capture::Mode_draw(){
    printf("mode draw\n");
    if(mode_window == 0){
        select_character.draw();
    }
    al_flip_display();
}

int
Mode_capture::Mode_process_event(){
    int error = MODE_CONTINUE;
    while (! MODE_EXIT){
        al_wait_for_event(capture_event_queue, &capture_event);
        if (capture_event.type == ALLEGRO_EVENT_KEY_UP || capture_event.type == ALLEGRO_EVENT_KEY_DOWN) {
           if (capture_event.keyboard.display == capture_display) {
              // use key
               printf("capture event\n");
               if(mode_window == 0){
                   select_character.process(capture_event);
               }
               if(capture_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                   printf("ESC\n");
                   error = MODE_EXIT;
               }else if(capture_event.type == ALLEGRO_EVENT_TIMER){
                   if(capture_event.timer.source == capture_timer)
                       printf("capture_timer\n");
                           draw = true;
               }
           }
           else {
              continue;
           }
        }
    }
    
    
    
    if(draw) Mode_update(error);
    return error;
}

void
Mode_capture::Mode_update(int stage){
    printf("mode update\n");
    if(mode_next_window && mode_window == 0){
        printf("mode next window\n");
        mode_next_window = false;
        //select_character.~Select_Character();
        //for testing
    }
    
}
/*
void
Mode_capture::draw_Mode_map(){
    
}
*/
/*
void
Mode_capture::draw_Mode_item(){
    
}
*/
void
Mode_capture::Mode_destroy(){
    printf("Mode destroy\n");
    al_destroy_display(capture_display);
    al_destroy_timer(capture_timer);
    al_destroy_bitmap(icon);
    select_character.~Select_Character();
}





