#include "BinTree.h"
#include <iostream>

// template <typename T>
// static void visit(T &x)
// {
//     std::cout << x << " ";
// }

int main(void)
{
    BinTree<int> b;
    b.insertAsRoot(0);
    b.insertAsLC(b.root(),100);
    b.insertAsRC(b.root(),101);
    b.insertAsRC(b.root()->lc,102);
    BinNodePosi(int) temp = b.root();
    for(int i = 1; i < 10; i++){
        (b.insertAsLC(temp,i));
        temp = (b.insertAsRC(temp,i+20));
    }
    std::cout<<b.size()<<std::endl;
    b.traverse(b.root(),visit);
    std::cout<<std::endl;
    b.travIn(visit);
    return 0;
} 