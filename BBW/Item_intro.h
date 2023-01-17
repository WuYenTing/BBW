#include "Scence.h"

class Item_intro : public Scence
{
public:
    Item_intro(){};
    ~Item_intro(){};
    virtual void init();
    virtual int process(ALLEGRO_EVENT event);
    virtual void draw();
    virtual void destroy();
    
private:
    ALLEGRO_BITMAP *picture = NULL;
    ALLEGRO_SAMPLE *sample1 = NULL;
    ALLEGRO_SAMPLE *sample2 = NULL;
    ALLEGRO_SAMPLE_INSTANCE *background_sound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *click_sound = NULL;
    
};
