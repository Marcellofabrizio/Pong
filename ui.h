
#ifndef _UI_H_
#define _UI_H_

#include <SDL.h>
#include "pong.h"

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

enum
{

    BORDER_SIZE = 2

};

enum
{
    MIDLINE_POINT_WIDTH = 3,
    MIDLINE_POINT_HEIGHT = 2 * MIDLINE_POINT_WIDTH,
    MIDLINE_POINT_MARGIN = 3,
    MIDLINE_PADDING = 20
};

enum
{
    FG_R = 255,
    FG_G = 255,
    FG_B = 255,
    FG_A = 255
};

enum
{
    BG_R = 0,
    BG_G = 0,
    BG_B = 0,
    BG_A = 255
};

typedef struct gameWindow
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    uint32_t last_update_time;
} GameWindow;

void initVideo();
void mainGame();
void renderScreen();
void waitForEvents();
void renderBorder();
void renderMidline();

#endif
