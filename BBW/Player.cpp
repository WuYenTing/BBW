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
                al_draw_bitmap(player_img[0], pos_x, pos_y, 0);
                break;
            case BACK:
                al_draw_bitmap(player_img[9], pos_x, pos_y, 0);
                break;
            case LEFT:
                al_draw_bitmap(player_img[3], pos_x, pos_y, 0);
                break;
            case RIGHT:
                al_draw_bitmap(player_img[6], pos_x, pos_y, 0);
                break;
        }
    }
    if(player_state == MOVE)
    {
        switch (player_dir)
        {
            case FRONT:
                
                al_draw_bitmap(player_img[0], pos_x, pos_y, 0);
                break;
            case BACK:
                
                al_draw_bitmap(player_img[9], pos_x, pos_y, 0);
                break;
            case LEFT:
                
                al_draw_bitmap(player_img[3], pos_x, pos_y, 0);
                break;
            case RIGHT:
                
                al_draw_bitmap(player_img[6], pos_x, pos_y, 0);
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
    speed = 0;
    life = 100;
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
    for(int i=0 ; i<=12; i++)
    {
        al_destroy_bitmap(player_img[i]);
    }
    
}

