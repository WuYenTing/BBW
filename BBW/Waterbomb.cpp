/*#include "Waterbomb.h"
Waterbomb::Waterbomb(int x, int y)
{
    this->circle = new Circle(x, y, 70);
    waterbomb_pos_x = x;
    waterbomb_pos_y = y;
}

Waterbomb::~Waterbomb()
{
    delete circle;
    for(int i=0;i<3;i++)
    {
        al_destroy_bitmap(waterbomb_img[i]);
    }
    waterbomb_pos_x = -10;
    waterbomb_pos_y = -10;
    
    
}

void
Waterbomb::waterbomb_init(Player*p1_out,Player*p2_out,Player*p3_out,Player*p4_out)
{
    for(int i=0;i<3;i++)
    {
        char path[50];
        //snprintf(path,sizeof(path), "./picture/cross/cross%d.png", i);
        snprintf(path,sizeof(path), "./picture/character/move%d.png", i);
        waterbomb_img[i] = al_load_bitmap(path);
    }
    //cross_timer = al_create_timer(1.0/60);
    //al_start_timer(cross_timer);
    anime = 0;
    anime_time = 20;
    p1 = p1_out;
    p2 = p2_out;
    p3 = p3_out;
    p4 = p4_out;
    printf("waterbomb init success\n");
}

void
Waterbomb::waterbomb_update()
{
    anime++;
    anime %= anime_time;
    if(trigger()){
        printf("waterbomb update item trigger\n");
        waterbomb_pos_x = -100;
        waterbomb_pos_y = -100;
    }
    else{
        printf("waterbomb update item not trigger\n");
    }
}

void
Waterbomb::Draw()
{
    printf("waterbomb draw\n");
    switch (anime/7)
    {
        case 0:
            al_draw_bitmap(waterbomb_img[0], waterbomb_pos_x, waterbomb_pos_y, 0);
            break;
        case 1:
            al_draw_bitmap(waterbomb_img[1], waterbomb_pos_x, waterbomb_pos_y, 0);
            break;
        case 2:
            al_draw_bitmap(waterbomb_img[2], waterbomb_pos_x, waterbomb_pos_y, 0);
            break;
    }
    printf("waterbomb draw success\n");
}

bool
Waterbomb::trigger()
{
    printf("waterbomb trigger check\n");
    printf("(%d,%d)---p1 ",p1->getX(),p1->getY());
    printf("(%d,%d)---waterbomb\n",this->getX(),this->getY());
    //this->circle;
    if (Circle::isOverlap(this->circle, p1->getCircle()))
    {
        printf("waterbomb trigger check 1\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p2->getCircle()))
    {
        printf("waterbomb trigger check 2\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p3->getCircle()))
    {
        printf("waterbomb trigger check 3\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p4->getCircle()))
    {
        printf("waterbomb trigger check 4\n");
        return true;
    }
    else
    {
        printf("waterbomb trigger check none\n");
        return false;
    }
}
*/
