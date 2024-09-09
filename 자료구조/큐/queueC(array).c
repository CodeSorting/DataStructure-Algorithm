#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 1000
typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

//오류 함수
void error(char *message) {
    fprintf(stderr,"%s\n",message);
    exit(1);
}

//초기화 함수
void init_queue(QueueType *q) {
    q->rear = -1;
    q->front = -1;
}

//큐 프린트
void queue_print(QueueType *q) {
    for (int i=MAX_QUEUE_SIZE;i>=0;--i) {
        /*
        if (i<=q->front || i>q->rear) {
            printf(" | ");
        }
        */
        if (i>q->front && i<=q->rear) {
            printf("%d | ", q->data[i]);
        }
    }
    printf("\n");
}

//가득 찼는지
int is_full(QueueType *q) {
    if (q->rear == MAX_QUEUE_SIZE - 1) return 1;
    else return 0;
}

//비어있는지
int is_empty(QueueType *q) {
    if (q->front == q->rear) return 1;
    else return 0;
}

//값 넣기
void push(QueueType *q,int value) {
    if (is_full(q)) {
        error("큐가 포화상태입니다.\n");
        return;
    }
    q->data[++(q->rear)] = value;
}

//빼기
element pop(QueueType *q) {
    if (is_empty(q)) {
        error("큐가 공백상태입니다.\n");
        return -1;
    }
    int item = q->data[++(q->front)];
    return item;
}

element peek(QueueType *q) {
    if (is_empty(q)) {
        error("큐가 공백상태입니다.\n");
        return -1;
    }
    int item = q->data[q->front];
    return item;
}

int main() { //push,pop,front,back,size
    int item = 0;
    QueueType q;
    init_queue(&q);
    
    push(&q,1); queue_print(&q);
    push(&q,2); queue_print(&q);
    push(&q,3); queue_print(&q);
    item = pop(&q); printf("%d\n",item); queue_print(&q);
    item = pop(&q); printf("%d\n",item); queue_print(&q);
    item = pop(&q); printf("%d\n",item); queue_print(&q);
    return 0;
}