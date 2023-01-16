#include "Magicdrink.h"
//add life
Magicdrink::Magicdrink(int x, int y)
{
    this->circle = new Circle(x, y, 70);
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
    //al_stop_timer(cross_timer);
    //al_destroy_timer(cross_timer);
}

void
Magicdrink::magicdrink_init(Player*p1_out,Player*p2_out,Player*p3_out,Player*p4_out)
{
    for(int i=0;i<3;i++)
    {
        char path[50];
        //snprintf(path,sizeof(path), "./picture/cross/cross%d.png", i);
        snprintf(path,sizeof(path), "./picture/character/move%d.png", i);
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
    printf("magicdrink init success\n");
}

void
Magicdrink::magicdrink_update()
{
    anime++;
    anime %= anime_time;
    if(trigger()){
        printf("magicdrink update item trigger\n");
        magicdrink_pos_x = -100;
        magicdrink_pos_y = -100;
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
        p1->life += add_life;
        printf("magicdrink trigger check 1\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p2->getCircle()))
    {
        p2->life += add_life;
        printf("magicdrink trigger check 2\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p3->getCircle()))
    {
        p3->life += add_life;
        printf("magicdrink trigger check 3\n");
        return true;
    }
    else if (Circle::isOverlap(this->circle, p4->getCircle()))
    {
        p4->life += add_life;
        printf("magicdrink trigger check 4\n");
        return true;
    }
    else
    {
        printf("magicdrink trigger check none\n");
        return false;
    }
}
