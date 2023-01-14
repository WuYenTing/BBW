#ifndef Mode_classic_h
#define Mode_classic_h
#include "Mode.h"
#include "Player.h"
#include "Item.h"
#include "global.h"

const float FPS_classic = 60;

class Mode_classic : public Mode
{
public:
    Mode_classic();
    
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
    int process_event();
    Player* create_player();
    Item* create_item();
    
    ~Mode_classic();
private:
    ALLEGRO_BITMAP *classic_map = NULL;
    ALLEGRO_DISPLAY* classic_display = NULL;
    
    ALLEGRO_EVENT_QUEUE *classic_event_queue = NULL;
    ALLEGRO_EVENT classic_event;
    
    ALLEGRO_TIMER *classic_timer = NULL;
    
    ALLEGRO_SAMPLE *classic_sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *classic_startSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *classic_clearSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *classic_failSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *classic_background_sound = NULL;
};
#endif  /*Mode_classic_h*/
