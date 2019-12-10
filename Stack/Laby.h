#include "Cell.h"

bool lanbyrinth(Cell Laby[LABY_MAX][LABY_MAX], Cell* s, Cell* t)
{
    if((AVAILABLE != s->status) || (AVAILABLE != t->status))
        return false;
    Stack <Cell*> path;
    s->incoming = UNKOWN;
    s->status = ROUTE;
    path.push(s);

    do{
        Cell* c = path.pop();
        if(c == t){
            return true;
        }
        while(NO_WAY > (c->outgoing = nextESWN(c->outgoing))){
            if(AVAILABLE == neighor(c) -> status){
                break;
            }
        }
        if(NO_WAY <= c->outgoing){
            c->status = BACKTRACKED;
            c = path.pop();
        }else{
            path.push(c = advance(c));
            c->outgoing = UNKOWN;
            c->status = ROUTE;
        }
    }while(!path.empty());
    
    return false;
}