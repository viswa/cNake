#ifndef SNAKE_H_
#define SNAKE_H_

#include <SDL2/SDL.h>

#include "game.h"
#include "cell.h"

#define INITIAL_SNAKE_LEN 10
#define SNAKE_WIDTH 10

typedef struct snake snake;
typedef struct food food;

/**
snake struct represents a snake object. snake is designed to be a queue data
structure implemented with a doubly-linked list.
*/
struct snake {
    cell* head;
    cell* tail;
    DIRECTION direction;
};

snake* make_snake(void);
cell* enqueue_cell(snake* s, int x, int y);
void dequeue_cell(snake* s);
void move(snake* s);
void draw_snake(SDL_Renderer** renderer, snake* s);

#endif