#include "Boxinggloves.h"
Boxinggloves::Boxinggloves(int x, int y)
{
    this->circle = new Circle(x, y, 50);
    boxinggloves_pos_x = x;
    boxinggloves_pos_y = y;
}

Boxinggloves::~Boxinggloves()
{
    delete circle;
    for(int i=0;i<3;i++)
    {
        al_destroy_bitmap(boxinggloves_img[i]);
    }
    boxinggloves_pos_x = -10;
    boxinggloves_pos_y = -10;
    al_destroy_sample_instance(instance);
    
    
}

void
Boxinggloves::boxinggloves_init(Player*p1_out,Player*p2_out,Player*p3_out,Player*p4_out)
{
    for(int i=0;i<3;i++)
    {
        char path[50];
        snprintf(path,sizeof(path), "./picture/boxinggloves/boxinggloves%d.png", i+1);
        //snprintf(path,sizeof(path), "./picture/character/move%d.png", i);
        boxinggloves_img[i] = al_load_bitmap(path);
    }
    //cross_timer = al_create_timer(1.0/60);
    //al_start_timer(cross_timer);
    anime = 0;
    anime_time = 20;
    p1 = p1_out;
    p2 = p2_out;
    p3 = p3_out;
    p4 = p4_out;
    sample = al_load_sample("./sound/boxinggloves.wav");
    instance = al_create_sample_instance(sample);
    
    printf("boxinggloves init success\n");
}

void
Boxinggloves::boxinggloves_update()
{
    anime++;
    anime %= anime_time;
    if(trigger()){
        printf("boxinggloves update item trigger\n");
        boxinggloves_pos_x = -500;
        boxinggloves_pos_y = -500;
        this->circle->x = boxinggloves_pos_x;
        this->circle->y = boxinggloves_pos_y;
    }
    else{
        printf("boxinggloves update item not trigger\n");
    }
}

void
Boxinggloves::Draw()
{
    printf("boxinggloves draw\n");
    switch (anime/7)
    {
        case 0:
            al_draw_bitmap(boxinggloves_img[0], boxinggloves_pos_x, boxinggloves_pos_y, 0);
            break;
        case 1:
            al_draw_bitmap(boxinggloves_img[1], boxinggloves_pos_x, boxinggloves_pos_y, 0);
            break;
        case 2:
            al_draw_bitmap(boxinggloves_img[2], boxinggloves_pos_x, boxinggloves_pos_y, 0);
            break;
    }
    printf("boxinggloves draw success\n");
}

bool
Boxinggloves::trigger()
{
    printf("boxinggloves trigger check\n");
    printf("(%d,%d)---p1 ",p1->getX(),p1->getY());
    printf("(%d,%d)---boxinggloves\n",this->getX(),this->getY());
    
    //this->circle;
    if (Circle::isOverlap(this->circle, p1->getCircle()))
    {
        p1_boxinggloves_trigger = true;
        
        al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
        al_set_sample_instance_gain(instance, 1);
        al_play_sample_instance(instance);
        
        printf("boxinggloves trigger check 1\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p2->getCircle()))
    {
        p2_boxinggloves_trigger = true;
        
        al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
        al_set_sample_instance_gain(instance, 1);
        al_play_sample_instance(instance);
        
        printf("boxinggloves trigger check 2\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p3->getCircle()))
    {
        p3_boxinggloves_trigger = true;
        
        al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
        al_set_sample_instance_gain(instance, 1);
        al_play_sample_instance(instance);
        
        printf("boxinggloves trigger check 3\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p4->getCircle()))
    {
        p4_boxinggloves_trigger = true;
        
        al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
        al_set_sample_instance_gain(instance, 1);
        al_play_sample_instance(instance);
        
        printf("boxinggloves trigger check 4\n");
        return true;
    }
    else
    {
        printf("boxinggloves trigger check none\n");
        return false;
    }
}
