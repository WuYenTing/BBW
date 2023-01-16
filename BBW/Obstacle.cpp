#include "Obstacle.h"
Obstacle::Obstacle(int x, int y, int t)
{
    this->circle = new Circle(x, y, 50);
    pos_x = x;
    pos_y = y;
    type = t;
}

Obstacle::~Obstacle()
{
    delete circle;
    al_destroy_bitmap(obstacle_img[0]);
    pos_x = -10;
    pos_y = -10;
    //al_stop_timer(obstacle_timer);
    //al_destroy_timer(obstacle_timer);
}

void
Obstacle::obstacle_init(Player*p1_out,Player*p2_out,Player*p3_out,Player*p4_out)
{
    char path[50];
    //snprintf(path,sizeof(path), "./picture/obstacle/obstacle%d.png", i);
    snprintf(path,sizeof(path), "./picture/character/move%d.png", type);
    obstacle_img[0] = al_load_bitmap(path);
    //obstacle_timer = al_create_timer(1.0/60);
    //al_start_timer(obstacle_timer);
    p1=p1_out;
    p2=p2_out;
    p3=p3_out;
    p4=p4_out;
    printf("obstacle init success\n");
}

void
Obstacle::obstacle_update()
{
    if(trigger()){
        printf("obstacle update obstacle trigger\n");
    }
    else{
        printf("obstacle update obstacle not trigger\n");
    }
}

void
Obstacle::Draw()
{
    printf("obstacle draw\n");
    switch (type)
    {
        case 0:
            al_draw_bitmap(obstacle_img[0], pos_x, pos_y, 0); //box
            printf("obstacle draw sucess 0\n");
            break;
        case 1:
            al_draw_bitmap(obstacle_img[0], pos_x, pos_y, 0); //wall
            printf("obstacle draw sucess 1\n");
            break;
        case 2:
            al_draw_bitmap(obstacle_img[0], pos_x, pos_y, 0); //tree
            printf("obstacle draw sucess 2\n");
            break;
    }
}

bool
Obstacle::trigger()
{
    printf("trigger check\n");
    printf("(%d,%d)---p1 ",p1->getX(),p1->getY());
    printf("(%d,%d)---obstacle\n",this->getX(),this->getY());
    //this->circle;
    if (Circle::isOverlap(this->circle, p1->getCircle()))
    {
        printf("trigger check 1\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p2->getCircle()))
    {
        printf("trigger check 2\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p3->getCircle()))
    {
        printf("trigger check 3\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p4->getCircle()))
    {
        printf("trigger check 4\n");
        return true;
    }
    else
    {
        printf("trigger check none\n");
        return false;
    }
}

