#ifndef Mode_capture_h
#define Mode_capture_h
#include "Mode.h"
#include "Player.h"
#include "Item.h"
class Mode_capture : public Mode
{
public:
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
    ~Mode_capture();
private:
};

#endif /* Mode_capture_h */
