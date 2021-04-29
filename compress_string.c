#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// import stack related definitions and functions
#define MAXSIZE 100
typedef struct{
    int array[MAXSIZE];
    int top;
}StackType;

//스택 초기화 함수
void init_stack(StackType *s){
    s->top = -1;
}

//스택 공백 상태 확인 함수
int is_empty(StackType *s){
    return (s->top ==-1);
}

//스택 포화 상태 확인 함수
int is_full(StackType *s){
    return(s->top ==(MAXSIZE -1));
}

//push 함수
void push(StackType *s, int data){
    if(is_full(s)){
        printf("stack is full\n");
        return;
    }
    else s->array[++(s->top)] = data;
}

//pop함수
int pop(StackType *s){
    if(is_empty(s)){
        printf("stack is empty\n");
        return 0;
    }
    else return s->array[(s->top)--];
}

//peek 함수
int peek(StackType *s){
    if(is_empty(s)){
        printf("stack is empty");
        return 0;
    }
    else return s->array[(s->top)];
}

int main()
{
    int letter_count = 1; //count 변수
    int num = 0;
    char top;
    char *ch;
    char result[100]; //결과를 담을 배열
    char line[100]; //문자열을 담을 배열
//  define a stack
    StackType s;
    init_stack(&s); //스택 초기화

//  initialize the stack
    printf("Input string to compress: ");
    scanf("%s", line);

    // convert to lower case
    for (int i = 0; line[i]; i++) {
        line[i] = tolower(line[i]);
        push(&s, line[i]); //한글자씩 푸쉬하여 넣음
    }//for문

    top = pop(&s);
    for (int i = 0; i<strlen(line) ; i++) {
        // compress the string here
        if(top ==peek(&s)){
            pop(&s);
            letter_count += 1;
        }//if문
        else{
            result[num++] = top;
            sprintf(ch, "%d", letter_count);
            result[num++] = *ch;
            letter_count = 1;
            top = pop(&s);
        }//else문

        if((s.top)==-1){
            break;
        }//if문

    }//for문
    result[num++] =top;
    sprintf(ch, "%d", letter_count);
    result[num] = *ch;

    printf("encoding string : ");

    while(num!=-1){
        printf("%c",result[num--]);
    }
    printf("\ndecoding string : %s", line);
    

    return 0;
} 
