// 이재성
// 2018011889
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
    char top; //맨 위 값을 저장할 변수
    char *ch; //정수를 문자열로 바꿀때 필요한 변수
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

    top = pop(&s); //맨 위값을 top에 넣음
    for (int i = 0; i<strlen(line) ; i++) {
        // compress the string here
        if(top ==peek(&s)){ //남은 맨 위값과 top값이 같을 경우
            pop(&s); //값은 pop함
            letter_count += 1; //count를 하나 늘임
        }//if문
        else{ //top값과 남은 맨 위값이 다른 경우
            result[num++] = top; //top 저장
            sprintf(ch, "%d", letter_count); //count를 문자열로 바꾸어 저장
            result[num++] = *ch; //배열에 저장
            letter_count = 1; //count 1로 초기화
            top = pop(&s); //맨 위값을 top에 넣음
        }//else문
        //스택이 비었을 경우
        if((s.top)==-1){
            break;
        }//if문

    }//for문
    //마지만 문자는 저장하지 못하여 한번 더 실행
    result[num++] =top;
    sprintf(ch, "%d", letter_count);
    result[num] = *ch;

    printf("encoding string : ");
    //wile문으로 실행
    while(num!=-1){
        printf("%c",result[num--]);
    }
    printf("\ndecoding string : %s", line);
    

    return 0;
} 
