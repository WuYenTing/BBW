#ifndef SCENCE_H_INCLUDED
#define SCENCE_H_INCLUDED
#include "global.h"

class Scence
{
public:
    Scence(){}
    ~Scence(){}
    virtual void init() = 0;
    virtual int process(ALLEGRO_EVENT event) = 0;
    virtual void draw() = 0;
};

#endif //SCENCE_H_INCLUDED
