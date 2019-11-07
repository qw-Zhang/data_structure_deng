#include<iostream>

using namespace std;

int fib(int);

int main(void)
{
    int i;
    cin>>i;
    int res = fib(i);
    cout<<"result = "<<res<<endl;
    return 0;
}

int fib(int n)
{
    int res = 0;
    int i = 0,j = 1;
    while(--n > 0){
        res = i + j;
        i = j;
        j = res;
        //n--;
    }
    return res;
}
