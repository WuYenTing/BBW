#include "Capture_map.h"
void
Capture_map::init()
{
    printf("init capture map\n");
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_acodec_addon();
    
    picture = al_load_bitmap("./picture/scene/capture_map.jpeg");
    sample = al_load_sample("./sound/capture_sound.wav");//background music
    p1_life = al_load_ttf_font("./Oswald_Regular.ttf", 36, 0);            //add
        g_time = al_load_ttf_font("./Oswald_Regular.ttf", 36, 0);             //add
        p2_life = al_load_ttf_font("./Oswald_Regular.ttf", 36, 0);

    background_sound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(background_sound, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(background_sound, al_get_default_mixer());
    al_set_sample_instance_gain(background_sound, 0.25);
    al_play_sample_instance(background_sound);
}

void
Capture_map::draw()
{
    al_draw_bitmap(picture, 0, 0, 0);
    al_draw_text(p1_life, al_map_rgb(0, 0, 0), 35, 15, 0, p1_life_string);         //add
        al_draw_text(g_time, al_map_rgb(0, 0, 0), 900, 15, 0, time_string);          //add
        al_draw_text(p2_life, al_map_rgb(0, 0, 0), 1500, 15, 0, p2_life_string);
    printf("draw map\n");
}
void
Capture_map::destroy()
{
    printf("destroy map\n");
    al_destroy_bitmap(picture);
    al_destroy_sample_instance(background_sound);
    al_destroy_font(p1_life);
    al_destroy_font(p2_life);
    al_destroy_font(g_time);
}
