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
    
    game_init();
    
}

void
Gamewindow::game_init()
{
    icon = al_load_bitmap("./picture/explosion.png");
    al_set_display_icon(display, icon);
    
    start_menu = al_load_bitmap("./picture/menu.jpeg");
    al_draw_bitmap(start_menu, 0, 0, 0);
    printf("draw menu\n");

    al_wait_for_event(event_queue, &event);
    
    
    al_reserve_samples(20);//set mixer
    sample = al_load_sample("./sound/background_sound.wav");//background music
    background_sound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(background_sound, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(background_sound, al_get_default_mixer());
    al_set_sample_instance_gain(background_sound, 1);
    al_play_sample_instance(background_sound);
    
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
    
    printf("game run\n");
    while (msg != GAME_EXIT)
    {
        msg = mode_select();
    }
    
    show_err_msg(msg);
}

void
Gamewindow::game_begin()
{
    printf("Game begin\n");
    
    al_start_timer(timer);
    
}

int Gamewindow::mode_select()
{
    printf("mode select\n");
    int error = GAME_CONTINUE;
    if(draw){
        game_draw();
        draw = false;
    }
    if (!al_is_event_queue_empty(event_queue))
    {
        if( event.type == ALLEGRO_EVENT_KEY_UP )
            {
                if(event.keyboard.keycode == ALLEGRO_KEY_A )
                {
                    printf("KEY_A:CAPTURE\n");
                    select_mode = CAPTURE;
                }
                if(event.keyboard.keycode == ALLEGRO_KEY_B){
                    printf("KEY_B:CLASSIC\n");
                    select_mode = CLASSIC;
                }
                if (event.keyboard.keycode == ALLEGRO_KEY_C) {
                    printf("KEY_C:DEATHMATCH\n");
                    select_mode = DEATHMATCH;
                }
                if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                {
                    printf("ESC\n");
                    return GAME_EXIT;
                }
            }
        if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
                return GAME_EXIT;
        }
        error = process_event();
    }
    
    return error;
}
void
Gamewindow::game_draw(){
    al_flip_display();
}

int
Gamewindow::game_update()
{
    
    {
        if(judge_move_to_mode){
            al_destroy_bitmap(start_menu);
            al_destroy_sample_instance(background_sound);
            al_stop_timer(timer);
            
            if(select_mode == CLASSIC)
            {
                /*
                Mode_capture *capture = new Mode_capture();
                capture->Mode_play();
                delete capture;
                */
            }else if(select_mode == CAPTURE)
            {
                /*
                Mode_classic *classic = new Mode_classic();
                classic->Mode_play();
                delete classic;
                 */
            }else if (select_mode == DEATHMATCH)
            {
                /*
                Mode_deathmatch *deathmatch = new Mode_deathmatch();
                deathmatch->Mode_play();
                delete deathmatch;
                */
            }
            
            judge_move_to_mode = false;
            al_start_timer(timer);
            
        }
        return GAME_CONTINUE;
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
        fprintf(stderr, "unexpected msg: %d", msg);
    }
    game_destroy();
    exit(9);
}
void
Gamewindow::game_destroy()
{
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);
    al_destroy_bitmap(icon);
    //al_destroy_bitmap(start_menu);
    //al_destroy_font(button);
    
}

// process of updated event
int
Gamewindow::process_event()
{
    al_wait_for_event(event_queue, &event);
    
    printf("process event\n");
    if(select_mode == CLASSIC ||select_mode == CAPTURE || select_mode == DEATHMATCH)
    {
        judge_move_to_mode = true;
    }
    if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        printf("ESC\n");
        return GAME_EXIT;
    }
    /*if(event.type == ALLEGRO_EVENT_TIMER){
        if(event.timer.source == FPS)
                draw = true;
    }*/
    if(draw) game_update();
    printf("GAME_CONTINUE\n");
    return GAME_CONTINUE;
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


