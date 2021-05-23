#include <stdlib.h>

#include "game.h"
#include "cell.h"
#include "snake.h"

// make_snake populates snake cells with an initial configuration
snake* make_snake(void)
{
    snake* new_snake = NULL;
    new_snake = (snake*) malloc(sizeof(snake));
    if (new_snake == NULL) {
        return NULL;
    }
    new_snake->direction = DOWN;
    new_snake->head = new_snake->tail = make_cell(30, 30);
    enqueue_cell(new_snake, 30, 20);
    enqueue_cell(new_snake, 30, 10);
    return new_snake;
}

// enqueue_cell adds a cell to head of snake
cell* enqueue_cell(snake* s, int x, int y)
{
    cell* new_cell = make_cell(x, y);
    if (new_cell == NULL) {
        return NULL;
    }
    s->head->prev = new_cell;
    new_cell->next = s->head;
    s->head = new_cell;
    return new_cell;
}

// dequeue_cell removes the tail cell of snake
void dequeue_cell(snake* s)
{
    cell* tail = s->tail;
    s->tail = s->tail->prev;
    s->tail->next = NULL;
    free(tail);
}

// move updates the s object parameters to simulate motion
void move(snake* s)
{
    int new_x, new_y; // Updated head position
    new_x = s->head->x;
    new_y = s->head->y;
    switch (s->direction) {
        case UP: {
            new_y -= SNAKE_WIDTH;
        } break;
        case DOWN: {
            new_y += SNAKE_WIDTH;
        } break;
        case LEFT: {
            new_x -= SNAKE_WIDTH;
        } break;
        case RIGHT: {
            new_x += SNAKE_WIDTH;
        } break;
    }
    if (new_x >= SC_WIDTH)
        new_x = 0;
    else if (new_x < 0)
        new_x = SC_WIDTH - SNAKE_WIDTH;

    if (new_y >= SC_HEIGHT)
        new_y = 0;
    else if (new_y < 0)
        new_y = SC_HEIGHT - SNAKE_WIDTH;

    dequeue_cell(s);
    enqueue_cell(s, new_x, new_y);
}

// draw_snake calculates the rectangles of snake and draws them to renderer
void draw_snake(SDL_Renderer** renderer, snake* s)
{
    cell* iter = s->head;
    SDL_SetRenderDrawColor(*renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
    while (iter != NULL) {
        SDL_Rect snake_cell = {iter->x, iter->y, SNAKE_WIDTH, SNAKE_WIDTH};
        SDL_RenderFillRect(*renderer, &snake_cell);
        iter = iter->next;
    }
}
