#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 11

//큐를 만드는 구조체
typedef struct _queue{
    int front;
    int rear;
    int array[MAX_SIZE];
} queue;
//큐를 생성
queue* CreateCQueue(){
    queue *q = malloc(sizeof(queue)); //큐 하나의 크기
    if(!q)
        return NULL;
    q->front = q->rear = -1;
    if(!q->array)
        return NULL;
    return q;
}
//큐가 empty인 경우
int IsEmptyCQ(queue *q)
{
    return (q->front == -1);
}
//큐가 full인 경우
int IsFullCQ(queue *q)
{
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

//enqueue함수
void EnCQ(queue *q, int data)
{
    if(IsFullCQ(q)) //큐가 가득차면 사이즈를 늘임
        printf("Queue is full");
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->array[q->rear] = data; //큐에 데이터를 넣음
    if(q->front == -1)
        q->front = q->rear;
    
    printf("EnCQueue %d\n", q->array[q->rear]);
}

int DeCQ(queue *q)
{
    int data = 0;
    if(IsEmptyCQ(q))
    {
        printf("CQueue is Empty\n");
        return 0;
    }
    else
    {
        data = q->array[q->front];
        if(q->front == q->rear)
            q->front = q->rear = -1;
        else
            q->front = (q->front+1) % MAX_SIZE;
    }
    printf("DeCQueue %d\n", data);
    return data;
}

void DelCQ(queue *q)
{
    if(q)
    {
        if(q->array)
            free(q->array);
        free(q);
    }
    printf("Queue Deleted\n");
}