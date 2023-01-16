#ifndef SCENCE_H_INCLUDED
#define SCENCE_H_INCLUDED
#include "global.h"
#define MENU 0
#define SELECT_CHARATER 1
#define CAPTURE_MAP 2
#define CLASSIC_MAP 3
#define DEATHMATCH_MAP 4
#define WIN 5
#define LOSE 6
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
