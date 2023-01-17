#include "global.h"

bool next_window = false;
int window = 0;
bool mode_next_window = false;
int mode_window = 0;
bool esc = false;
int select_capture = -1, select_deathmatch = -1;
bool key_state[ALLEGRO_KEY_MAX] = {false};

bool p1_boxinggloves_trigger = false;
bool p2_boxinggloves_trigger = false;
bool p3_boxinggloves_trigger = false;
bool p4_boxinggloves_trigger = false;

bool p1_shield_trigger = false;
bool p2_shield_trigger = false;
bool p3_shield_trigger = false;
bool p4_shield_trigger = false;


int max_speed = 8;
int min_speed = -2;

int add_life = 10;
float minus_life = 0.2;

bool p1_attack = false;
int p1_attack_time = 0;

double ts = 0;
double elapsed_time = 0;
int game_time = 0;

//int p1_life = 100;
//int p2_life = 100;

char p1_life_string[101] = {'\0'};
char p2_life_string[101] = {'\0'};
char time_string[181] = {'\0'};

