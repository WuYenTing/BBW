#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include "Object.h"
#include "global.h"
//#include "Gamewindow.h"
class Player : public Object
{
public:
    Player(int x = 0, int y = 0);
    ~Player();
    void Draw();
    void player_init(char up,char down, char left, char right, char attack, int type);
    void player_process(ALLEGRO_EVENT,ALLEGRO_TIMER*);
    void player_update();
    void player_destroy();
    void create_waterbomb(int ,int );
    
    int pos_x,pos_y;
    float life;
    int speed;
    int anime ;
    int anime_time;
    int type;
    //Waterbomb* create_waterbomb(int x=0,int y=0);
    //Waterbomb* player_waterbomb = NULL;
    void create_waterbomb();
    void Draw_waterbomb();
    void waterbomb_init();
    void waterbomb_update(int,int);
    bool waterbomb_trigger(int,int);
    int waterbomb_pos_x;
    int waterbomb_pos_y;
    int waterbomb_start;
    int waterbomb_center_x;
    int waterbomb_center_y;
    int range = 100 ;//
    int cd_time;
    int explore;
    int set_time;
private:
    /* data */
    enum dir {FRONT, BACK, LEFT, RIGHT};
    dir player_dir;
    enum state {STOP, MOVE, CHANGE_DIR};
    state player_state;
    int width,height;
    
    ALLEGRO_BITMAP *player_img[12];
    ALLEGRO_BITMAP *waterbomb_img[4];
    ALLEGRO_EVENT player_event;
    ALLEGRO_TIMER *player_timer = NULL;
    int OPERATION_UP;
    int OPERATION_DOWN;
    int OPERATION_LEFT;
    int OPERATION_RIGHT;
    int OPERATION_ATTACK;
};

#endif // PLAYER_H_INCLUDED
