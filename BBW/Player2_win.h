#include "Scence.h"

class Player2_win : public Scence
{
public:
    Player2_win(){};
    ~Player2_win(){};
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

