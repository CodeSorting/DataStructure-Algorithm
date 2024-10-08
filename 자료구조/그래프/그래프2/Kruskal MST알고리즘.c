#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 100000

int parent[MAX_VERTICES];
//union-find 알고리즘
void set_init(int n) {
    for (int i=0;i<n;++i) {
        parent[i] = -1;
    }
}

int find(int curr) {
    if (parent[curr] != -1) return curr;
    return parent[curr];
}

void Union(int a,int b) {
    int root1 = find(a);
    int root2 = find(b);
    if (root1!=root2) parent[root1] = root2;
}

struct Edge {
    int start, end, weight; // 간선 구조체(시작,끝,가중치)
};

typedef struct GraphType {
    int n; //간선 개수
    int nvertex; //정점 개수
    struct Edge edges[2*MAX_VERTICES];
} GraphType;

//그래프 초기화
void graph_init(GraphType *g) {
    g->n = g->nvertex = 0;
    for (int i=0;i<2*MAX_VERTICES;++i) {
        g->edges[i].start = 0;
        g->edges[i].end = 0;
        g->edges[i].weight = INF;
    }
}

//간선 삽입 연산
void insert_edge(GraphType *g,int start,int end,int w) {
    g->edges[g->n].start = start;
    g->edges[g->n].end = end;
    g->edges[g->n].weight = w;
    g->n++;
}

//qsort()에 사용되는 함수 c언어 정렬 함수
int compare(const void *a, const void *b) {
    struct Edge *x = (struct Edge*)a;
    struct Edge *y = (struct Edge*)b;
    return (x->weight - y->weight); //x>y이면 양수, x<y이면 음수
}

//kruskal의 최소 비용 신장 트리 프로그램
void kruskal(GraphType *g) {
    int edge_accepted = 0; //현재까지 선택된 간선의 수
    int uset,vset; //정점 u와 정점 v의 집합 번호
    struct Edge e;

    set_init(g->nvertex); //집합 초기화
    qsort(g->edges,g->n,sizeof(struct Edge),compare);
    
    printf("크루스칼 최소 신장 트리 알고리즘\n");
    int i=0;
    while (edge_accepted < (g->nvertex - 1)) {
        e = g->edges[i];
        uset = find(e.start);
        vset = find(e.end);
        if (uset != vset) {
            printf("간선 (%d,%d) %d 선택\n",e.start,e.end,e.weight);
            edge_accepted++;
            Union(uset,vset);
        }
        ++i;
    }
}

int main() {
    GraphType *g = (GraphType *)malloc(sizeof(GraphType));
    graph_init(g);

    g->nvertex = 7; //노드 개수 = 7개
    insert_edge(g,0,1,29);
    insert_edge(g,1,2,16);
    insert_edge(g,2,3,12);
    insert_edge(g,3,4,22);
    insert_edge(g,4,5,27);
    insert_edge(g,5,0,10);
    insert_edge(g,6,1,15);
    insert_edge(g,6,3,18);
    insert_edge(g,6,4,25);

    kruskal(g);
    free(g);
    return 0;
}