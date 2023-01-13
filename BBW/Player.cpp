#include "Player.h"
Player::Player(int pos_x, int pos_y)
{
    this->circle = new Circle(pos_x, pos_y, 70);
}

Player::~Player()
{
    
}

void 
Player::Draw()
{
    if(player_state == STOP)
    {
        switch (player_dir)
        {
            case FRONT:
                
                break;
            case BACK:
                
                break;
            case LEFT:
                
                break;
            case RIGHT:
                
                break;
        }
    }
    if(player_state == MOVE)
    {
        switch (player_dir)
        {
            case FRONT:
                
                break;
            case BACK:
                
                break;
            case LEFT:
                
                break;
            case RIGHT:
                
                break;
        }
    }
}    

void 
Player::player_init()
{
    for(int i=0  ; i<=12 ;i++)
    {
        char path[50];
        sprintf(path, "./picture/character/move%d.png", i);
        player_img[i] = al_load_bitmap(path);
    }
    player_state = STOP;
    player_dir = FRONT;
    anime = 0;
    
}

void 
Player::player_process()
{

}

void 
Player::player_update()
{

}

void 
Player::player_destroy()
{

}

