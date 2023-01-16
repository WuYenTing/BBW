#ifndef MAXDRUG_H_INCLUDED
#define MAXDRUG_H_INCLUDED
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
class Maxdrug : public Object
{
public:
    Maxdrug(int x=0, int y=0);
    ~Maxdrug();
    void Draw();
    void maxdrug_init(Player*,Player*,Player*,Player*);
    void maxdrug_update();
    bool trigger();
    int anime;
    int anime_time;
    int maxdrug_pos_x;
    int maxdrug_pos_y;
    int maxdrug_start;
    int cd_time = 0;
    Player* p1;
    Player* p2;
    Player* p3;
    Player* p4;
    ALLEGRO_BITMAP* maxdrug_img[3];
    ALLEGRO_TIMER* maxdrug_timer = NULL;
    ALLEGRO_SAMPLE *sample = NULL;// add
    ALLEGRO_SAMPLE_INSTANCE *instance;// add
};

#endif // MAXDRUG_H_INCLUDED
