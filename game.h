#ifndef GAME_H_
#define GAME_H_

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
} DIRECTION;

#define SC_WIDTH 640
#define SC_HEIGHT 480

_Noreturn void quit();

#endif