#include "Scence.h"

class Menu : public Scence
{
public:
    Menu(){};
    ~Menu(){};
    virtual void init();
    virtual int process(ALLEGRO_EVENT event);
    virtual void draw();
    virtual void destroy();
    
private:
    ALLEGRO_BITMAP *menu = NULL;
    ALLEGRO_SAMPLE *sample1 = NULL;
    ALLEGRO_SAMPLE *sample2 = NULL;
    ALLEGRO_SAMPLE_INSTANCE *background_sound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *click_sound = NULL;
    
};
