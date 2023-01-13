#ifndef LIGHTNING_H_INCLUDED
#define LIGHTNING_H_INCLUDED
#include "Item.h"
class Lightning : public Item
{
public:
    Lightning(int pos_x, int pos_y)
    {
        this->item = new item(pos_x, pos_y);
        lightning_pos_x = pos_x;
        lightning_pos_y = pos_y;
        char path[50];
        for(int i=0;i<3;i++){
            sprintf(path, "./picture/lightning/lightning%d.png", i);
        }
    }
    ~Lightning();
    void Draw(){
        
    }
    int lightning_pos_x;
    int lightning_pos_y;
};

Lightning::Lightning(/* args */)
{
}

Lightning::~Lightning()
{
}

#endif // LIGHTNING_H_INCLUDED
