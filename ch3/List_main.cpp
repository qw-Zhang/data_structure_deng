#include <iostream>
#include<cstdlib>
#include"List.h"

using namespace std;

template <typename T>
void visit(T& e)
{
    cout<<e<<" ";
}

int main()
{
   List<int> L;
   for(int i = 0;i < 20;i++){
       L.insertAsLast(rand()%100);
   }
   int s = L.size();
   cout<<s<<endl;
   L.traverse(visit);
   cout<<endl;
   L.sort(L.first(),L.size());
   L.traverse(visit);
   cout<<endl;
   return 0;
}
