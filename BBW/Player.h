#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <vector>
#include "Object.h"
#include "Circle.h"
#include "Character.h"
#include "global.h"

class Player : public Object
{
public:
    Player(int = 0, int = 0);
    virtual ~Player();
    void Draw();    
    void player_init();
    void player_process();
    void player_update();
    void player_destroy();

private:
    /* data */
    int direction[4];
    int life;
    int speed;
    std::vector<ALLEGRO_BITMAP*> player_img;
};

#endif // PLAYER_H_INCLUDED
