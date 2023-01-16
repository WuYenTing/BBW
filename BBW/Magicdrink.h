#ifndef MAGICDRINK_H_INCLUDED
#define MAGICDRINK_H_INCLUDED
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "Object.h"
#include "global.h"
#include "Player.h"
#include "Item.h"
class Magicdrink : public Item
{
public:
    Magicdrink(int x=0, int y=0);
    ~Magicdrink();
    void Draw();
    void magicdrink_init(Player*,Player*,Player*,Player*);
    void magicdrink_update();
    bool trigger();
    int anime;
    int anime_time;
    int magicdrink_pos_x;
    int magicdrink_pos_y;
    int magicdrink_start;
    int cd_time = 0;
    Player* p1;
    Player* p2;
    Player* p3;
    Player* p4;
    ALLEGRO_BITMAP* magicdrink_img[3];
    ALLEGRO_TIMER* magicdrink_timer = NULL;
    ALLEGRO_SAMPLE *sample = NULL;// add
    ALLEGRO_SAMPLE_INSTANCE *instance;// add
};

#endif // MAGICDRINK_H_INCLUDED
