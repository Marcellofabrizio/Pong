#ifndef _PONG_H_
#define _PONG_H_

#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#define PI 3.14159265358979323846264

typedef struct racket
{
    int y, height, width;
} Racket;

typedef struct ball
{
    int x, y;
} Ball;

typedef struct player
{
    Racket racket;
    int score;
} Player;

typedef struct game_state
{
    Player player1, player2;
    Ball ball;

} GameState;

void initGameState();

#endif