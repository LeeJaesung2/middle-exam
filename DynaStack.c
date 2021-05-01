// 이재성
// 2018011889

// Write your code here
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 64

struct _Stack{
	int top;
	int capacity; //용량을 설정
	int *array; //array를 동적할당 받기위해 인자를 없앰
};

struct _Stack *CreateStack() { //strcut 오타 수정
	struct _Stack *S =(struct _Stack*)malloc(sizeof(struct _Stack));  //malloc의 타입 추가
	S->capacity = MAXSIZE; //MAX_SIZE를 MAXSIZE로 수정
	S->top = -1; //top을 -1로 수정
	S->array =malloc((S->capacity) * sizeof(int)); //int사이즈를 곱함 
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
        s->capacity += 1; //capacity의 크기를 1 늘임
		realloc(s->array, s->capacity * sizeof(int) ); //공간의 크기를 재할당 함	
    }
	 s->array[++(s->top)] = data; //else문을 삭제함
}

int PopStack(struct _Stack *s) { //stacks를 Stack으로 변경, 리턴타입을 int로 변경
	if(isEmptyStack(s)){ //S를 소문자로 변경, isFullStack을 isEmptyStack으로 바꿈
        printf("stack is empty\n"); //full시 문장 추가
        return 0; //리턴값 추가
    }
	else {
		//print문 삭제
        int num =  (s->array[(s->top)--]); //array값을 num에 저장하고 top을 하나 줄임
		if(s->top<(s->capacity)/2){ //top이 용량의 반보다 작을 경우
			s->capacity /= 2; //용량을 반으로 줄임
			realloc(s->array, (s->capacity)*sizeof(int)); //공간을 재 할당함
		}
		return num; //pop한 값을 리턴함
	}
}

int Top(struct _Stack *s) { //stack의 s를 대문자로 변경
	return s->array[(s->top)]; //s.data를 s->array[(s->top)]로 변경
}

void DeleteStack(struct _Stack *s) { //stack의 s를 대문자로 변경
	if(s) {
		if(s->array) 
			free(s->array); //할당받은 배열 반환
		free(s); //할당받은 스택 반환
	}
}


int main(void) {
	struct _Stack *s = CreateStack();//CreateStack의 리턴값을 저장할 변수를 만듦
	for (int i = 0; i <= MAXSIZE; i++) {
		PushStack(s, i*10);
		printf("Top : %d, ",Top(s)); //인자를 넣어줌, 프린트 문으로 실행확인
		printf("size of Stack : %d\n", s->capacity);
		
	}
	printf("\n");
    for (int i = 0; i <= MAXSIZE; i++) {
		printf("Top : %d, ",PopStack(s)); //i*10인자를 삭제, pop한 수 출력
		printf("size of Stack : %d\n", s->capacity);
	}

	DeleteStack(s); //인자를 넣어줌
}