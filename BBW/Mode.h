#ifndef Mode_h
#define Mode_h
#include"global.h"
#include "Player.h"
#include "Item.h"
#define MODE_INIT -1
#define MODE_SETTING 0
#define MODE_SELECT 1
#define MODE_BEGIN 2
#define MODE_CONTINUE 3
#define MODE_FAIL 4
#define MODE_TERMINATE 5
#define MODE_NEXT_LEVEL 6
#define MODE_EXIT 7


class Mode
{
public:
    enum item_list {WATERBOMB, MAXDRUG, LIGHTNING, CROSS, SHIELD, BOXGLOVING};
    
    virtual void Mode_init();
    virtual void Mode_reset();
    virtual void Mode_play();
    virtual void Mode_begin();
    virtual void Mode_draw();
    
    virtual int Mode_run();
    virtual int Mode_update();

    virtual void show_err_msg(int msg);
    virtual void Mode_destroy();

    // each drawing scene function
    virtual void draw_Mode_map();
    virtual void draw_Mode_item();

    // process of updated event
    virtual int Mode_process_event();
    Player* create_player(){
        Player* p = NULL;
        p = new Player(rand()%1930+70,rand()%1430+70);
        return p;
    }
    Item* create_item(item_list,int x,int y){
        Item* i = NULL;
        /*switch(item)
        {
            case WATERBOMB:
                return new
                break;
            case MAXDRUG:
                return new
                break;
            case LIGHTNING:
                return new
                break;
            case CROSS:
                return new
                break;
            case SHIELD:
                return new
                break;
            case BOXGLOVING:
                return new
                break;
        }*/
        return i;
    }
    //~Mode();
    bool initial = true;
    
private:
};
#endif  /*MODE_H_INCLUDED*/
