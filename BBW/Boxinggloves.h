#ifndef BOXINGGLOVES_H_INCLUDED
#define BOXINGGLOVES_H_INCLUDED
#include "Item.h"
class Boxinggloves : public Item
{
public:
    Boxinggloves(int pos_x, int pos_y)
    {
        this->item = new item(pos_x, pos_y);
        boxinggloves_pos_x = pos_x;
        boxinggloves_pos_y = pos_y;
        char path[50];
        for(int i=0;i<3;i++){
            sprintf(path, "./picture/boxinggloves/boxinggloves%d.png", i);
        }
        
    }
    ~Boxinggloves();
    void Draw(){
        
    }
    int boxinggloves_pos_x;
    int boxinggloves_pos_y;
private:
};

Boxinggloves::Boxinggloves(/* args */)
{
}

Boxinggloves::~Boxinggloves()
{
}

#endif // BOXINGGLOVES_H_INCLUDED
