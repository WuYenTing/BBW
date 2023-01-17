#include "Item_intro.h"
void
Item_intro::init()
{
    printf("init intro\n");
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_acodec_addon();
    
    picture = al_load_bitmap("./picture/scene/item_intro.jpeg");
    sample1 = al_load_sample("./sound/capture_sound.wav");//background music
    background_sound = al_create_sample_instance(sample1);
    al_set_sample_instance_playmode(background_sound, ALLEGRO_PLAYMODE_LOOP);
    sample2 = al_load_sample("./sound/click_sound.wav");
    click_sound = al_create_sample_instance(sample2);
    al_set_sample_instance_playmode(click_sound, ALLEGRO_PLAYMODE_ONCE);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(background_sound, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(click_sound, al_get_default_mixer());
    al_set_sample_instance_gain(click_sound, 5);
    al_set_sample_instance_gain(background_sound, 0.8);
    al_play_sample_instance(background_sound);
}

int
Item_intro::process(ALLEGRO_EVENT event)
{
    printf("intro_process\n");
    if(event.type == ALLEGRO_EVENT_KEY_UP){
        switch (event.keyboard.keycode) {
            case ALLEGRO_KEY_ESCAPE:
                printf("press ESC in menu process\n");
                return GAME_EXIT;
            case ALLEGRO_KEY_ENTER:
                printf("press ENTER\n");
                next_window = true;
                al_play_sample_instance(click_sound);
                break;
        }
    }
    return GAME_CONTINUE;
}

void
Item_intro::draw()
{
    al_draw_bitmap(picture, 0, 0, 0);
    printf("draw intro\n");
}
void
Item_intro::destroy()
{
    printf("destroy intro\n");
    al_destroy_bitmap(picture);
    al_destroy_sample_instance(background_sound);
    al_destroy_sample_instance(click_sound);
}
