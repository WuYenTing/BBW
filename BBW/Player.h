#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "Object.h"

class Player : public Object
{
public:
    Player(int = 0, int = 0);
    ~Player();
    void Draw();    
    void player_init();
    void player_process();
    void player_update();
    void player_destroy();

private:
    /* data */
    enum dir {FRONT, BACK, LEFT,RIGHT};
    dir player_dir;
    enum state {STOP, MOVE, CHANGE_DIR};
    state player_state;
    int life;
    int speed;
    int pos_x,pos_y;
    int width,height;
    int anime;
    ALLEGRO_BITMAP *player_img[12];
};

#endif // PLAYER_H_INCLUDED
