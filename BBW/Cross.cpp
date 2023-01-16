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
    //al_stop_timer(cross_timer);
    //al_destroy_timer(cross_timer);
}

void
Cross::cross_init(Player*p1_out,Player*p2_out,Player*p3_out,Player*p4_out)
{
    for(int i=0;i<3;i++)
    {
        char path[50];
        //snprintf(path,sizeof(path), "./picture/cross/cross%d.png", i);
        snprintf(path,sizeof(path), "./picture/character/move%d.png", i);
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
    printf("cross init success\n");
}

void
Cross::cross_update()
{
    anime++;
    anime %= anime_time;
    if(trigger()){
        printf("cross update item trigger\n");
        //cross_pos_x = -100;
        //cross_pos_y = -100;
    }
    else{
        printf("cross update item not trigger\n");
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
        p1->speed = min_speed;
        printf("cross trigger check 1\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p2->getCircle()))
    {
        p2->speed = min_speed;
        printf("cross trigger check 2\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p3->getCircle()))
    {
        p3->speed = min_speed;
        printf("cross trigger check 3\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p4->getCircle()))
    {
        p4->speed = min_speed;
        printf("cross trigger check 4\n");
        return true;
    }
    else
    {
        printf("cross trigger check none\n");
        return false;
    }
}
