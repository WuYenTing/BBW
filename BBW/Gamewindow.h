#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include "global.h"
#include "Character.h"
#include "Item.h"
#include "Menu.h"
#include "Obstacle.h"
#include "Player.h"
#include "Scence.h"
#include "Mode.h"
#include "Mode_capture.h"
#include "Mode_classic.h"
#include "Mode_deathmatch.h"

// clock rate
const float FPS = 60;

// total game mode
const int MODE = 3;

class Gamewindow
{
public:
    Gamewindow(/* args */);

    void game_init();
    void game_reset();
    void game_play();
    void game_begin();
    void game_draw();
    int mode_select();

    int game_run();
    void game_update();

    void show_err_msg(int msg);
    void game_destroy();

    // each drawing scene function
    //void draw_running_map();

    // process of updated event
    int process_event();
    

    bool mouse_hover(int, int, int, int);
    ~Gamewindow();

public:
    bool initial = true;

private:
    /* data */
    ALLEGRO_BITMAP *icon;
    
    ALLEGRO_DISPLAY* display = NULL;
    
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_EVENT event;
    
    ALLEGRO_TIMER *timer = NULL;
    
    Menu menu;
    

    int select_mode = 0, c = 0;
    int mouse_x, mouse_y;
    int select_classic = -1, select_capture = -1, select_deathmatch = -1;
    bool mute = false;
    bool draw = true;
    
};


#endif // MAINWINDOW_H_INCLUDED
