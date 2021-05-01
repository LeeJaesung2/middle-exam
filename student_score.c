// 이재성
// 2018011889
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
//student data 구조체
typedef struct{
    char name[10]; //이름을 저장할 배열
    float score; //점수를 저장하는 변수
}data; //학생의 정보를 저장할 구조체

//노드 구조체
typedef struct _node {
    data *student; //데이터를 담는 공간
    struct _node *next; //다음 노드의 주소
} node;

//리스트 구조체
typedef struct _list {
     node *head; //node의 첫번째 주소
     node *pos; //node의 주소
     int count; //리스트 크기
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
    l->pos = l->head; //pos에 head를 넣음
    while (l && (l->pos != NULL)) { //노드가 있을 경우
        printf("%s %f -> ",l->pos->student->name, l->pos->student->score);//이름과 점수 출력
        l->pos = l->pos->next; //pos가 다음 노드를 가르킴
    }
    printf("NULL\n");
}
//첫번째에 노드 삽입
void InsertListHead(list *l, data *student) { //data 구조체를 삽입
    node *new = (node *)malloc(sizeof(node)); //새 노드를 생성
    if (!new) {
        printf("Failed to create node\n");
        return;
    }

    new->student = student; //노드의 student에 student를 넣음
    new->next = l->head; //다음 노드를 가르킴
    l->head = new; //헤더를 새로운 노드로 바꾸어줌
    ++(l->count); //개수를 늘임
}
//첫번째 노드 삭제
data* DeleteListHead(list *l) { //리턴타입을 data*로 변경
    data *student = l->head->student; //student 구조체 지우기전에 저장
     
    l->pos = l->head; //pos에 head를 넣음
    if (l->pos != NULL) {
        l->pos = l->pos->next; //pos가 다음 노드를 가르킴
        --(l->count); //개수를 하나 줄임
        free(l->pos); //노드 하나를 반납함
    }
    printf("%s %f deleted\n", student->name, student->score);
    return student;
}
//리스트 삭제
void DelList(list *l) {
    while (l && (l->head != NULL)) { //노드가 모두 없어질때까지 반복
        l->pos = l->head; //노드 삭제와 같음
        l->head = l->head->next;
        free(l->pos);
    }
    free(l); //리스트 반납
}

int main(void) {
    float min = 101, max = 0, sum = 0;
    char maxname[10], minname[10];
    list *l = InitList(); //리스트 생성

    for (int i = 0; i<5; i++){
        data *student;
        printf("input name\n");
        scanf("%s",student->name); //name입력받아 data에 넣음
        printf("input score\n");
        scanf("%f",&student->score); //score를 입력받아 data에 넣음
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
    printf("Highest Score : %s %f\n", maxname, max);
    printf("Lowest Score : %s %f\n", minname, min);
    printf("Average Score : %f", sum/5);
    return 0;
}
