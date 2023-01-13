#ifndef SHIELD_H_INCLUDED
#define SHIELD_H_INCLUDED
#include "Item.h"
class Shield : public Item
{
public:
    Shield(int pos_x, int pos_y)
    {
        this->item = new item(pos_x, pos_y);
        shield_pos_x = pos_x;
        shield_pos_y = pos_y;
        char path[50];
        for(int i=0;i<3;i++){
            sprintf(path, "./picture/shield/shield%d.png", i);
        }
    }
    ~Shield();
    void Draw(){
        
    }
    int shield_pos_x;
    int shield_pos_y;
};

Shield::Shield(/* args */)
{
}

Shield::~Shield()
{
}

#endif // SHIELD_H_INCLUDED
