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
    bubblesort1A(array,9);
    for(int i = 0;i < 9;i++){
        cout<<array[i]<<" ";
    }
}
