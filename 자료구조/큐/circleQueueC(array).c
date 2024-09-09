#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 10
typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

//에러 함수
void error(char *message) {
    fprintf(stderr,"%s\n",message);
    exit(1);
}

//초기화
void init_queue(QueueType *q) {
    q->rear = 0; //원형 큐는 %를 쓰기 때문에 0부터 시작
    q->front = 0;
}

//가득찼는지
int is_full(QueueType *q) {
    if (q->front >= (q->rear + 1) % MAX_QUEUE_SIZE) return 1;
    else return 0;
}

//없는지
int is_empty(QueueType *q) {
    if (q->front == q->rear) return 1; //return (q->front==q->rear)도 된다.
    else return 0;
}

//프린트
void queue_print(QueueType *q) {
    printf("QUEUE(front=%d,rear=%d)",q->front,q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % MAX_QUEUE_SIZE; //다음으로 돌린다.
            printf("%d | ",q->data[i]);
            if (i == q->rear) break; 
        } while (i != q->front);
    }
    printf("\n");
}

//값 넣기
void push(QueueType *q,int value) {
    if (is_full(q)) {
        error("에러\n");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = value;
}

//값 빼기
int pop(QueueType *q) {
    if (is_empty(q)) {
        error("에러\n");
        return -1;
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    int item = q->data[q->front];
    return item;
}

//앞의 원소 빼기
element peek(QueueType *q) {
    if (is_empty(q)) {
        error("에러\n");
        return -1;
    }
    int item = q->data[(q->front + 1) % MAX_QUEUE_SIZE];
    return item;
}

int main() { //push,pop,front,back,size
    int item = 0;
    QueueType q;
    init_queue(&q);
    printf("--값 입력--\n");
    while (!is_full(&q)) {
        printf("원소를 입력하시오 : ");
        scanf("%d",&item);
        push(&q,item);
        queue_print(&q);
    }
    printf("--입력 끝--\n\n");

    printf("--값을 뺍니다.--\n");
    while (!is_empty(&q)) {
        item = pop(&q);
        printf("뺀 원소 : %d\n",item);
        queue_print(&q);
    }
    printf("--큐가 비었습니다.--\n");
    return 0;
}