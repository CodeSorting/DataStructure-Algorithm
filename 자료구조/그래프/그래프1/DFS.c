#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES]; //boolean 타입을 못써서..

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

//행렬 출력
void print_adj_mat(GraphType *g) {
    for (int i=0;i<g->n;++i) {
        for (int j=0;j<g->n;++j) {
            printf("%2d ",g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

//재귀로 DFS 구현
void dfs_mat(GraphType *g, int st) { 
    int ed; //끝
    visited[st] = 1;
    printf("정점 %d ->", st);
    for (ed=0;ed<g->n;++ed) {
        if (g->adj_mat[st][ed] && !visited[ed]) {
            dfs_mat(g,ed);
        }
    }
}
/*
void dfs_list(GraphType* g, int v) {
	GraphNode* w;
	visited[v] = 1;   		
	printf("정점 %d -> ", v);		
	for (w = g->adj_list[v]; w; w = w->link)
		if (!visited[w->vertex])
			dfs_list(g, w->vertex);
}
*/
int main() {
    GraphType *g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for (int i=0;i<4;++i) {
        insert_vertex(g,i);
    }
    insert_edge(g,0,1);
    insert_edge(g,0,2);
    insert_edge(g,0,3);
    insert_edge(g,1,2);
    insert_edge(g,2,3);

    printf("깊이 우선 탐색\n");
    dfs_mat(g,0);
    printf("\n");
    free(g);
    return 0;
}