#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 1000
typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} DequeType;

//오류 함수
void error(char *message) {
    fprintf(stderr,"%s\n",message);
    exit(1);
}

//초기화 함수
void init_deque(DequeType *q) {
    q->rear = 0;
    q->front = 0;
}

//가득 찼는지
int is_full(DequeType *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//비어있는지
int is_empty(DequeType *q) {
    return (q->rear==q->front);
}

//디큐 프린트
void deque_print(DequeType *q) {
    printf("DEQUE(front=%d,rear=%d)",q->front,q->rear);
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

//앞에 값 넣기
void push_front(DequeType *q,int value) {
    if (is_full(q)) {
        error("큐가 포화상태입니다.\n");
    }
    q->data[q->front] = value;
    q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; //데이터 그자리에 넣고 한 칸 앞으로 front 옮기기
}

//뒤에 값 넣기
void push_back(DequeType *q,int value) {
    if (is_full(q)) {
        error("큐가 포화상태입니다.\n");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = value; //rear + 1하고 데이터 넣기
}

//앞에 빼기
element pop_front(DequeType *q) {
    if (is_empty(q)) {
        error("큐가 공백상태입니다.\n");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    int item = q->data[q->front]; //front 한칸 앞으로 가고 데이터 반환
    return item;
}

//뒤에 빼기
element pop_back(DequeType *q) {
    if (is_empty(q)) {
        error("큐가 공백상태입니다.\n");
    }
    int prev = q->rear;
    q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    int item = q->data[prev]; //front 한칸 뒤로 가고 데이터 반환
    return item;
}

//맨 앞의 원소 뽑기
element get_front(DequeType *q) {
    if (is_empty(q)) {
        error("큐가 공백상태입니다.\n");
    }
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

//맨 뒤의 원소 뽑기
element get_back(DequeType *q) {
    if (is_empty(q)) {
        error("큐가 공백상태입니다.\n");
    }
    return q->data[q->rear];
}

int main() { //push,pop,front,back,size
    int item = 0;
    DequeType q;
    init_deque(&q);
    
    push_front(&q,1); // 1
    deque_print(&q);
    push_front(&q,2); // 2 1
    deque_print(&q);
    push_back(&q,3); // 2 1 3
    deque_print(&q);
    push_back(&q,4); // 2 1 3 4
    deque_print(&q);
    pop_front(&q); // 1 3 4
    deque_print(&q);
    pop_back(&q); // 1 3
    deque_print(&q);
    element a = get_front(&q);
    printf("%d\n",a);
    a = get_back(&q);
    printf("%d\n",a);
    return 0;
}