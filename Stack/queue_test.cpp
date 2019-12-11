#include "queue.h"
#include <iostream>

using namespace std;

int main(void)
{
    Queue<int> q;
    for(int i = 0;i < 10;i++){
        q.enqueue(i);
    }
    int len = q.size();
    for(int i = 0; i < len;i++){
        cout<<q.dequeue()<<" ";
    }
    return 0;
}