// 이재성
//2018011889
#include "simpList.h"

//순환 리스트를 만드는 함수
list *Creatlooplist(list *l){
    int data, loop;
    printf("How many you want loop?\n");
    scanf("%d", &loop);
    for(int i= 0; i<loop; i++){
        printf("input data : ");
        scanf("%d", &data);
        InsertListHead(l, data);
    }
    l->pos = l->head;
    while (l && (l->pos->next != NULL)) {
        l->pos = l->pos->next;
    }
    l->pos->next = l->head; //마지막 노드에 순환 시작지점 노드 주소를 넣음

    printf("how many you want to make noon loop node?\n");
    scanf("%d", &loop);
    for(int i= 0; i<loop; i++){
        printf("input data : ");
        scanf("%d", &data);
        InsertListHead(l, data);
    }
    return l;
}

//순환 지점을 찾는 함수
void FindLoop(list *l){
    //주소로 받아서 문제
    l->pos = l->head;
    list slow = *l;
    list fast = *l;
    //fast와 slow가 만날때 까지 반복
    do{
        fast.pos = fast.pos->next->next; //fast는 두칸 이동
        printf("fast %d\n", fast.pos->data);
        slow.pos = slow.pos-> next; //slow는 한칸 이동
        printf("slow %d\n", slow.pos->data);
    }while(fast.pos->next != slow.pos->next);

    printf("/////\n");
    slow.pos = l->head; //slow를 처음으로 옮김
    //fast와 slow가 만날때 까지 반복
    while(fast.pos != slow.pos){
        fast.pos = fast.pos->next; //fast, slow 모두 한칸씩 이동
        printf("fast %d\n", fast.pos->data);
        slow.pos = slow.pos-> next;
        printf("slow %d\n", slow.pos->data);
    }

    printf("start loop data is %d", fast.pos->data);
}

int main(void){
    int loop;
    list *l = InitList();
    l = Creatlooplist(l);
    FindLoop(l);
    return 0;
}