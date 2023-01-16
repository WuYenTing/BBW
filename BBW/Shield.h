#ifndef SHIELD_H_INCLUDED
#define SHIELD_H_INCLUDED
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
class Shield : public Object
{
public:
    Shield(int x=0, int y=0);
    ~Shield();
    void Draw();
    void shield_init(Player*,Player*,Player*,Player*);
    void shield_update();
    bool trigger();
    int anime;
    int anime_time;
    int shield_pos_x;
    int shield_pos_y;
    int shield_start;
    int cd_time = 0;
    Player* p1;
    Player* p2;
    Player* p3;
    Player* p4;
    ALLEGRO_BITMAP* shield_img[3];
    ALLEGRO_TIMER* shield_timer = NULL;
    
    ALLEGRO_SAMPLE *sample = NULL;// add
    ALLEGRO_SAMPLE_INSTANCE *instance;// add
};
#endif // SHIELD_H_INCLUDED
