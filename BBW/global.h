#include <stdio.h>
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
#define CLASSIC 8
#define CAPTURE 9
#define DEATHMATCH 10
#define PLAYER_1 11
#define PLAYER_2 12

extern bool next_window;
extern int window;
extern bool mode_next_window;
extern int mode_window;
extern bool esc;
extern int select_classic, select_capture, select_deathmatch;

