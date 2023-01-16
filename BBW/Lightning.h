#ifndef LIGHTNING_H_INCLUDED
#define LIGHTNING_H_INCLUDED
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
class Lightning : public Object
{
public:
    Lightning(int x=0, int y=0);
    ~Lightning();
    void Draw();
    void lightning_init(Player*,Player*,Player*,Player*);
    void lightning_update();
    bool trigger();
    int anime;
    int anime_time;
    int lightning_pos_x;
    int lightning_pos_y;
    int lightninh_start;
    int cd_time = 0;
    Player* p1;
    Player* p2;
    Player* p3;
    Player* p4;
    ALLEGRO_BITMAP* lightning_img[3];
    ALLEGRO_TIMER* lightning_timer = NULL;
    ALLEGRO_SAMPLE *sample = NULL;// add
    ALLEGRO_SAMPLE_INSTANCE *instance;// add
};

#endif // LIGHTNING_H_INCLUDED
