#ifndef SCENCE_H_INCLUDED
#define SCENCE_H_INCLUDED
#include "global.h"
#define MENU 0
#define ITEM_INTRO 1
#define SELECT_CHARATER 2
#define CAPTURE_MAP 3
#define DEATHMATCH_MAP 4
#define PLAYER1_WIN 5
#define PLAYER2_WIN 6
#define PLAYER_TIE 7
class Scence
{
public:
    Scence(){}
    ~Scence(){}
    virtual void init() = 0;
    int process(ALLEGRO_EVENT event);
    virtual void draw() = 0;
    virtual void destroy() = 0;
};

#endif //SCENCE_H_INCLUDED
