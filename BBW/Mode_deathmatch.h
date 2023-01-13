#ifndef Mode_deathmatch_h
#define Mode_deathmatch_h
#include "Mode.h"
#include "Player.h"
#include "Item.h"
class Mode_deathmatch : public Mode
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
    ~Mode_deathmatch();
private:
};
#endif /* Mode_deathmatch_h */

