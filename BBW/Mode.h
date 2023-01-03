#ifndef Mode_h
#define Mode_h
#include "global.h"
class Mode
{
public:

    virtual int Mode_run();
    virtual int Mode_update();

    virtual void show_err_msg(int msg);
    virtual void Mode_destroy();

    // each drawing scene function
    virtual void draw_Mode_map();
    virtual void draw_Mode_item();

    // process of updated event
    virtual int process_event();
    
   

   
    ~Mode();

public:
    bool initial = true;

};
#endif // MODE_H_INCLUDED
