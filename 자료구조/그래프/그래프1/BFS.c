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

//빼고 삭제
element pop(QueueType *q) {
    if (is_empty(q)) {
        error("큐가 공백상태입니다.\n");
        return -1;
    }
    int item = q->data[++(q->front)];
    return item;
}

//제일 위 원소 빼기
element peek(QueueType *q) {
    if (is_empty(q)) {
        error("큐가 공백상태입니다.\n");
        return -1;
    }
    int item = q->data[q->front];
    return item;
}

#define MAX_VERTICES 50
typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

//사이즈 = 0, 행렬 내의 모든 값 = 0(연결x)
void init(GraphType *g) {
    int r,c;
    g->n = 0;
    for (r=0;r<MAX_VERTICES;++r) {
        for (c=0;c<MAX_VERTICES;++c) {
            g->adj_mat[r][c] = 0;
        }
    }
}

//노드 넣기(그냥 사이즈 + 1)
void insert_vertex(GraphType *g,int v) {
    if ((g->n) + 1 > MAX_VERTICES) {
        fprintf(stderr,"그래프 : 정점의 개수 초과\n");
        return;
    }
    g->n++;
}

//간선 넣기
void insert_edge(GraphType *g,int start,int end) {
    if (start >= g->n || end >= g->n) {
        fprintf(stderr,"그래프 : 정점 번호 오류\n");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

//BFS 구현 (큐로)
void bfs_mat(GraphType *g,int v) {
    int st;
    QueueType q;
    init_queue(&q);
    visited[v] = 1;
    printf("%d 방문 -> ",v);
    push(&q,v);
    while (!is_empty(&q)) {
        st = pop(&q);
        for (int ed=0;ed<g->n;++ed) {
            if (g->adj_mat[st][ed] && !visited[ed]) {
                visited[ed] = 1;
                printf("%d 방문 -> ",ed);
                push(&q,ed);
            }
        }
    }
}
/*
void bfs_list(GraphType* g, int v) {
	GraphNode* w;
	QueueType q;

	init(&q);    			
	visited[v] = 1;
	printf("%d 방문 -> ", v);
	enqueue(&q, v);		
	while (!is_empty(&q)) {
		v = dequeue(&q);		 
		for (w = g->adj_list[v]; w; w = w->link) 
			if (!visited[w->vertex]) {
				visited[w->vertex] = 1;  
				printf("%d 방문 -> ", w->vextex);
				enqueue(&q, w->vertex);	
			}
	}
}
*/

int main() { 
    GraphType *g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for (int i=0;i<6;++i) {
        insert_vertex(g,i);
    }
    insert_edge(g,0,2);
    insert_edge(g,2,1);
    insert_edge(g,2,3);
    insert_edge(g,0,4);
    insert_edge(g,4,5);
    insert_edge(g,1,5);

    printf("너비 우선 탐색\n");
    bfs_mat(g,0);
    printf("\n");
    free(g);
    return 0;
}