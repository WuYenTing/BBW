#include "Scence.h"

class Capture_map : public Scence
{
public:
    Capture_map(){};
    ~Capture_map(){};
    virtual void init();
    //virtual int process(ALLEGRO_EVENT event);
    virtual void draw();
    virtual void destroy();
    
private:
    ALLEGRO_BITMAP *picture = NULL;
    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *background_sound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *click_sound = NULL;
    
    ALLEGRO_FONT *p1_life= NULL;         //add
    ALLEGRO_FONT *p2_life=NULL;
    ALLEGRO_FONT *g_time= NULL;          //add
    
};

