#include "Scence.h"

class Menu : public Scence
{
public:
    Menu(){};
    ~Menu();
    void init();
    int process(ALLEGRO_EVENT event);
    void draw();

    
private:
    ALLEGRO_BITMAP *menu = NULL;
    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *background_sound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *click_sound = NULL;
    
};
