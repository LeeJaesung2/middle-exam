#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
//student data 구조체
typedef struct{
    char name[10];
    int score;
}data;

//노드 구조체
typedef struct _node {
    data *student; //데이터를 담는 공간
    struct _node *next; //다음 노드의 주소
} node;

//리스트 구조체
typedef struct _list {
     node *head; //node의 첫번째 주소
     node *pos; //node의 주소
     int count; //리스트 쿠기
} list;
//리스트 생성 함수
list* InitList() {
    list *l = (list *)malloc(sizeof(list)); //리스트 공간 할당
    l->head = (node *)malloc(sizeof(node)); //노드 공간 할당
    l->head = NULL;
    l->pos = NULL;
    l->count = 0;
    return l;
}
//리스트 크기 반환
int ListLen(list *l) {
    return l->count;
}
//리스트 출력
void PrintList(list *l) {
    l->pos = l->head;
    while (l && (l->pos != NULL)) { //노드가 있을 경우
        printf("%s %d -> ",l->pos->student->name, l->pos->student->score);
        l->pos = l->pos->next;
    }
    printf("NULL\n");
}
//첫번째에 노드 삽입
void InsertListHead(list *l, data *student) { //data 구조체를 삽입
    node *new = (node *)malloc(sizeof(node));
    if (!new) {
        printf("Failed to create node\n");
        return;
    }

    new->student = student;
    new->next = l->head;
    l->head = new;
    ++(l->count);
}
//첫번째 노드 삭제
data* DeleteListHead(list *l) { //리턴타입을 data*로 변경
    data *student = l->head->student;
     
    l->pos = l->head;
    if (l->pos != NULL) {
        l->pos = l->pos->next;
        --(l->count);
        free(l->pos);
    }
    printf("%s %d deleted\n", student->name, student->score);
    return student;
}
//리스트 삭제
void DelList(list *l) {
    while (l && (l->head != NULL)) {
        l->pos = l->head;
        l->head = l->head->next;
        free(l->pos);
    }
    free(l);
}

int main(void) {
    int min = 101, max = 0, sum = 0;
    char maxname[10], minname[10];
    list *l = InitList(); //리스트 생성

    for (int i = 0; i<5; i++){
        data *student;
        printf("input name\n");
        scanf("%s",student->name); //name입력받아 data에 넣음
        printf("input score\n");
        scanf("%d",&student->score); //score를 입력받아 data에 넣음
        InsertListHead(l, student); //student data를 노드에 넣음
        //최솟값을 찾음
        if((student->score)<min){
            min = student->score;
            strcpy(minname, student->name);
        }
        //최댓값을 찾음
        if((student->score)>max){
            max = student->score;
            strcpy(maxname, student->name);
        }
        sum += student->score; //합을 구함

    }
    printf("Highest Score : %s %d\n", maxname, max);
    printf("Lowest Score : %s %d\n", minname, min);
    printf("Average Score : %d", sum/5);
    return 0;
}
