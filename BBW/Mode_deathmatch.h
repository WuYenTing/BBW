#ifndef Mode_capture_h
#define Mode_capture_h


#include "Mode.h"
#include "Player.h"
#include "Item.h"

const float FPS_deathmatch = 60;
class Mode_deathmatch : public Mode
{
public:
    Mode_deathmatch();
    
    void Mode_init();
    void Mode_reset();
    
    int Mode_run();
    int Mode_update();

    void show_err_msg(int msg);
    void Mode_destroy();

    // each drawing scene function
    void draw_Mode_map();
    void draw_Mode_item();

    // process of updated event
    int Mode_process_event();
    
    Player* create_player();
    Item* create_item();
    
    ~Mode_deathmatch();
private:
    ALLEGRO_BITMAP *deathmatch_map = NULL;
    ALLEGRO_DISPLAY* deathmatch_display = NULL;
    
    ALLEGRO_EVENT_QUEUE *deathmatch_event_queue = NULL;
    ALLEGRO_EVENT deathmatch_event;
    
    ALLEGRO_TIMER *deathmatch_timer = NULL;
    
    ALLEGRO_SAMPLE *deathmatch_sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *deathmatch_startSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *deathmatch_clearSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *deathmatch_failSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *deathmatch_background_sound = NULL;
        
};

#endif  /*Mode_capture_h*/
