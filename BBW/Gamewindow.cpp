#include "Gamewindow.h"
#include "global.h"
#include <iostream>

#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)

Gamewindow::~Gamewindow(){}
Gamewindow::Gamewindow()
{
    if(!al_init())
    {
        show_err_msg(-1);
    }
    printf("Game Initializing...\n");
    
    display = al_create_display(2000, 1500);//window_widthh,window_height
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
    icon = al_load_bitmap("./explosion.png");
    al_set_display_icon(display, icon);
    
    start_menu = al_load_bitmap("./startmenu.jpg");
    al_draw_bitmap(start_menu, 0, 0, 0);
    
    
    button = al_load_font("Oswald_Regular.ttf", 36, 0);
    //classic button
    al_draw_rounded_rectangle(1, 0, 300, 50, 15, 15, WHITE, 5);
    al_draw_filled_rounded_rectangle(1, 1, 300, 50, 15, 15, BLACK);
    al_draw_text(button, WHITE, 10, 0, 0, " CLASSIC ");
    //capture button
    al_draw_rounded_rectangle(1, 100, 300, 150, 15, 15, WHITE, 5);
    al_draw_filled_rounded_rectangle(1, 100, 300, 150, 15, 15, BLACK);
    al_draw_text(button, WHITE, 10, 100, 0, " CAPTURE ");
    //death match
    al_draw_rounded_rectangle(1, 200, 300, 250, 15, 15, WHITE, 5);
    al_draw_filled_rounded_rectangle(1, 200, 300, 250, 15, 15, BLACK);
    al_draw_text(button, WHITE, 10, 200, 0, " DEATHMATCH ");
    //exit
    al_draw_rounded_rectangle(1, 300, 300, 350, 15, 15, WHITE, 5);
    al_draw_filled_rounded_rectangle(1, 300, 300, 350, 15, 15, BLACK);
    al_draw_text(button, WHITE, 10, 300, 0, " EXIT ");
    
    al_wait_for_event(event_queue, &event);
    
    
    al_reserve_samples(20);//set mixer
    sample = al_load_sample("./background_sound.wav");//background music
    background_sound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(background_sound, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(background_sound, al_get_default_mixer());
    al_set_sample_instance_gain(background_sound, 1);
    al_play_sample_instance(background_sound);
    
    //sample = al_load_sample("");//click sound
    //click_sound = al_create_sample_instance(sample);
    
    

    al_flip_display();
}

void
Gamewindow::game_reset()
{
    
}

void
Gamewindow::game_play()
{
    printf("game play\n");
    int msg;
    srand(time(NULL));
    
    
    msg = -1;
    game_reset();
    game_begin();

    
    printf("game run\n");
    while (msg != GAME_EXIT)
    {
        msg = game_run();
    }
    
    show_err_msg(msg);
}

void
Gamewindow::game_begin()
{
    map = al_load_bitmap("./startmenu.jpg");
    al_draw_bitmap(map, 0, 0, 0);
    al_start_timer(timer);
}

int
Gamewindow::game_run()
{
    int error = GAME_CONTINUE;
    
    
    if (!al_is_event_queue_empty(event_queue))
    {
        error = process_event();
    }
    
    return error;
}

int
Gamewindow::game_update()
{
    
    return 0;
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
        fprintf(stderr, "unepected msg: %d", msg);
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
    al_destroy_bitmap(start_menu);
    al_destroy_font(button);
    
}

// each drawing scene function
void
Gamewindow::draw_running_map()
{
    
}

// process of updated event
int
Gamewindow::process_event()
{
    al_wait_for_event(event_queue, &event);
    
    printf("process event\n");
    if(select_mode == CLASSIC)
    {
        
    }
    else if(select_mode == CAPTURE)
    {
        
    }
    else if (select_mode == DEATHMATCH)
    {
        
    }
    if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            return GAME_EXIT;
    }
    game_update();
    draw_running_map();
    
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

Item*
Gamewindow::create_item(int)
{
    Item* item = NULL;
    return item;
}

Player*
Gamewindow::create_player_1()
{
    Player* player_1 = NULL;
    return player_1;
}

Player*
Gamewindow::create_player_2()
{
    Player* player_2 = NULL;
    return player_2;
}

Player*
Gamewindow::create_player_3()
{
    Player* player_3 = NULL;
    player_3->player_init();
    return player_3;
}

Player*
Gamewindow::create_player_4()
{
    Player* player_4 = NULL;
    player_4->player_init();
    return player_4;
}
