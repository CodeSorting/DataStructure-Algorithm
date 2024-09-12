#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

#define MAX_QUEUE_SIZE 100
typedef TreeNode* element; //treenode 포인터를 element라고 한다.
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

void level_order(TreeNode *ptr) {
    QueueType q;
    init_queue(&q);
    if (ptr==NULL) return;
    push(&q,ptr);
    while (!is_empty(&q)) { //큐에 계속 자식 노드 넣기 (왼쪽->오른쪽으로 순회한다.)
        ptr = pop(&q);
        printf(" [%d] ", ptr->data);
        if (ptr->left) {
            push(&q,ptr->left);
        }
        if (ptr->right) {
            push(&q,ptr->right);
        }
    }
}

/*
      15
    4   20
  1    16 25
*/
TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 4,&n1,NULL };
TreeNode n3 = { 16,NULL,NULL };
TreeNode n4 = { 25,NULL,NULL };
TreeNode n5 = { 20,&n3,&n4 };
TreeNode n6 = { 15,&n2,&n5 };
TreeNode *root = &n6;

int main() {
    printf("레벨 순회=");
    level_order(root);
    printf("\n");
    return 0;
}