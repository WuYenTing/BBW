#ifndef Mode_capture_h
#define Mode_capture_h


#include "Mode.h"
#include "Player.h"
#include "Item.h"
#include "global.h"
#include "Select_Character.h"

const float FPS_capture = 60;
class Mode_capture
{
public:
    enum item_list {WATERBOMB, MAXDRUG, LIGHTNING, CROSS, SHIELD, BOXGLOVING};
    Mode_capture();
    
    void Mode_init();
    void Mode_reset();
    void Mode_play();
    void Mode_draw();
    void Mode_begin();
    
    int Mode_run();
    void Mode_update(int );

    void show_err_msg(int msg){
        if (!al_init())
        {
            fprintf(stderr, "Capture Terinamted...");
        }
        else
        {
            fprintf(stderr, "unexpected msg: %d\n", msg);
        }
        Mode_destroy();
        exit(9);
    }
    //void Mode_destroy();

    // each drawing scene function
    void draw_Mode_map();
    void draw_Mode_item();
    
    void Mode_destroy();
    // process of updated event
    int Mode_process_event();
    
    Player* create_player();
    Item* create_item();
    
    ~Mode_capture();
private:
    bool initial = true;
    
    ALLEGRO_BITMAP *icon;
    ALLEGRO_DISPLAY* capture_display = NULL;
    
    ALLEGRO_EVENT_QUEUE *capture_event_queue = NULL;
    ALLEGRO_EVENT capture_event;
    
    ALLEGRO_TIMER *capture_timer = NULL;
    Select_Character select_character;
    
    bool draw = true;
        
};

#endif  /*Mode_capture_h*/

