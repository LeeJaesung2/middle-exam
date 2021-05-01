// 이재성
// 2018011889
#include <stdio.h>
#include <string.h>
#include "stack.h"

// Write your code here
//연산자 우선순위 비교
int prec(char op){
     switch(op){
         case '(': case ')': return 0;
         case '+': case '-': return 1;
         case '*': case '/': return 2;
     }
     return -1;
 }
//중위식을 후위식으로 바꾸는 함수
void in2postEval(char *exp, char *exp2){
    char ch, top_op;
    int num = 0;
    int len = strlen(exp); //문자열 길이
     dstack *s = CreateStack(); //스택 생성

    for(int i=0; i<len; i++){ //스택의 길이만큼 반복
        ch = exp[i]; //한글자씩 넣음
        //연산자 일 경우
        switch(ch){
            case '+': case '-': case '*': case '/':{
                while(!empty(s)&&(prec(ch))<=(prec(peek(s)))){ //스택이 비어있지 않고 이전 연산자보다 우선순위가 낮은 경우
                    printf("%c", peek(s)); //pop하여 출력
                    exp2[num++] = pop(s);
                }//while문
                push(s,ch); //연산자 push
                break;
            }//case
            case '(':{ //여는괄호를 받은 경우
                push(s,ch); //push
                break;
            }//case
            case ')':{ //닫는괄호를 받은 경우
                top_op = pop(s); //top에 하나 저장
                while(top_op != '('){ //top이 여는 괄호를 만날때까지 반복
                    printf("%c", top_op); //top 출력
                    exp2[num++] = top_op;
                    top_op = pop(s); //top에 다시 pop
                }//while문
                break;
            }//case
            default: { //숫자인 경우
                printf("%c", ch); //하나 출력
                exp2[num++] = ch;
                break;
            }//default
        }//switch문
    }//for문
    while(!empty(s)){
        printf("%c",peek(s));
        exp2[num++] = pop(s);
    }
}

typedef enum {lparen, rparen,
              plus, minus,
              times, divide,
              mod, eos, operand
              } precedence;
//문자열로 받은 연산기호를 실제 연산기호로 바꾸기 위한 함수
precedence get_token(char *exp, char *symbol, int *pn)
{
    *symbol = exp[(*pn)++];
    switch (*symbol)
    {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        case '\0': return eos;
        default : return operand;
    }
}
//후위식을 계산하는 함수
int eval(char* exp){
    precedence token;
    
    int op1, op2;
    int n = 0;
    char symbol;

    int result = 0;

    dstack *s = CreateStack(); //스택 생성

    token = get_token(exp, &symbol, &n);//연산자에 해당하는 리턴값
    
    while (token != eos) // 값이 있다면 반복
    {
        if (token == operand) //숫자인 경우
        {
            push(s, symbol-'0');
        }
        //연산자를 받음 경우
        else
        {//맨 위 두수를 가져옴
            op2 = pop(s);
            op1 = pop(s);
            //연산후 다시 stack에 넣음
            switch (token)
            {
                case plus: push(s, op1 + op2);
                        break;
                case minus: push(s, op1 - op2);
                        break;
                case times: push(s, op1 * op2);
                        break;
                case divide: push(s, op1 / op2);
                        break;
                case mod: push(s, op1 % op2);
                        break;
            }
        }
        token = get_token(exp, &symbol, &n);
    }
    return pop(s);
}

int main(void)
{
    char exp[] = "(5+4/2)*((9*7)/(8/2+3))-2";
    printf("infix : %s\n", exp);//중위식 출력
    char exp2[100]; //후위식을 저장할 배열 생성
    printf("postfix : "); 
    in2postEval(exp, exp2); //후위식을 출력하고 값을 가져옴
    
    int result = eval(exp2); //후위식을 계산함
    printf("\npostfix evaluation: %d\n", result);
    return 0;
}