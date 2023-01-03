#include "Item.h"

Item::Item(int pos_x, int pos_y)
{
    this->circle = new Circle(pos_x, pos_y, 70);
}

Item::~Item()
{

}

void
Item::Draw()
{
    
}

bool
Item::trigger_item(Player *player)
{
    return true;
}
