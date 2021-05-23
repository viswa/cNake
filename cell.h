#ifndef CELL_H_
#define CELL_H_

typedef struct cell cell;

struct cell {
    int x, y;
    cell* prev;
    cell* next;
};

cell* make_cell(int x, int y);

#endif
