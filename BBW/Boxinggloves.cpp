#include "Boxinggloves.h"
Boxinggloves::Boxinggloves(int x, int y)
{
    this->circle = new Circle(x, y, 70);
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
    
    
}

void
Boxinggloves::boxinggloves_init(Player*p1_out,Player*p2_out,Player*p3_out,Player*p4_out)
{
    for(int i=0;i<3;i++)
    {
        char path[50];
        //snprintf(path,sizeof(path), "./picture/cross/cross%d.png", i);
        snprintf(path,sizeof(path), "./picture/character/move%d.png", i);
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
    printf("boxinggloves init success\n");
}

void
Boxinggloves::boxinggloves_update()
{
    anime++;
    anime %= anime_time;
    if(trigger()){
        printf("boxinggloves update item trigger\n");
        boxinggloves_pos_x = -100;
        boxinggloves_pos_y = -100;
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
        printf("boxinggloves trigger check 1\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p2->getCircle()))
    {
        printf("boxinggloves trigger check 2\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p3->getCircle()))
    {
        printf("boxinggloves trigger check 3\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p4->getCircle()))
    {
        printf("boxinggloves trigger check 4\n");
        return true;
    }
    else
    {
        printf("boxinggloves trigger check none\n");
        return false;
    }
}
