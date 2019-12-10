#include <iostream>
#include"Stack.h"
#include"Queen.h"

int static nCheck = 0;
int static nSolu = 0;

void placeQueens(int N)
{
    Stack<Queen> solu;
    Queen q(0,0);
    do{
        if(N <= solu.size() || N <= q.y ){
            q = solu.pop();
            q.y++;
        }else{
            while((q.y < N) && (0 <= solu.find(q))){
                q.y++;
                nCheck++;
            }
            if(N > q.y){
                solu.push(q);
                if(N <= solu.size())
                    nSolu++;
                q.x++;
                q.y = 0;
            }
        }
    }while((0 < q.x) || (q.y < N));
}
