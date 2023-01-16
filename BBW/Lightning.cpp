#include "Lightning.h"
//minus life
Lightning::Lightning(int x,int y)
{
    this->circle = new Circle(x, y, 50);
    lightning_pos_x = x;
    lightning_pos_y = y;
}

Lightning::~Lightning()
{
    delete circle;
    for(int i=0;i<3;i++)
    {
        al_destroy_bitmap(lightning_img[i]);
    }
    lightning_pos_x = -10;
    lightning_pos_y = -10;
    al_destroy_sample_instance(instance);
    
    
}

void
Lightning::lightning_init(Player*p1_out,Player*p2_out,Player*p3_out,Player*p4_out)
{
    for(int i=0;i<3;i++)
    {
        char path[50];
        snprintf(path,sizeof(path), "./picture/lightning/lightning%d.png", i+1);
        //snprintf(path,sizeof(path), "./picture/character/move%d.png", i);
        lightning_img[i] = al_load_bitmap(path);
    }
    //cross_timer = al_create_timer(1.0/60);
    //al_start_timer(cross_timer);
    anime = 0;
    anime_time = 20;
    p1 = p1_out;
    p2 = p2_out;
    p3 = p3_out;
    p4 = p4_out;
    
    sample = al_load_sample("./sound/lighting.wav");
    instance = al_create_sample_instance(sample);
    
    printf("lightning init success\n");
}

void
Lightning::lightning_update()
{
    anime++;
    anime %= anime_time;
    if(trigger()){
        printf("lightning update item trigger\n");
        lightning_pos_x = -500;
        lightning_pos_y = -500;
        this->circle->x = lightning_pos_x;
        this->circle->y = lightning_pos_y;
    }
    else{
        printf("lightning update item not trigger\n");
        int t = al_get_time();
                switch (t%11){
                    case 0:
                        lightning_pos_x = 766;
                        lightning_pos_y = 450;
                        this->circle->x = lightning_pos_x;
                        this->circle->y = lightning_pos_y;
                        break;
                    case 1:
                        lightning_pos_x = 782;
                        lightning_pos_y = 550;
                        this->circle->x = lightning_pos_x;
                        this->circle->y = lightning_pos_y;
                        break;
                    case 2:
                        lightning_pos_x = 920;
                        lightning_pos_y = 452;
                        this->circle->x = lightning_pos_x;
                        this->circle->y = lightning_pos_y;
                        break;
                    case 3:
                        lightning_pos_x = 776;
                        lightning_pos_y = 546;
                        this->circle->x = lightning_pos_x;
                        this->circle->y = lightning_pos_y;
                        break;
                    case 4:
                        lightning_pos_x = 910;
                        lightning_pos_y = 650;
                        this->circle->x = lightning_pos_x;
                        this->circle->y = lightning_pos_y;
                        break;
                    case 5:
                        lightning_pos_x = 850;
                        lightning_pos_y = 634;
                        this->circle->x = lightning_pos_x;
                        this->circle->y = lightning_pos_y;
                        break;
                    case 6:
                        lightning_pos_x = 860;
                        lightning_pos_y = 1300;
                        this->circle->x = lightning_pos_x;
                        this->circle->y = lightning_pos_y;
                        break;
                    case 7:
                        lightning_pos_x = 1402;
                        lightning_pos_y = 754;
                        this->circle->x = lightning_pos_x;
                        this->circle->y = lightning_pos_y;
                        break;
                    case 8:
                        lightning_pos_x = 1536;
                        lightning_pos_y = 948;
                        this->circle->x = lightning_pos_x;
                        this->circle->y = lightning_pos_y;
                        break;
                    case 9:
                        lightning_pos_x = 1520;
                        lightning_pos_y = 1050;
                        this->circle->x = lightning_pos_x;
                        this->circle->y = lightning_pos_y;
                        break;
                    
                }
    }
}

void
Lightning::Draw()
{
    printf("lightning draw\n");
    switch (anime/7)
    {
        case 0:
            al_draw_bitmap(lightning_img[0], lightning_pos_x, lightning_pos_y, 0);
            break;
        case 1:
            al_draw_bitmap(lightning_img[1], lightning_pos_x, lightning_pos_y, 0);
            break;
        case 2:
            al_draw_bitmap(lightning_img[2], lightning_pos_x, lightning_pos_y, 0);
            break;
    }
    printf("lightning_img[i] draw success\n");
}

bool
Lightning::trigger()
{
    printf("lightning trigger check\n");
    printf("(%d,%d)---p1 ",p1->getX(),p1->getY());
    printf("(%d,%d)---lightning\n",this->getX(),this->getY());
    //this->circle;
    if (Circle::isOverlap(this->circle, p1->getCircle()))
    {
        if(!p1_boxinggloves_trigger){
            p1->life -= minus_life;
        }else if (p1_boxinggloves_trigger){
            p1_boxinggloves_trigger = false;
        }
        
        
        al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
        al_set_sample_instance_gain(instance, 0.1);
        al_play_sample_instance(instance);
        
        printf("lightning trigger check 1\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p2->getCircle()))
    {
        if(!p2_boxinggloves_trigger){
            p2->life -= minus_life;
        }else if (p2_boxinggloves_trigger){
            p2_boxinggloves_trigger = false;
        }
        
        al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
        al_set_sample_instance_gain(instance, 0.1);
        al_play_sample_instance(instance);
        
        printf("lightning trigger check 2\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p3->getCircle()))
    {
        if(!p3_boxinggloves_trigger){
            p3->life -= minus_life;
        }else if (p3_boxinggloves_trigger){
            p3_boxinggloves_trigger = false;
        }
        
        al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
        al_set_sample_instance_gain(instance, 0.1);
        al_play_sample_instance(instance);
        
        printf("lightning trigger check 3\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p4->getCircle()))
    {
        if(!p4_boxinggloves_trigger){
            p4->life -= minus_life;
        }else if (p4_boxinggloves_trigger){
            p4_boxinggloves_trigger = false;
        }
        
        al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
        al_set_sample_instance_gain(instance, 0.1);
        al_play_sample_instance(instance);
        
        printf("lightning trigger check 4\n");
        return true;
    }
    else
    {
        printf("lightning trigger check none\n");
        return false;
    }
}
