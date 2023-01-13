//
//  Mode.cpp
//  BBW
//
//  Created by 吳彥廷 on 2023/1/4.
//

#include <iostream>
#include "Mode.h"
int
Mode::Mode_run()
{
    return 0;
}

int
Mode::Mode_update()
{
    return 0;
}

void
Mode::show_err_msg(int msg)
{
    
}

void
Mode::Mode_destroy()
{
    
}

void
Mode::draw_Mode_map()
{
    
}

void
Mode::draw_Mode_item()
{
    
}


int
Mode::process_event()
{
    return 0;
}

Player* Mode::create_player(){
    Player* p = NULL;
    p = new Player(rand()%1930+70,rand()%1430+70);
    return p;
}

Item* Mode::create_item(item_list item,int x,int y){
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
