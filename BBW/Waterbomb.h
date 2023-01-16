/*#ifndef WATERBOMB_H_INCLUDED
#define WATERBOMB_H_INCLUDED
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
class Waterbomb : public Object
{
public:
    Waterbomb(int x=0, int y=0);
    ~Waterbomb();
    void Draw();
    void waterbomb_init(Player*,Player*,Player*,Player*);
    void waterbomb_update();
    bool trigger();
    int anime;
    int anime_time;
    int waterbomb_pos_x;
    int waterbomb_pos_y;
    int waterbomb_start;
    int cd_time;
    int explore;
    int set_time;
    Player* p1;
    Player* p2;
    Player* p3;
    Player* p4;
    ALLEGRO_BITMAP* waterbomb_img[3];
    ALLEGRO_TIMER* waterbomb_timer = NULL;
};

#endif // WATERBOMB_H_INCLUDED
*/
