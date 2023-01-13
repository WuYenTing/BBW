#ifndef CROSSS_H_INCLUDED
#define CROSSS_H_INCLUDED
#include "Item.h"
class Cross : public Item
{
public:
    Cross(int pos_x, int pos_y)
    {
        this->item = new item(pos_x, pos_y);
        cross_pos_x = pos_x;
        cross_pos_y = pos_y;
        char path[50];
        for(int i=0;i<3;i++){
            sprintf(path, "./picture/cross/cross%d.png", i);
        }
    }
    ~Cross();
    void Draw(){
        
    }
    int cross_pos_x;
    int cross_pos_y;
};

Cross::Cross(/* args */)
{
}

Cross::~Cross()
{
}

#endif // CROSSS_H_INCLUDED
