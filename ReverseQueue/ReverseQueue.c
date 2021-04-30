// 이재성
// 2018011889

// Write your code here

#include "circular_queue.h"
#include "stack.h"

queue* ReverseQueue(queue *q){
    dstack *s;
    s = CreateStack();
    while ((q->rear) != (q->front)){
        push(s, DeCQ(q));
    }
    push(s,DeCQ(q));
    while((s->top) != -1){
        EnCQ(q, pop(s));
    }
    DeleteStack(s);
    printf("\n");
    return q;
}

int main(void)
{
    queue *Q = CreateCQueue();
    printf("Nomal Queue\n");
    for (int i = 0; i < 10; i++) {
        EnCQ(Q, i*10);
    }
    printf("\n");
    Q = ReverseQueue(Q);
    printf("\nReverse Queue\n");
    for (int i = 0; i <10; i++) 
        DeCQ(Q);
    DelCQ(Q);
    return 0;
}