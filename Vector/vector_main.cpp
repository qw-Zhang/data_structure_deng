#include<iostream>
#include"vector.h" 
//template class need implements code write into .h header file
//g++ doesn't support seperate compile .h and .cpp(e.g.,vector.h vector.cpp)
//otherwise you directlly include .cpp(vector.cpp) 

using namespace std;

template <typename T> void visit(T& e){
    std::cout<<e<<" ";
}

int main(void)
{
    int arr[5] = {0,1,2,3,4};
    Vector<int> myvector(arr,5);
    int temp = 10;
    int ss = myvector.insert(temp);
    myvector.insert(1000);
    myvector.insert(1111);
    int res_search = myvector.search(1);
    int res = myvector.size();
    //increase(myvector);
    int dd = myvector.disordered();
    myvector.traverse(visit);
    cout<<endl;
    cout<<"insert position = "<<ss<<endl;
    cout<<"size = "<<res<<endl;
    cout<<"disorders = "<<dd<<endl;
    cout<<"position of search = "<<res_search<<endl;
    return 0;
}
