#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <time.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "algif.h"
//ALLEGRO_EVENT_QUEUE *event_queue = NULL;
//include c++ , algif and allegro5 lib in global

#define window_width 2000
#define window_height 1500

#define GAME_INIT -1
#define GAME_SETTING 0
#define GAME_SELECT 1
#define GAME_BEGIN 2
#define GAME_CONTINUE 3
#define GAME_FAIL 4
#define GAME_TERMINATE 5
#define GAME_NEXT_LEVEL 6
#define GAME_EXIT 7
#define CAPTURE 8
#define DEATHMATCH 9
#define PLAYER_1 11
#define PLAYER_2 12

extern bool next_window;
extern int window;
extern bool mode_next_window;
extern int mode_window;
extern bool esc;
extern int select_capture, select_deathmatch;
extern bool key_state[ALLEGRO_KEY_MAX];

extern bool p1_boxinggloves_trigger;
extern bool p2_boxinggloves_trigger;
extern bool p3_boxinggloves_trigger;
extern bool p4_boxinggloves_trigger;

extern bool p1_shield_trigger;
extern bool p2_shield_trigger;
extern bool p3_shield_trigger;
extern bool p4_shield_trigger;

extern int max_speed;
extern int min_speed;

extern int add_life;
extern int minus_life;

extern bool p1_attack;
extern int p1_attack_time;
extern int p1_x;
extern int p1_y;
extern int p2_x;
extern int p2_y;

//extern int p1_life;
//extern int p2_life;
extern char p1_life_string[101];
extern char p2_life_string[101];
extern char time_string[181];

extern double ts;
extern double elapsed_time;
extern int game_time;
