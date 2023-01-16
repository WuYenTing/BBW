#include "Player.h"

Player::Player(int x, int y)
{
    this->circle = new Circle(x, y, 70);
    pos_x = x;
    pos_y = y;
}

Player::~Player()
{
    delete circle;
    for(int i=0;i<12;i++)
    {
        al_destroy_bitmap(player_img[i]);
    }
    pos_x = -10;
    pos_y = -10;
}

void
Player::Draw()
{
    printf("player Draw\n");
    if(player_state == STOP)
    {
        printf("player stop\n");
        switch (player_dir)
        {
            case FRONT:
                printf("player stop front\n");
                printf("x:%d, y:%d\n",pos_x,pos_y);
                al_draw_bitmap(player_img[0], pos_x, pos_y, 0);
                //al_draw_bitmap(player_img[0], pos_x, pos_y, 0);
                printf("stop draw success\n");
                break;
            case BACK:
                al_draw_bitmap(player_img[9], pos_x, pos_y, 0);
                //al_draw_bitmap(player_img[3], pos_x, pos_y, 0);
                break;
            case LEFT:
                al_draw_bitmap(player_img[3], pos_x, pos_y, 0);
                //al_draw_bitmap(player_img[1], pos_x, pos_y, 0);
                break;
            case RIGHT:
                al_draw_bitmap(player_img[6], pos_x, pos_y, 0);
                //al_draw_bitmap(player_img[2], pos_x, pos_y, 0);
                break;
        }
    }
    if(player_state == MOVE)
    {
        printf("player move\n");
        printf("x:%d, y:%d\n",pos_x,pos_y);
        printf("move draw success\n");
        switch (player_dir)
        {
            case FRONT:
                printf("player move front\n");
                //al_draw_bitmap(player_img[0], pos_x, pos_y, 0);
                if( anime < anime_time/3 )
                {
                    al_draw_bitmap(player_img[0], pos_x, pos_y, 0);
                }
                else if( anime > 2*anime_time/3)
                {
                    al_draw_bitmap(player_img[2], pos_x, pos_y, 0);
                }
                else
                {
                    al_draw_bitmap(player_img[1], pos_x, pos_y, 0);
                }
                break;
            case BACK:
                //al_draw_bitmap(player_img[3], pos_x, pos_y, 0);
                
                if( anime < anime_time/3 )
                {
                    al_draw_bitmap(player_img[9], pos_x, pos_y, 0);
                }
                else if( anime > 2*anime_time/3)
                {
                    al_draw_bitmap(player_img[11], pos_x, pos_y, 0);
                }
                else
                {
                    al_draw_bitmap(player_img[10], pos_x, pos_y, 0);
                }
                break;
            case LEFT:
                //al_draw_bitmap(player_img[1], pos_x, pos_y, 0);
                
                if( anime < anime_time/3 )
                {
                    al_draw_bitmap(player_img[3], pos_x, pos_y, 0);
                }
                else if( anime > 2*anime_time/3)
                {
                    al_draw_bitmap(player_img[5], pos_x, pos_y, 0);
                }
                else
                {
                    al_draw_bitmap(player_img[4], pos_x, pos_y, 0);
                }
                break;
            case RIGHT:
                //al_draw_bitmap(player_img[2], pos_x, pos_y, 0);
                
                if( anime < anime_time/3+1 )
                {
                    al_draw_bitmap(player_img[6], pos_x, pos_y, 0);
                }
                else if( anime > 2*anime_time/3)
                {
                    al_draw_bitmap(player_img[8], pos_x, pos_y, 0);
                }
                else{
                    al_draw_bitmap(player_img[7], pos_x, pos_y, 0);
                }
                break;
        }
    }
    
}

void
Player::player_init(char up,char down, char left, char right, char attack, int x)
{
    OPERATION_UP = up -'A'+1;
    printf(" up %d \n",OPERATION_UP);
    OPERATION_DOWN = down -'A'+1;
    printf(" down %d \n",OPERATION_DOWN);
    OPERATION_LEFT = left -'A'+1;
    printf(" left %d \n",OPERATION_LEFT);
    OPERATION_RIGHT = right -'A'+1;
    printf(" right %d \n",OPERATION_RIGHT);
    OPERATION_ATTACK = attack  -'A'+1;
    printf(" attack %d \n",OPERATION_ATTACK);
   
    for(int i=0  ; i<12 ;i++)
    {
        char path[100];
        snprintf(path,sizeof(path), "./picture/character/type%d/move%d.png",x,i);
        //snprintf(path,sizeof(path), "./1move%d.png",  i);
        player_img[i] = al_load_bitmap(path);
    }
    //player_timer = al_create_timer(1.0/60);
    //al_start_timer(player_timer);
    player_state = STOP;
    player_dir = FRONT;
    anime = 0;
    anime_time = 20;
    speed = 0;
    life = 100;
}

void
Player::player_process(ALLEGRO_EVENT event,ALLEGRO_TIMER *timer)
{
    printf("player_process\n");
    if( event.type == ALLEGRO_EVENT_TIMER )
    {
        if( event.timer.source == timer ){
            anime++;
            anime %= anime_time;
            printf("anime = %d\n",anime);
        }
    // process the keyboard event
    }
    else if( event.type == ALLEGRO_EVENT_KEY_DOWN )
    {
        printf("player_process_key_down\n");
        key_state[event.keyboard.keycode] = true;
        anime = 0;
    }
    else if( event.type == ALLEGRO_EVENT_KEY_UP )
    {
        key_state[event.keyboard.keycode] = false;
    }
}

void
Player::player_update()
{
    //delete circle;
    printf("player_update\n");
    if( key_state[OPERATION_UP] )
    {
        player_dir = BACK;
        pos_y -= (5+speed);
        player_state = MOVE;
        printf("player_update_key_w (%d,%d)\n",pos_x,pos_y);
    }
    else if( key_state[OPERATION_DOWN] )
    {
        player_dir = FRONT;
        pos_y += (5+speed);
        player_state = MOVE;
        printf("player_update_key_s (%d,%d)\n",pos_x,pos_y);
    }
    else if( key_state[OPERATION_LEFT] )
    {
        player_dir = LEFT;
        pos_x -= (5+speed);
        player_state = MOVE;
        printf("player_update_key_a (%d,%d)\n",pos_x,pos_y);
    }
    else if( key_state[OPERATION_RIGHT] )
    {
        player_dir = RIGHT;
        pos_x += (5+speed);
        player_state = MOVE;
        printf("player_update_key_d (%d,%d)\n",pos_x,pos_y);
    }
    else if ( key_state[OPERATION_ATTACK])
    {
        printf("ATTACK!!!!\n");
        p1_attack = true;
        if(p1_attack){
            set_time = 0;
            create_waterbomb(pos_x, pos_y);
            set_time++;
        }
        
    }
    else if( anime == anime_time-1 )
    {
        anime = 0;
        player_state = STOP;
    }
    else if ( anime == 0 )
    {
        player_state = STOP;
    }
    //this->circle = new Circle(pos_x, pos_y, 70);
    if(pos_x>=1920){
        pos_x=1920;
    }
    if(pos_x<=0){
        pos_x=0;
    }
    if(pos_y<=40){
        pos_y=40;
    }
    if(pos_y>=1400){
        pos_y=1400;
    }
    this->circle->x = pos_x;
    this->circle->y = pos_y;
    
    //Draw();
}

void
Player::player_destroy()
{
    printf("player destroy\n");
    for(int i=0 ; i<12; i++)
    {
        al_destroy_bitmap(player_img[i]);
    }
}

void
Player::create_waterbomb(int x,int y)
{
    waterbomb_pos_x = x;
    waterbomb_pos_y = y;
    printf("player creat Waterbomb (%d,%d)\n",x,y);
    //printf("player creat Waterbomb success\n")
}

void
Player::waterbomb_init()
{
    for(int i=0  ; i<4 ;i++)
    {
        char path[100];
        snprintf(path,sizeof(path), "./picture/waterbomb/waterbomb%d.png",i+1);
        //snprintf(path,sizeof(path), "./1move%d.png",  i);
        waterbomb_img[i] = al_load_bitmap(path);
    }
}


void
Player::waterbomb_update(int x,int y)
{
    //anime++;
    printf("waterbomb animetime%d\n" ,anime_time);
    //anime %= anime_time;
    if(p1_attack){
        set_time++;
        if(set_time >= 210){
            set_time = 0;
            p1_attack = false;
        }
    }
    //if(set_time  )
    if(waterbomb_trigger(x,y)){
        printf("waterbomb update item trigger\n");
        //waterbomb_pos_x = -500;
        //waterbomb_pos_y = -500;
    }
    else{
        printf("waterbomb update item not trigger\n");
    }
}

void
Player::Draw_waterbomb()
{
    printf("waterbomb draw\n");
    if(p1_attack)
    {
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
        if(set_time >= 120){
            //range = 300;
            waterbomb_center_x = waterbomb_pos_x;
            waterbomb_center_y = waterbomb_pos_y;
            for(int x = 0; x < range; x++){
                al_draw_bitmap(waterbomb_img[3], waterbomb_center_x+x, waterbomb_center_y, 0);
            }
            for(int y = 0; y < range; y++){
                al_draw_bitmap(waterbomb_img[3], waterbomb_center_x, waterbomb_center_y+y, 0);
            }
            for(int x = 0; x > -range; x--){
                al_draw_bitmap(waterbomb_img[3], waterbomb_center_x+x, waterbomb_center_y, 0);
            }
            for(int y = 0; y > -range; y--){
                al_draw_bitmap(waterbomb_img[3], waterbomb_center_x, waterbomb_center_y+y, 0);
            }
        }
    }
    else
    {
        waterbomb_pos_x = -500;
        waterbomb_pos_y = -500;
    }
    printf("waterbomb draw success\n");
}

bool
Player::waterbomb_trigger(int x,int y){
    if(set_time >= 120 && set_time <= 210){
            if(((waterbomb_pos_x-range-80<=x && x<= waterbomb_pos_x+range) && (waterbomb_pos_y-100 && y<=waterbomb_pos_y+100)) ||
                   ((waterbomb_pos_x-80<=x && x<=waterbomb_pos_x+75) && (waterbomb_pos_y-range-100<=y && y<=waterbomb_pos_y+range))){
                    return true;
                }
        }
    //if(x+70>=waterbomb_pos_x)
    return false;
}
