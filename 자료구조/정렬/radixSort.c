/*
수가 1~10000이라면 int arr[10001]을 짜고 scanf("%d",temp); arr[temp]++로 둔 다음에 하면 O(n)에 할 수 있다.
*/
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
#define BUCKETS 10
#define DIGITS 4
//큐를 이용해 
void radix_sort(int list[],int n) {
    int i,b,d,factor = 1;
    QueueType q[BUCKETS];

    for (b=0;b<BUCKETS;++b) init_queue(&q[b]); //큐들 초기화

    for (d=0;d<DIGITS;++d) {
        for (i=0;i<n;++i) { //데이터 자릿수에 따라 큐에 삽입
            push(&q[(list[i]/factor) % 10],list[i]);
        }
        for (b=i=0;b<BUCKETS;++b) { //버킷에서 꺼내어 list로 합친다.
            while (!is_empty(&q[b]))
                list[i++] = pop(&q[b]);
        }
        factor *= 10; //그 다음 자릿수로 간다.
    }
}

#define SIZE 10

int main() { //push,pop,front,back,size
    int list[SIZE];
    srand(time(NULL));
    for (int i=0;i<SIZE;++i)
        list[i] = rand()%100;
    
    radix_sort(list,SIZE);
    for (int i=0;i<SIZE;++i) {
        printf("%d ",list[i]);
    }
    printf("\n");
    return 0;
}