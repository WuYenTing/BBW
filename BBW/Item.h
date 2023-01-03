#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
#include "Object.h"
#include "Circle.h"
#include "Character.h"
#include "global.h"
#include "Player.h"

class Item : public Object
{
public:
    Item(int = 0, int = 0);
    virtual ~Item();

    // override virtual function "Object::Draw"
    void Draw();
    bool trigger_item(Player*);

protected:
    // information of Item
    int type;
    std::vector<ALLEGRO_BITMAP*> item_img;
    
};

#endif // ITEM_H_INCLUDED
