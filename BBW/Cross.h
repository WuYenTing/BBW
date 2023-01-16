#ifndef CROSSS_H_INCLUDED
#define CROSSS_H_INCLUDED
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
class Cross : public Object
{
public:
    Cross(int x=0, int y=0);
    ~Cross();
    void Draw();
    void cross_init(Player*,Player*,Player*,Player*);
    void cross_update();
    bool trigger();
    int anime;
    int anime_time;
    int cross_pos_x;
    int cross_pos_y;
    int cross_start;
    int cd_time = 0;
    Player* p1;
    Player* p2;
    Player* p3;
    Player* p4;
    ALLEGRO_BITMAP* cross_img[3];
    ALLEGRO_TIMER* cross_timer = NULL;
    ALLEGRO_SAMPLE *sample = NULL;// add
    ALLEGRO_SAMPLE_INSTANCE *instance;// add
};

#endif // CROSSS_H_INCLUDED
