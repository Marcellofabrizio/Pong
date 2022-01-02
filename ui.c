#include "ui.h"

GameWindow gameWindow;

void initVideo()
{

    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {

        gameWindow.window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED,
                                             SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
                                             WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

        if (!gameWindow.window)
        {
            printf("Failed to create window\n");
            exit(1);
        }

        gameWindow.renderer = SDL_CreateRenderer(gameWindow.window, -1, SDL_RENDERER_ACCELERATED);

        if (gameWindow.renderer)
        {
            return;
        }

        SDL_DestroyWindow(gameWindow.window);
    }
    SDL_Quit();
}

void mainGame()
{

    waitForEvents();
}

void waitForEvents()
{

    gameWindow.last_update_time = SDL_GetTicks();
    SDL_Event event;
    bool quit = false;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }

            renderScreen();
        }
    }
}

void renderScreen()
{

    SDL_SetRenderDrawColor(gameWindow.renderer, 0, 0, 0, 0);
    SDL_RenderClear(gameWindow.renderer);
    renderBorder();
    SDL_RenderPresent(gameWindow.renderer);
}

void renderBorder()
{
    int x, y;

    SDL_Rect rect;

    for (x = 0; x < WINDOW_WIDTH; x++)
    {
        rect = (SDL_Rect){x, 0, BORDER_SIZE, BORDER_SIZE};
        SDL_SetRenderDrawColor(gameWindow.renderer, FG_R, FG_G, FG_B, FG_A);
        SDL_RenderFillRect(gameWindow.renderer, &rect);

        rect = (SDL_Rect){x, WINDOW_HEIGHT-BORDER_SIZE , BORDER_SIZE , BORDER_SIZE };
        SDL_SetRenderDrawColor(gameWindow.renderer, FG_R, FG_G, FG_B, FG_A);
        SDL_RenderFillRect(gameWindow.renderer, &rect);
    }

    for (y = 0; y < WINDOW_HEIGHT; y++)
    {
        rect = (SDL_Rect){0, y, BORDER_SIZE, BORDER_SIZE};
        SDL_SetRenderDrawColor(gameWindow.renderer, FG_R, FG_G, FG_B, FG_A);
        SDL_RenderFillRect(gameWindow.renderer, &rect);

        rect = (SDL_Rect){WINDOW_WIDTH-BORDER_SIZE, y, BORDER_SIZE, BORDER_SIZE};
        SDL_SetRenderDrawColor(gameWindow.renderer, FG_R, FG_G, FG_B, FG_A);
        SDL_RenderFillRect(gameWindow.renderer, &rect);
    }
}