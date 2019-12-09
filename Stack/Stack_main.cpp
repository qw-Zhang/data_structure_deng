#include <iostream>
#include<cstring>
#include<cstdlib>
//#include"Stack.h"
#include"rpn.cpp"

using namespace std;

void convert_recursive(Stack<char>& S, long long n, int base);
void convert_iteration(Stack<char>& S, long long n, int base);
bool paren(const char exp[], int lo,int hi);

int main()
{
/*   
    Stack<int> s;
    s.push(11);
    s.push(100);
    s.push(1000);
    std::cout << s.pop() << " "<<s.top()<<"   empty?"<<s.empty()<<std::endl;
    Stack<char> vert;
    convert_iteration(vert, 51, 16);
    while(!vert.empty()){
        cout<<vert.pop();
    }
    cout<<endl;
    
    char exp[] = "}{{[[[{{{(())}()}}]]]}}";
    int len = sizeof(exp)/sizeof(char);
    cout<<paren(exp,0,len-1)<<endl;
*/
    char S[] = "1234+23*(1+1)/33";
    char* RPN = new char[100];
    float tt = rpn::evaluate(S,RPN);
    cout<<RPN<<endl;
    cout<<tt<<endl;
    delete[] RPN;
    return 0;
}

void convert_recursive(Stack<char>& S, long long n,int base)
{
    static char digit[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    if(0 < n){
        S.push(digit[n % base]);
        convert_recursive(S, n/base, base);
    }
}

void convert_iteration(Stack<char>& S, long long n,int base)
{
    char digit[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(n > 0){
        int temp = (int) n % base;
        S.push(digit[temp]);
        n /= base;
    }

}

bool paren(const char exp[], int lo, int hi)
{
    Stack<char> S;
    for(int i = lo; i < hi;i++ ){
        switch(exp[i]){
            case '(':
            case '[':
            case '{':S.push(exp[i]); break;
                     
            case ')':
                     if((S.empty()) || ('(' != S.pop()))
                         return false;
                        break;

            case ']':
                     if((S.empty()) || ('[' != S.pop()))
                         return false;
                        break;
            case '}':
                     if((S.empty()) || ('{' != S.pop()))
                         return false;
                        break;
            default:break;
        }
    }
    return S.empty();
}


