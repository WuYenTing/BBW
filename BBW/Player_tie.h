#include "Scence.h"

class Player_tie : public Scence
{
public:
    Player_tie(){};
    ~Player_tie(){};
    virtual void init();
    virtual int process(ALLEGRO_EVENT event);
    virtual void draw();
    virtual void destroy();
    
private:
    ALLEGRO_BITMAP *picture = NULL;
    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *background_sound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *click_sound = NULL;
    
};

