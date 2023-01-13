#ifndef MAXDRUG_H_INCLUDED
#define MAXDRUG_H_INCLUDED
#include "Item.h"
class Maxdrug : public Item
{
public:
    Maxdrug(int pos_x, int pos_y)
    {
        this->item = new item(pos_x, pos_y);
        maxdrug_pos_x = pos_x;
        maxdrug_pos_y = pos_y;
        char path[50];
        for(int i=0;i<3;i++){
            sprintf(path, "./picture/maxdrug/maxdrug%d.png", i);
        }
    }
    ~Maxdrug();
    void Draw(){
        
    }
    int maxdrug_pos_x;
    int maxdrug_pos_y;
};

Maxdrug::Maxdrug(/* args */)
{
}

Maxdrug::~Maxdrug()
{
}

#endif // MAXDRUG_H_INCLUDED
