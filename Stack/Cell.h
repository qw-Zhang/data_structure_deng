//#include<iostream>
#include "Stack.h"

typedef enum {AVAILABLE, ROUTE , BACKTRACKED, WALL} Status;

typedef enum {UNKOWN, EAST, SOUTH, WEST, NORTH, NO_WAY} ESWN;

inline ESWN nextESWN(ESWN eswn)
{
    return ESWN(eswn + 1);
}

struct Cell{
    int x, y;
    Status status;

    ESWN incoming,outgoing;
};

#define LABY_MAX 24
Cell laby[LABY_MAX][LABY_MAX];

inline Cell* neighor(Cell* cell)
{
    switch(cell->outgoing){
        case EAST: return cell + LABY_MAX;
        case SOUTH: return cell + 1;
        case WEST: return cell - LABY_MAX;
        case NORTH: return cell - 1;
        default: exit(-1);
    }
}

inline Cell* advance(Cell* cell)
{
    Cell* next;
    switch (cell->outgoing){
        case EAST: 
                    next = cell + LABY_MAX;
                    next->incoming = WEST;
                    break;
        case SOUTH: 
                    next = cell + 1;
                    next->incoming = NORTH;
                    break;
        case WEST: 
                    next = cell - LABY_MAX;
                    next->incoming = SOUTH;
                    break;
        case NORTH:
                    next = cell - 1;
                    next->incoming = SOUTH;
                    break;
        default: exit(-1);

    }
    return next;
}

