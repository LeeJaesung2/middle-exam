// 이재성
// 2018011889

// Write your code here
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

struct _Stack{
	int top;
	int capacity; //용량을 설정
	int array[MAXSIZE];
};

struct _Stack *CreateStack() { //strcut 오타 수정
	struct _Stack *S =(struct _Stack*)malloc(sizeof(struct _Stack));  //malloc의 타입 추가
	S->capacity = MAXSIZE; //MAX_SIZE를 MAXSIZE로 수정
	S->top = -1;//top을 -1로 변경
	//array가 동적할당받는 문장을 삭제
	return S; //포인터를 삭제하여 리턴타입에 맞춤
}

int isEmptyStack(struct _Stack *S) { //stack의 s를 대문자로 변경
	return (S->top==-1); //실행문 추가
}

int isFullStack(struct _Stack *S) { //stacks를 Stack으로 변경, 인자의 이름 S 추가
	return (S->top==(S->capacity)-1);
}

void PushStack(struct _Stack *s, int data) { //stacks를 Stack으로 변경
	if(isFullStack(s)){//isEmptyStack을 isFullStack으로 바꿈
        printf("stack is full"); //full시 문장 추가
    }
	else
	    s->array[++(s->top)] = data; //data의 저장위치 설정
}

int PopStack(struct _Stack *s) { //stacks를 Stack으로 변경, 리턴타입을 int로 변경
	if(isEmptyStack(s)){ //S를 소문자로 변경, isFullStack을 isEmptyStack으로 바꿈
        printf("stack is empty"); //empty시 문장 추가
    }
	else {
		//print문 삭제
        return (s->array[(s->top)--]); //array값을 리턴하고 top을 하나 줄임
	}
	return 0;
}

int Top(struct _Stack *s) { //stack의 s를 대문자로 변경
	return s->array[(s->top)]; //s.data를 s->array[(s->top)]로 변경
}

void DeleteStack(struct _Stack *s) { //stack의 s를 대문자로 변경
	if(s) {
		//array가 동적할당은 받은것을 반납하는 문구를 삭제
		free(s);
	}
}

int main(void) {
	struct _Stack *s = CreateStack(); //CreateStack의 리턴값을 저장할 변수를 만듦
	for (int i = 0; i < MAXSIZE; i++) {
		PushStack(s, i*10);
		printf("%d\n", Top(s)); //Top에 이자를 넣고 출력해줌
	}

	DeleteStack(s); //인자를 넣어줌
}
