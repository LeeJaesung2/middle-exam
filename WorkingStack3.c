#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

struct _Stack{
	int top;
	int capacity; //용량을 설정
	int *array; //array를 동적할당 받기위해 인자를 없앰
};

struct _Stack *CreateStack() { //strcut 오타 수정
	struct _Stack *S =(struct _Stack*)malloc(sizeof(struct _Stack));  //malloc의 타입 추가
	S->capacity = MAXSIZE; //MAX_SIZE를 MAXSIZE로 수정
	S->top = 1;
	S->array =malloc(S->capacity + sizeof(int)); 
	return S; //포인터를 삭제하여 리턴타입에 맞춤
}

int isEmptyStack(struct _Stack *S) { //stack의 s를 대문자로 변경
	return (S->top==-1); //실행문 추가
}

int isFullStack(struct _Stack *S) { //stacks를 Stack으로 변경, 인자의 이름 S 추가
	return (S->top==(S->capacity)-1);
}

void PushStack(struct _Stack *s, int data) { //stacks를 Stack으로 변경
	if(isEmptyStack(s)){
        printf("stack is empty"); //empty시 문장 추가
    }
	else
	    s->array[++(s->top)] = data; //data의 저장위치 설정
}

int PopStack(struct _Stack *s) { //stacks를 Stack으로 변경, 리턴타입을 int로 변경
	if(isFullStack(s)){ //S를 소문자로 변경
        printf("stack is full"); //full시 문장 추가
        return 0; //리턴값 추가
    }
	else {
		//print문 삭제
        return (s->array[(s->top)--]); //array값을 리턴하고 top을 하나 줄임
	}
}

int Top(struct _Stack *s) { //stack의 s를 대문자로 변경
	return s->array[(s->top)]; //s.data를 s->array[(s->top)]로 변경
}

void DeleteStack(struct _Stack *s) { //stack의 s를 대문자로 변경
	if(s) {
		if(s->array)
			free(s->array);
		free(s);
	}
}

int main(void) {
	struct _Stack *s = CreateStack(); //CreateStack의 리턴값을 저장할 변수를 만듦
	for (int i = 0; i <= MAXSIZE; i++) {
		PushStack(s, i*10);
		int a = Top(s); //인자를 넣어줌
		printf("%d",a);
        
	}

	DeleteStack(s); //인자를 넣어줌
}
