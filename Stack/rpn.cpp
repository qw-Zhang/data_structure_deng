#include<iostream>
#include<string.h>
#include"Stack.h"
#include"priority.h"

namespace rpn{
    float evaluate(char* S, char*& RPN);
    bool isdigit(char S);
    int readNumber(char* S,Stack<float>& num);
    void append(char*& RPN, float num);
    char orderBetween(char optr,char S_top);


float evaluate(char* S,char*& RPN)
{
    Stack<float> opnd;
    Stack<char> optr;
    optr.push('\0');
    while(!optr.empty()){
        if(isdigit(*S)){
           int move = readNumber(S, opnd);
           S = S + move;
           append(RPN,opnd.top());
        }else{
            switch(orderBetween(optr.top(), *S)){
            case '<':
                optr.push(*S);
                S++; break;
            case '=':
                optr.pop();
                S++; break;
            case '>':{
                char op = optr.pop();
                append(RPN,op);
                     }
            }
        }
    }
    
   
    int move = readNumber(S, opnd);
    S = S + move;
    append(RPN,opnd.top());
    std::cout<<opnd.top()<<" "<<*S;
    return 1;
}

bool isdigit(char S)
{
    if((S < 58) && (S > 47))
        return true;
    return false;
}

int readNumber(char* S, Stack<float>& num)
{
    float temp = 0;
    int i = 0;
    while(isdigit(*S) && (*S)!=0){
        temp  = temp*10 + (*S)-'0';
        S++;
        i++;
    }
    num.push(temp);

    return i;
}

void append(char*& RPN, float num)
{
    
    int len = strlen(RPN);
    std::cout<<num<<" "<<len<<std::endl;
    char* temp = new char[100];
    gcvt(num,3,temp);
    strcat(RPN,temp);
    delete[] temp;
}

}
