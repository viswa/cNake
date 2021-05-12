#include <stdlib.h>

#include "cell.h"
#include "game.h"
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
