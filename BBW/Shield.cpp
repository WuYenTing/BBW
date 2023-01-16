#include "Shield.h"
Shield::Shield(int x, int y)
{
    this->circle = new Circle(x, y, 50);
    shield_pos_x = x;
    shield_pos_y = y;
}

Shield::~Shield()
{
    delete circle;
    for(int i=0;i<3;i++)
    {
        al_destroy_bitmap(shield_img[i]);
    }
    shield_pos_x = -10;
    shield_pos_y = -10;
    
    
}

void
Shield::shield_init(Player*p1_out,Player*p2_out,Player*p3_out,Player*p4_out)
{
    for(int i=0;i<3;i++)
    {
        char path[50];
        //snprintf(path,sizeof(path), "./picture/cross/cross%d.png", i);
        snprintf(path,sizeof(path), "./picture/character/move%d.png", i);
        shield_img[i] = al_load_bitmap(path);
    }
    //cross_timer = al_create_timer(1.0/60);
    //al_start_timer(cross_timer);
    anime = 0;
    anime_time = 20;
    p1 = p1_out;
    p2 = p2_out;
    p3 = p3_out;
    p4 = p4_out;
    printf("shield init success\n");
}

void
Shield::shield_update()
{
    anime++;
    anime %= anime_time;
    if(trigger()){
        printf("shield update item trigger\n");
        shield_pos_x = -100;
        shield_pos_y = -100;
    }
    else{
        printf("shield update item not trigger\n");
    }
}

void
Shield::Draw()
{
    printf("shield draw\n");
    switch (anime/7)
    {
        case 0:
            al_draw_bitmap(shield_img[0], shield_pos_x, shield_pos_y, 0);
            break;
        case 1:
            al_draw_bitmap(shield_img[1], shield_pos_x, shield_pos_y, 0);
            break;
        case 2:
            al_draw_bitmap(shield_img[2], shield_pos_x, shield_pos_y, 0);
            break;
    }
    printf("shield draw success\n");
}

bool
Shield::trigger()
{
    printf("shield trigger check\n");
    printf("(%d,%d)---p1 ",p1->getX(),p1->getY());
    printf("(%d,%d)---shield\n",this->getX(),this->getY());
    //this->circle;
    if (Circle::isOverlap(this->circle, p1->getCircle()))
    {
        printf("v trigger check 1\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p2->getCircle()))
    {
        printf("v trigger check 2\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p3->getCircle()))
    {
        printf("shield trigger check 3\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p4->getCircle()))
    {
        printf("shield trigger check 4\n");
        return true;
    }
    else
    {
        printf("shield trigger check none\n");
        return false;
    }
}
