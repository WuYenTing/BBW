#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include "global.h"
#include "Character.h"
#include "Item.h"
#include "Menu.h"
#include "Obstacle.h"
#include "Player.h"
#include "Scence.h"

#define GAME_INIT -1
#define GAME_SETTING 0
#define GAME_SELECT 1
#define GAME_BEGIN 2
#define GAME_CONTINUE 3
#define GAME_FAIL 4
#define GAME_TERMINATE 5
#define GAME_NEXT_LEVEL 6
#define GAME_EXIT 7
#define CLASSIC 8
#define CAPTURE 9
#define DEATHMATCH 10



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
    void mode_select();

    int game_run();
    int game_update();

    void show_err_msg(int msg);
    void game_destroy();

    // each drawing scene function
    void draw_running_map();

    // process of updated event
    int process_event();
    

    bool mouse_hover(int, int, int, int);
    ~Gamewindow();

public:
    bool initial = true;

private:
    /* data */
    ALLEGRO_BITMAP *icon;
    ALLEGRO_BITMAP *start_menu = NULL;
    ALLEGRO_BITMAP *map = NULL;
    

    ALLEGRO_DISPLAY* display = NULL;
    
    ALLEGRO_FONT *button = NULL;
    ALLEGRO_FONT *capture_button = NULL;
    ALLEGRO_FONT *deathmatch_button = NULL;
    
    
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    
    ALLEGRO_EVENT event;
    
    ALLEGRO_TIMER *timer = NULL;
    
    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *startSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *clearSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *failSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *background_sound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *click_sound = NULL;

    int select_mode = 0, c = 0;
    int mouse_x, mouse_y;
    int select_classic = -1, select_capture = -1, select_deathmatch = -1;
    bool mute = false;
 
};


#endif // MAINWINDOW_H_INCLUDED
