#include "Maxdrug.h"
//max speed
Maxdrug::Maxdrug(int x, int y)
{
    this->circle = new Circle(x, y, 70);
    maxdrug_pos_x = x;
    maxdrug_pos_y = y;
}
Maxdrug::~Maxdrug()
{
    delete circle;
    for(int i=0;i<3;i++)
    {
        al_destroy_bitmap(maxdrug_img[i]);
    }
    maxdrug_pos_x = -10;
    maxdrug_pos_y = -10;
    
    
}
void
Maxdrug::maxdrug_init(Player*p1_out,Player*p2_out,Player*p3_out,Player*p4_out)
{
    for(int i=0;i<3;i++)
    {
        char path[50];
        //snprintf(path,sizeof(path), "./picture/cross/cross%d.png", i);
        snprintf(path,sizeof(path), "./picture/character/move%d.png", i);
        maxdrug_img[i] = al_load_bitmap(path);
    }
    //cross_timer = al_create_timer(1.0/60);
    //al_start_timer(cross_timer);
    anime = 0;
    anime_time = 20;
    p1 = p1_out;
    p2 = p2_out;
    p3 = p3_out;
    p4 = p4_out;
    printf("maxdrug init success\n");
}
void
Maxdrug::maxdrug_update()
{
    anime++;
    anime %= anime_time;
    if(trigger()){
        printf("maxdrug update item trigger\n");
        maxdrug_pos_x = -100;
        maxdrug_pos_y = -100;
    }
    else{
        printf("maxdrug update item not trigger\n");
    }
}
void
Maxdrug::Draw()
{
    printf("maxdrug draw\n");
    switch (anime/7)
    {
        case 0:
            al_draw_bitmap(maxdrug_img[0], maxdrug_pos_x, maxdrug_pos_y, 0);
            break;
        case 1:
            al_draw_bitmap(maxdrug_img[1], maxdrug_pos_x, maxdrug_pos_y, 0);
            break;
        case 2:
            al_draw_bitmap(maxdrug_img[2], maxdrug_pos_x, maxdrug_pos_y, 0);
            break;
    }
    printf("maxdrug draw success\n");
}
bool
Maxdrug::trigger()
{
    printf("maxdrug trigger check\n");
    printf("(%d,%d)---p1 ",p1->getX(),p1->getY());
    printf("(%d,%d)---maxdrug\n",this->getX(),this->getY());
    //this->circle;
    if (Circle::isOverlap(this->circle, p1->getCircle()))
    {
        p1->speed = max_speed;
        printf("maxdrug trigger check 1\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p2->getCircle()))
    {
        p2->speed = max_speed;
        printf("maxdrug trigger check 2\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p3->getCircle()))
    {
        p3->speed = max_speed;
        printf("maxdrug trigger check 3\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p4->getCircle()))
    {
        p4->speed = max_speed;
        printf("maxdrug trigger check 4\n");
        return true;
    }
    else
    {
        printf("maxdrug trigger check none\n");
        return false;
    }
}
