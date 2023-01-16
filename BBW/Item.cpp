#include "Item.h"
Item::Item(int x, int y)
{
    this->circle = new Circle(x, y, 70);
    pos_x = x;
    pos_y = y;
}

Item::~Item()
{
    delete circle;
    for(int i=0;i<3;i++)
    {
        al_destroy_bitmap(item_img[i]);
    }
    pos_x = -10;
    pos_y = -10;
    //al_stop_timer(item_timer);
    //al_destroy_timer(item_timer);
}

void
Item::item_init(Player*p1_out,Player*p2_out,Player*p3_out,Player*p4_out)
{
    for(int i=0;i<3;i++)
    {
        char path[50];
        //snprintf(path,sizeof(path), "./picture/item/item%d.png", i);
        snprintf(path,sizeof(path), "./picture/character/move%d.png", i);
        item_img[i] = al_load_bitmap(path);
    }
    //item_timer = al_create_timer(1.0/60);
    //al_start_timer(item_timer);
    p1=p1_out;
    p2=p2_out;
    p3=p3_out;
    p4=p4_out;
    printf("item init success\n");
}

void
Item::item_update()
{
    if(trigger()){
        printf("item update item trigger\n");
    }
    else{
        printf("item update item not trigger\n");
    }
}

void
Item::Draw()
{
    printf("item draw\n");
    al_draw_bitmap(item_img[0], pos_x, pos_y, 0);
    printf("item draw sucess\n");
    /*switch (frame)
    {
        case 0:
            al_draw_bitmap(item_img[0], pos_x, pos_y, 0);
            break;
        case 1:
            al_draw_bitmap(item_img[1], pos_x, pos_y, 0);
            break;
        case 2:
            al_draw_bitmap(item_img[2], pos_x, pos_y, 0);
            break;
    }*/
}

bool
Item::trigger()
{
    printf("trigger check\n");
    printf("(%d,%d)---p1 ",p1->getX(),p1->getY());
    printf("(%d,%d)---item\n",this->getX(),this->getY());
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

