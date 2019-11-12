#include<iostream>
#include"vector.h" 
//template class need implements code write into .h header file
//g++ doesn't support seperate compile .h and .cpp(e.g.,vector.h vector.cpp)
//otherwise you directlly include .cpp(vector.cpp) 

using namespace std;

int main(void)
{
    int arr[5] = {0,1,2,3,4};
    Vector<int> myvector(arr,5);
    int temp = 10;
    int ss = myvector.insert(temp);
    myvector.insert(1000);
    int res = myvector.size();
    cout<<"insert position = "<<ss<<endl;
    cout<<"size = "<<res<<endl;
    return 0;
}
