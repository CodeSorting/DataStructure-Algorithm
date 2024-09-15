#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
typedef struct GraphNode {
    int vertex; //노드
    struct GraphNode* link; //간선(포인터)
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode *adj_mat[MAX_VERTICES];
} GraphType;
/*
포인터 50개를 가지는 포인터 배열 생성 후 연결리스트처럼 삽입하기
0 -> 1 -> 2 -> 3 null
1 -> 2 -> 3 null
2 -> 4 null
3 null
*/
//사이즈 = 0, 각 정점에서 포인터 가리키는 곳 null로 한다.
void init(GraphType *g) {
    int v;
    g->n = 0;
    for (v=0;v<MAX_VERTICES;++v) {
        g->adj_mat[v] = NULL;
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
    GraphNode *node;
    if (start >= g->n || end >= g->n) {
        fprintf(stderr,"그래프 : 정점 번호 오류\n");
        return;
    }
    node = (GraphNode *)malloc(sizeof(GraphNode));
    node->vertex = end; // node-> vertex(end),link
    node->link = g->adj_mat[start]; // node-> vertex(end),link(adjmat[start]) -> 1 -> 2
    g->adj_mat[start] = node; // adj_mat[start],node -> vertex(end),link -> 1 -> 2  
}

//행렬 출력
void print_adj_list(GraphType *g) {
    for (int i=0;i<g->n;++i) {
        GraphNode *p = g->adj_mat[i];
        printf("정점 %d의 인접 리스트 ",i);
        while (p!=NULL) {
            printf("-> %d ",p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

int main() {
    GraphType *g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for (int i=0;i<4;++i) {
        insert_vertex(g,i);
    }
    insert_edge(g,0,1);
    insert_edge(g,1,0);
    insert_edge(g,0,2);
    insert_edge(g,2,0);
    insert_edge(g,0,3);
    insert_edge(g,3,0);
    insert_edge(g,1,2);
    insert_edge(g,2,1);
    insert_edge(g,2,3);
    insert_edge(g,3,2);
    print_adj_list(g);

    free(g);
    return 0;
}