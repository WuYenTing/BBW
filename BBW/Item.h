#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include "Object.h"
#include "Circle.h"
#include "global.h"
#include "Player.h"
#include <stdio.h>
class Item : public Object
{
public:
    Item(int = 0, int = 0);
    virtual ~Item();

    // override virtual function "Object::Draw"
    virtual void Draw();
    bool trigger(Player*);
    int pos_x;
    int pos_y;

    // information of Item
    int type;
    ALLEGRO_BITMAP* item_img[3];
private:
};

#endif // ITEM_H_INCLUDED
