#include<iostream>
#include "BST.h"

typedef struct temp{
    int re = 1;
    int im = 2;
}name;

int main(void)
{
    name temp1 = {1,2};
    name temp2 = {3,4};
    name *a[3];
    *a[0] = temp1;
    *a[1] = temp2;
    name* temp_a = a[1];
    std::cout<<temp_a->re<<std::endl;

    BST<int> bst;
    for(int i = 0;i < 10;i++){
        bst.insert(i);
    }
    bst.travIn(visit);
    bst.remove(5);
    bool temp = bst.search(5);
    std::cout<<std::endl;
    std::cout<<temp<<std::endl;
    return 0;
}