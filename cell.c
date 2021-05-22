#include <stdlib.h>

#include "cell.h"

cell* make_cell(int x, int y)
{
    cell* c = NULL;
    c = (cell*) malloc(sizeof(cell));
    if (c == NULL) {
        return NULL;
    }
    c->x = x;
    c->y = y;
    c->prev = c->next = NULL;
    return c;
}