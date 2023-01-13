#ifndef Mode_h
#define Mode_h
#include "Player.h"
#include "Item.h"
class Mode
{
public:
    enum item_list {WATERBOMB, MAXDRUG, LIGHTNING, CROSS, SHIELD, BOXGLOVING};
    virtual int Mode_run();
    virtual int Mode_update();

    virtual void show_err_msg(int msg);
    virtual void Mode_destroy();

    // each drawing scene function
    virtual void draw_Mode_map();
    virtual void draw_Mode_item();

    // process of updated event
    virtual int process_event();
    Player* create_player();
    Item* create_item(item_list,int,int);
    ~Mode();
    bool initial = true;
    
private:
};
#endif // MODE_H_INCLUDED
