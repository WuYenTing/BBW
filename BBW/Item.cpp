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
    
}

void
Item::Draw()
{
    
}

bool
Item::trigger(Player *player)
{
    
    return true;
}
