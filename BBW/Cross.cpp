#include "Cross.h"
Cross::Cross(int x, int y)
{
    this->circle = new Circle(x, y, 50);
    cross_pos_x = x;
    cross_pos_y = y;
}
 
Cross::~Cross()
{
    delete circle;
    for(int i=0;i<3;i++)
    {
        al_destroy_bitmap(cross_img[i]);
    }
    cross_pos_x = -10;
    cross_pos_y = -10;
    al_destroy_sample_instance(instance);
    //al_stop_timer(cross_timer);
    //al_destroy_timer(cross_timer);
}

void
Cross::cross_init(Player*p1_out,Player*p2_out,Player*p3_out,Player*p4_out)
{
    for(int i=0;i<3;i++)
    {
        char path[50];
        snprintf(path,sizeof(path), "./picture/cross/cross%d.png", i+1);
        //snprintf(path,sizeof(path), "./picture/character/move%d.png", i);
        cross_img[i] = al_load_bitmap(path);
    }
    //cross_timer = al_create_timer(1.0/60);
    //al_start_timer(cross_timer);
    anime = 0;
    anime_time = 20;
    p1 = p1_out;
    p2 = p2_out;
    p3 = p3_out;
    p4 = p4_out;
    sample = al_load_sample("./sound/cross.wav");
    instance = al_create_sample_instance(sample);
    printf("cross init success\n");
}

void
Cross::cross_update()
{
    anime++;
    anime %= anime_time;
    if(trigger()){
        printf("cross update item trigger\n");
        cross_pos_x = -500;
        cross_pos_y = -500;
        this->circle->x = cross_pos_x;
        this->circle->y = cross_pos_y;
    }
    else{
        printf("cross update item not trigger\n");
        int t = al_get_time();
                switch (t%11){
                    case 0:
                        cross_pos_x = 140;
                        cross_pos_y = 550;
                        this->circle->x = cross_pos_x;
                        this->circle->y = cross_pos_y;
                        break;
                    case 1:
                        cross_pos_x = 214;
                        cross_pos_y = 650;
                        this->circle->x = cross_pos_x;
                        this->circle->y = cross_pos_y;
                        break;
                    case 2:
                        cross_pos_x = 840;
                        cross_pos_y = 348;
                        this->circle->x = cross_pos_x;
                        this->circle->y = cross_pos_y;
                        break;
                    case 3:
                        cross_pos_x = 1268;
                        cross_pos_y = 450;
                        this->circle->x = cross_pos_x;
                        this->circle->y = cross_pos_y;
                        break;
                    case 4:
                        cross_pos_x = 1466;
                        cross_pos_y = 644;
                        this->circle->x = cross_pos_x;
                        this->circle->y = cross_pos_y;
                        break;
                    case 5:
                        cross_pos_x = 1470;
                        cross_pos_y = 634;
                        this->circle->x = cross_pos_x;
                        this->circle->y = cross_pos_y;
                        break;
                    case 6:
                        cross_pos_x = 950;
                        cross_pos_y = 1300;
                        this->circle->x = cross_pos_x;
                        this->circle->y = cross_pos_y;
                        break;
                    case 7:
                        cross_pos_x = 1420;
                        cross_pos_y = 950;
                        this->circle->x = cross_pos_x;
                        this->circle->y = cross_pos_y;
                        break;
                    case 8:
                        cross_pos_x = 1214;
                        cross_pos_y = 1122;
                        this->circle->x = cross_pos_x;
                        this->circle->y = cross_pos_y;
                        break;
                    case 9:
                        cross_pos_x = 352;
                        cross_pos_y = 1196;
                        this->circle->x = cross_pos_x;
                        this->circle->y = cross_pos_y;
                        break;
                    
                }
    }
}

void
Cross::Draw()
{
    printf("cross draw\n");
    switch (anime/7)
    {
        case 0:
            al_draw_bitmap(cross_img[0], cross_pos_x, cross_pos_y, 0);
            break;
        case 1:
            al_draw_bitmap(cross_img[1], cross_pos_x, cross_pos_y, 0);
            break;
        case 2:
            al_draw_bitmap(cross_img[2], cross_pos_x, cross_pos_y, 0);
            break;
    }
    printf("cross draw success\n");
}

bool
Cross::trigger()
{
    printf("cross trigger check\n");
    printf("(%d,%d)---p1 ",p1->getX(),p1->getY());
    printf("(%d,%d)---cross\n",this->getX(),this->getY());
    //this->circle;
    if (Circle::isOverlap(this->circle, p1->getCircle()))
    {
        if(!p1_boxinggloves_trigger){
            p1->speed = min_speed;
        }else if(p1_boxinggloves_trigger){
            p1_boxinggloves_trigger = false;
        }
        
        al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
        al_set_sample_instance_gain(instance, 1);
        al_play_sample_instance(instance);
        
        printf("cross trigger check 1\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p2->getCircle()))
    {
        if(!p2_boxinggloves_trigger){
            p2->speed = min_speed;
        }else if(p2_boxinggloves_trigger){
            p2_boxinggloves_trigger = false;
        }
        
        al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
        al_set_sample_instance_gain(instance, 1);
        al_play_sample_instance(instance);
        
        printf("cross trigger check 2\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p3->getCircle()))
    {
        if(!p3_boxinggloves_trigger){
            p3->speed = min_speed;
        }else if(p3_boxinggloves_trigger){
            p3_boxinggloves_trigger = false;
        }
        
        al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
        al_set_sample_instance_gain(instance, 1);
        al_play_sample_instance(instance);
        
        printf("cross trigger check 3\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p4->getCircle()))
    {
        if(!p4_boxinggloves_trigger){
            p4->speed = min_speed;
        }else if(p4_boxinggloves_trigger){
            p4_boxinggloves_trigger = false;
        }
        
        al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
        al_set_sample_instance_gain(instance, 1);
        al_play_sample_instance(instance);
        
        printf("cross trigger check 4\n");
        return true;
    }
    else
    {
        printf("cross trigger check none\n");
        return false;
    }
}
