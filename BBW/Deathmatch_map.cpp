#include "deathmatch_map.h"
void
Deathmatch_map::init()
{
    printf("init capture map\n");
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_acodec_addon();
    
    picture = al_load_bitmap("./picture/scene/deathmatch_map.jpeg");
    sample = al_load_sample("./sound/background_sound.wav");//background music
    background_sound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(background_sound, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(background_sound, al_get_default_mixer());
    al_set_sample_instance_gain(background_sound, 1);
    al_play_sample_instance(background_sound);
}

void
Deathmatch_map::draw()
{
    al_draw_bitmap(picture, 0, 0, 0);
    printf("draw map\n");
}
void
Deathmatch_map::destroy()
{
    printf("destroy map\n");
    al_destroy_bitmap(picture);
    al_destroy_sample_instance(background_sound);
}
