#include<iostream>

using namespace std;

void bubblesort1A(int A[],int n)
{
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for(int i = 1;i < n;i++){
            if(A[i-1]>A[i]){
                swap(A[i-1],A[i]);
                sorted = false;
            }
        }
        n--;
    }
}

int main(void)
{
    int array[] = {2,13,345,63,2,1,434,21,18};
    int len = sizeof(array)/sizeof(array[0]);
    bubblesort1A(array,len);
    for(int i = 0;i < len;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}
