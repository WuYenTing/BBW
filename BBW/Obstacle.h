#ifndef OBSTACLE_H_INCLUDED
#define OBSTACLE_H_INCLUDED

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "Object.h"
#include "global.h"
#include "Player.h"
class Obstacle : public Object
{
public:
    Obstacle(int x= 0, int y= 0 ,int t=0);
    ~Obstacle();
    void Draw();
    void obstacle_init(Player*,Player*,Player*,Player*);
    void obstacle_update();
    bool trigger();
    int anime;
    int anime_time;
    int pos_x;
    int pos_y;
    int Obstacle_start;
    int type; //tree,box,wall
    Player *p1;
    Player *p2;
    Player *p3;
    Player *p4;
    ALLEGRO_BITMAP* obstacle_img[3];
    ALLEGRO_TIMER* obstacle_timer = NULL;
};

#endif // OBSTACLE_H_INCLUDED

