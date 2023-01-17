#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include "global.h"
#include "Character.h"
#include "Item.h"
#include "Boxinggloves.h"
#include "Cross.h"
#include "Magicdrink.h"
#include "Maxdrug.h"
#include "Lightning.h"
#include "Shield.h"
#include "Waterbomb.h"

#include "Obstacle.h"
#include "Player.h"
#include "Scence.h"
#include "Menu.h"
#include "Item_intro.h"
#include "Select_Character.h"
#include "Capture_map.h"
//#include "Deathmatch_map.h"
#include "Player1_win.h"
#include "Player2_win.h"
#include "Player_tie.h"
//#include "Mode.h"
//#include "Mode_capture.h"
//#include "Mode_classic.h"
//#include "Mode_deathmatch.h"

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
    int game_run();

    //int game_run();
    void game_update();

    void show_err_msg(int msg);
    void game_destroy();

    // each drawing scene function
    //void draw_running_map();

    // process of updated event
    int process_event();
    

    bool mouse_hover(int, int, int, int);
    ~Gamewindow();
    Player* create_player(int ,int);
    Player* p1 = create_player(136,153);
    Player* p2 = create_player(1680,156);
    Player* p3 = create_player(-101,-101);
    Player* p4 = create_player(-101,-101);
    Boxinggloves* create_boxinggloves();
    Boxinggloves* bx = create_boxinggloves();
    Cross* create_cross();
    Cross* cr = create_cross();
    Magicdrink* create_magicdrink();
    Magicdrink* mk = create_magicdrink();
    Maxdrug* create_maxdrug();
    Maxdrug* mg = create_maxdrug();
    Lightning* create_lightning();
    Lightning* li = create_lightning();
    Shield* create_shield();
    Shield* sh = create_shield();
    Item* create_item();
    //Item* it = create_item();
    Obstacle* create_obstacle(int x=0,int y=0,int t=0);
    //Obstacle* ob = create_obstacle(1200,1200,2);
    std::vector<Obstacle*> wallset;
    void create_wall();
    char W = 'W';
    char S = 'S';
    char A = 'A';
    char D = 'D';
    char X = 'X';

    char I = 'I';
    char K = 'K';
    char J = 'J';
    char L = 'L';
    char M = 'M';
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
    Item_intro item_intro;
    Select_Character select_character;
    Capture_map capture_map;
    //Deathmatch_map deathmatch_map;
    Player1_win player1_win;
    Player2_win player2_win;
    Player_tie player_tie;
    
    int select_mode = 0, c = 0;
    int mouse_x, mouse_y;
    bool mute = false;
    bool draw = true;
    
};


#endif // MAINWINDOW_H_INCLUDED
