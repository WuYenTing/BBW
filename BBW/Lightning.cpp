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
    
    
}

void
Lightning::lightning_init(Player*p1_out,Player*p2_out,Player*p3_out,Player*p4_out)
{
    for(int i=0;i<3;i++)
    {
        char path[50];
        //snprintf(path,sizeof(path), "./picture/cross/cross%d.png", i);
        snprintf(path,sizeof(path), "./picture/character/move%d.png", i);
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
    printf("lightning init success\n");
}

void
Lightning::lightning_update()
{
    anime++;
    anime %= anime_time;
    if(trigger()){
        printf("lightning update item trigger\n");
        lightning_pos_x = -100;
        lightning_pos_y = -100;
    }
    else{
        printf("lightning update item not trigger\n");
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
        p1->life -= minus_life;
        printf("lightning trigger check 1\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p2->getCircle()))
    {
        p2->life -= minus_life;
        printf("lightning trigger check 2\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p3->getCircle()))
    {
        p3->life -= minus_life;
        printf("lightning trigger check 3\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p4->getCircle()))
    {
        p4->life -= minus_life;
        printf("lightning trigger check 4\n");
        return true;
    }
    else
    {
        printf("lightning trigger check none\n");
        return false;
    }
}
