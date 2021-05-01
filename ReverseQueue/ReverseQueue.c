// 이재성
// 2018011889

// Write your code here

#include "circular_queue.h"
#include "stack.h"

queue* ReverseQueue(queue *q){
    dstack *s;
    s = CreateStack(); //스택 생성
    //큐에있는 값을을 빼서 스택에 넣음
    while ((q->rear) != (q->front)){
        push(s, DeCQ(q));
    }
    push(s,DeCQ(q)); //마지막 값도 스택에 넣음
    //스택의 값들을 다시 큐에 넣음
    while((s->top) != -1){
        EnCQ(q, pop(s));
    }
    DeleteStack(s); //스택을 삭제함
    printf("\n");
    return q;
}

int main(void)
{
    queue *Q = CreateCQueue(); //큐를 생성
    printf("Nomal Queue\n"); //일반 큐를 출력
    //큐에 값을 넣음
    for (int i = 0; i < 10; i++) {
        EnCQ(Q, i*10);
    }
    printf("\n");
    Q = ReverseQueue(Q); //큐 값을 반대로 만듦
    printf("\nReverse Queue\n");
    //큐 값을 출력함
    for (int i = 0; i <10; i++) 
        DeCQ(Q);
    DelCQ(Q); //큐를 삭제함
    return 0;
}