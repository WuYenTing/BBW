#include "Player2_win.h"
void
Player2_win::init()
{
    printf("player2 win init\n");
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_acodec_addon();
    
    picture = al_load_bitmap("./picture/scene/scene_player2_win.jpeg");
    sample = al_load_sample("./sound/sound_game_succeed.wav");//background music
    background_sound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(background_sound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(background_sound, al_get_default_mixer());
    al_set_sample_instance_gain(background_sound, 1);
    al_play_sample_instance(background_sound);
}

int
Player2_win::process(ALLEGRO_EVENT event)
{
    printf("player2 win_process\n");
    if(event.type == ALLEGRO_EVENT_KEY_UP){
        switch (event.keyboard.keycode) {
            case ALLEGRO_KEY_ESCAPE:
                printf("press ESC\n");
                return GAME_EXIT;
            case ALLEGRO_KEY_ENTER:
                printf("press ENTER\n");
                next_window = true;
                //return PLAYER_1;
                break;
           
        }
    }
    return GAME_CONTINUE;
}

void
Player2_win::draw()
{
    al_draw_bitmap(picture, 0, 0, 0);
    printf("draw player2 win\n");
}
void
Player2_win::destroy()
{
    printf("destroy player2 win\n");
    al_destroy_bitmap(picture);
    al_destroy_sample_instance(background_sound);
}
