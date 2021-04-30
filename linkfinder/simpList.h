#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct _node {
    int data;
    struct _node *next;
} node;


typedef struct _list {
     node *head;
     node *pos;
     int count;
} list;

list* InitList() {
    list *l = (list *)malloc(sizeof(list));
    l->head = (node *)malloc(sizeof(node));
    l->head = NULL;
    l->pos = NULL;
    l->count = 0;
    return l;
}

int ListLen(list *l) {
    return l->count;
}

void PrintList(list *l) {
    l->pos = l->head;
    while (l && (l->pos != NULL)) {
        printf("%d -> ", l->pos->data);
        l->pos = l->pos->next;
    }
    printf("NULL\n");
}

void InsertListHead(list *l, int data) {
    node *new = (node *)malloc(sizeof(node));
    if (!new) {
        printf("Failed to create node\n");
        return;
    }

    new->data = data;
    new->next = l->head;
    l->head = new;
    ++(l->count);
}

int DeleteListHead(list *l) {
    int data = l->head->data;
     
    l->pos = l->head;
    if (l->pos != NULL) {
        l->pos = l->pos->next;
        --(l->count);
        free(l->pos);
    }
    printf("%d deleted\n", data);
    return data;
}

void DelList(list *l) {
    while (l && (l->head != NULL)) {
        l->pos = l->head;
        l->head = l->head->next;
        free(l->pos);
    }
    free(l);
}