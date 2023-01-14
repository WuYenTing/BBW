#ifndef Mode_capture_h
#define Mode_capture_h


#include "Mode.h"
#include "Player.h"
#include "Item.h"
#include "global.h"

const float FPS_capture = 60;
class Mode_capture : public Mode
{
public:
    Mode_capture();
    
    void Mode_init();
    void Mode_reset();
    void Mode_play();
    void Mode_draw();
    
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
    
    ~Mode_capture();
private:
    ALLEGRO_BITMAP *capture_map = NULL;
    ALLEGRO_DISPLAY* capture_display = NULL;
    
    ALLEGRO_EVENT_QUEUE *capture_event_queue = NULL;
    ALLEGRO_EVENT capture_event;
    
    ALLEGRO_TIMER *capture_timer = NULL;
    
    ALLEGRO_SAMPLE *capture_sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *capture_startSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *capture_clearSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *capture_failSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *capture_background_sound = NULL;
        
};

#endif  /*Mode_capture_h*/
