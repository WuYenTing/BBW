#include "Gamewindow.h"

int main(int argc, char *argv[])
{
    Gamewindow *BBW = new Gamewindow();

    BBW->game_play();

    delete BBW;
    return 0;
}
