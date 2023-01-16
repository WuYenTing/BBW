#ifndef BOXINGGLOVES_H_INCLUDED
#define BOXINGGLOVES_H_INCLUDED
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
class Boxinggloves : public Object
{
public:
    Boxinggloves(int x=0, int y=0);
    ~Boxinggloves();
    void Draw();
    void boxinggloves_init(Player*,Player*,Player*,Player*);
    void boxinggloves_update();
    bool trigger();
    int anime;
    int anime_time;
    int boxinggloves_pos_x;
    int boxinggloves_pos_y;
    int boxinggloves_start;
    int cd_time = 0;
    Player* p1;
    Player* p2;
    Player* p3;
    Player* p4;
    ALLEGRO_BITMAP* boxinggloves_img[3];
    ALLEGRO_TIMER* boxinggloves_timer = NULL;
    ALLEGRO_SAMPLE *sample = NULL;// add
    ALLEGRO_SAMPLE_INSTANCE *instance;// add
};

#endif // BOXINGGLOVES_H_INCLUDED
