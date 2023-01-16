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
    
    menu = al_load_bitmap("./picture/scene/menu.jpeg");
    sample1 = al_load_sample("./sound/background_sound.wav");//background music
    background_sound = al_create_sample_instance(sample1);
    al_set_sample_instance_playmode(background_sound, ALLEGRO_PLAYMODE_LOOP);
    sample2 = al_load_sample("./sound/click_sound.wav");
    click_sound = al_create_sample_instance(sample2);
    al_set_sample_instance_playmode(click_sound, ALLEGRO_PLAYMODE_ONCE);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(background_sound, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(click_sound, al_get_default_mixer());
    al_set_sample_instance_gain(click_sound, 5);
    al_set_sample_instance_gain(background_sound, 0.3);
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
            case ALLEGRO_KEY_ENTER:
                printf("press ENTER\n");
                next_window = true;
                select_capture = 1;
                al_play_sample_instance(click_sound);
                break;
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
void
Menu::destroy()
{
    printf("destroy menu\n");
    al_destroy_bitmap(menu);
    al_destroy_sample_instance(background_sound);
    al_destroy_sample_instance(click_sound);
}
