#include<stdlib.h>
#define MAXSIZE 100

typedef struct{
    int data[MAXSIZE];
    int top;
}dstack;

dstack* CreateStack(){
    dstack *S =(dstack*)malloc(sizeof(dstack));
	S->top = -1;
	return S; 
}

int empty(dstack *S) {
	return (S->top==-1);
}

int full(dstack *S) {
	return (S->top==(MAXSIZE-1));
}

void push(dstack *s, int data) {
	if(full(s)){
        printf("stack is full\n");
    }
	else
	    s->data[++(s->top)] = data;
}

int pop(dstack *s) {
	if(empty(s)){
        printf("stack is empty\n");
    }
	else {
        return (s->data[(s->top)--]);
	}
	return 0;
}

int peek(dstack *s) {
	return s->data[(s->top)];
}

void DeleteStack(dstack *s) { 
	if(s) {
		free(s);
	}
}