#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "Object.h"
#include "global.h"
#include "Player.h"
class Item : public Object
{
public:
    Item(int x= 0, int y= 0);
    ~Item();
    void Draw();
    void item_init(Player*,Player*,Player*,Player*);
    void item_update();
    bool trigger();
    int anime;
    int anime_time;
    int pos_x;
    int pos_y;
    int item_start;
    Player *p1;
    Player *p2;
    Player *p3;
    Player *p4;
    ALLEGRO_BITMAP* item_img[3];
    ALLEGRO_TIMER* item_timer = NULL;
};

#endif // ITEM_H_INCLUDED
