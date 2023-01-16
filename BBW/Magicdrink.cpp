#include "Magicdrink.h"
//add life
Magicdrink::Magicdrink(int x, int y)
{
    this->circle = new Circle(x, y, 50);
    magicdrink_pos_x = x;
    magicdrink_pos_y = y;
}

Magicdrink::~Magicdrink()
{
    delete circle;
    for(int i=0;i<3;i++)
    {
        al_destroy_bitmap(magicdrink_img[i]);
    }
    magicdrink_pos_x = -10;
    magicdrink_pos_y = -10;
    al_destroy_sample_instance(instance);
    //al_stop_timer(cross_timer);
    //al_destroy_timer(cross_timer);
}

void
Magicdrink::magicdrink_init(Player*p1_out,Player*p2_out,Player*p3_out,Player*p4_out)
{
    for(int i=0;i<3;i++)
    {
        char path[50];
        snprintf(path,sizeof(path), "./picture/magicdrink/magicdrink%d.png", i+1);
        //snprintf(path,sizeof(path), "./picture/character/move%d.png", i);
        magicdrink_img[i] = al_load_bitmap(path);
    }
    //cross_timer = al_create_timer(1.0/60);
    //al_start_timer(cross_timer);
    anime = 0;
    anime_time = 20;
    p1 = p1_out;
    p2 = p2_out;
    p3 = p3_out;
    p4 = p4_out;
    
    sample = al_load_sample("./sound/magicdrink.wav");
    instance = al_create_sample_instance(sample);
    
    printf("magicdrink init success\n");
}

void
Magicdrink::magicdrink_update()
{
    anime++;
    anime %= anime_time;
    if(trigger()){
        printf("magicdrink update item trigger\n");
        magicdrink_pos_x = -500;
        magicdrink_pos_y = -500;
        this->circle->x = magicdrink_pos_x;
        this->circle->y = magicdrink_pos_y;
    }
    else{
        printf("magicdrink update item not trigger\n");
    }
}

void
Magicdrink::Draw()
{
    printf("magicdrink draw\n");
    switch (anime/7)
    {
        case 0:
            al_draw_bitmap(magicdrink_img[0], magicdrink_pos_x, magicdrink_pos_y, 0);
            break;
        case 1:
            al_draw_bitmap(magicdrink_img[1], magicdrink_pos_x, magicdrink_pos_y, 0);
            break;
        case 2:
            al_draw_bitmap(magicdrink_img[2], magicdrink_pos_x, magicdrink_pos_y, 0);
            break;
    }
    printf("magicdrink draw success\n");
}


bool
Magicdrink::trigger()
{
    printf("magicdrink trigger check\n");
    printf("(%d,%d)---p1 ",p1->getX(),p1->getY());
    printf("(%d,%d)---magicdrink\n",this->getX(),this->getY());
    //this->circle;
    if (Circle::isOverlap(this->circle, p1->getCircle()))
    {
        if(p1->life <= 100 - add_life)
            p1->life += add_life;
        else p1->life = 100;
        
        al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
        al_set_sample_instance_gain(instance, 0.8);
        al_play_sample_instance(instance);
        
        printf("magicdrink trigger check 1\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p2->getCircle()))
    {
        if(p2->life <= 100 - add_life)
            p2->life += add_life;
        else p2->life = 100;
        
        al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
        al_set_sample_instance_gain(instance, 0.8);
        al_play_sample_instance(instance);
        
        printf("magicdrink trigger check 2\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p3->getCircle()))
    {
        if(p3->life <= 100 - add_life)
            p3->life += add_life;
        else p3->life = 100;
        
        al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
        al_set_sample_instance_gain(instance, 0.8);
        al_play_sample_instance(instance);
        
        printf("magicdrink trigger check 3\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p4->getCircle()))
    {
        if(p4->life <= 100 - add_life)
            p4->life += add_life;
        else p4->life = 100;
        
        al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
        al_set_sample_instance_gain(instance, 0.8);
        al_play_sample_instance(instance);
        
        printf("magicdrink trigger check 4\n");
        return true;
    }
    else
    {
        printf("magicdrink trigger check none\n");
        return false;
    }
}
