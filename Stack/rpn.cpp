#include<cstring>
#include<cmath>
#include"Stack.h"
#include"priority.h"

namespace rpn{
    float evaluate(char* S, char*& RPN);
    bool isdigit(char S);
    int readNumber(char* S,Stack<float>& num);
    void append(char*& RPN, float num);
    void append(char*& RPN, char op);
    char orderBetween(char optr,char S_top);
	float calcu(char op,float popnd);
	float calcu(float popnd1,char op,float popnd2);

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
		                if('!'==op){
		                float popnd = opnd.pop();
		                opnd.push(calcu(op,popnd));
		            	}else{
		            		float popnd2 = opnd.pop(), popnd1 = opnd.pop();
		            		opnd.push(calcu(popnd1,op,popnd2));
						}
						break;
		            }
		            default:exit(-1);
		        }
	    	}
		}
		
	    return opnd.pop();
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
	    
	    char* temp = new char[100];
	    gcvt(num,3,temp);
	    strcat(RPN,temp);
	    int len = strlen(RPN);
        RPN[len] = ' ';
        RPN[len + 1] = '\0';
	    delete[] temp;
	}
	
	void append(char*& RPN, char op)
	{
		char* op_temp = new char[2];
		op_temp[0] = op;
		op_temp[1] = '\0';
		strcat(RPN,op_temp);
	    int len = strlen(RPN);
        RPN[len] = ' ';
        RPN[len + 1] = '\0';
		delete[] op_temp; 
	}
	
    Operator optr2rank(char op)
    {
        switch(op){
        case '+': return ADD;
        case '-': return SUB;
        case '*': return MUL;
        case '/': return DIV;
        case '^': return POW;
        case '!': return FAC;
        case '(': return L_P;
        case ')': return R_P;
        case '\0':return EOE;
        default: exit(-1);
        }
    }

	char orderBetween(char optr,char S_top)
	{
	    return pri[optr2rank(optr)][optr2rank(S_top)];	
	}
	
	float calcu(char op,float popnd)
	{
		float res = 1;
		for(int i = 1;i <= popnd;i++){
			res *= i;
		}
		return res;
	}
	
	float calcu(float popnd1,char op,float popnd2)
	{
		switch(op){
			case '+':{
				return popnd1 + popnd2;
				break;
			}
			case '-':{
				return popnd1 - popnd2;
				break;
			}
			case '*':{
				return popnd1 * popnd2;
				break;
			}
			case '/':{
				return popnd1 / popnd2;
				break;
			}
			case '^':{
				return pow(popnd1,popnd2);
				break;
			}
			default:{
				return 0;
				break;
			}			
		}
	}

}
