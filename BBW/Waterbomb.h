#ifndef WATERBOMB_H_INCLUDED
#define WATERBOMB_H_INCLUDED
#include "Item.h"
class Waterbomb : public Item
{
public:
    Waterbomb(int pos_x, int pos_y)
    {
        this->item = new item(pos_x, pos_y);
        waterbomb_pos_x = pos_x;
        waterbomb_pos_y = pos_y;
        char path[50];
        for(int i=0;i<3;i++){
            sprintf(path, "./picture/waterbomb/waterbomb%d.png", i);
        }
    }
    ~Waterbomb();
    void Draw(){
        
    }
    int waterbomb_pos_x;
    int waterbomb_pos_y;
};

Waterbomb::Waterbomb(/* args */)
{
}

Waterbomb::~Waterbomb()
{
}

#endif // WATERBOMB_H_INCLUDED
