#include "Menu.h"
void
Menu::init()
{
    printf("init menu\n");
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_acodec_addon();
    
    menu = al_load_bitmap("./picture/menu.jpeg");
    sample = al_load_sample("./sound/background_sound.wav");//background music
    background_sound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(background_sound, ALLEGRO_PLAYMODE_LOOP);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(background_sound, al_get_default_mixer());
    al_set_sample_instance_gain(background_sound, 1);
    al_play_sample_instance(background_sound);
}

int
Menu::process(ALLEGRO_EVENT event)
{
    printf("menu_process\n");
    if(event.type == ALLEGRO_EVENT_KEY_UP){
        switch (event.keyboard.keycode) {
            case ALLEGRO_KEY_ESCAPE:
                printf("press ESC in menu process\n");
                return GAME_EXIT;
            case ALLEGRO_KEY_1:
                printf("press 1\n");
                next_window = true;
                return CAPTURE;
            case ALLEGRO_KEY_2:
                printf("press 2\n");
                next_window = true;
                return CLASSIC;
            case ALLEGRO_KEY_3:
                printf("press 3\n");
                next_window = true;
                return DEATHMATCH;
        }
    }
    return GAME_CONTINUE;
}

void
Menu::draw()
{
    al_draw_bitmap(menu, 0, 0, 0);
    printf("draw menu\n");
}

Menu::~Menu()
{
    printf("destroy menu\n");
    al_destroy_bitmap(menu);
    al_destroy_sample_instance(background_sound);
}
