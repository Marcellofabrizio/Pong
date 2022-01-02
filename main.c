#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "pong.h"

void gameInit(void)
{

    uint32_t last_ms;

    mainGame();
}

int main(int argc, char *argv[])
{
    initVideo();
    gameInit();
}