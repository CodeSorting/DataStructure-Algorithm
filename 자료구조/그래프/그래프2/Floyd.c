#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF	1000000 //연결 x인경우

typedef struct GraphType {
    int n; //정점 개수
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int A[MAX_VERTICES][MAX_VERTICES];

//행렬 프린트
void printA(GraphType *g) {
    int i,j;
    for (i=0;i<g->n;++i) {
        for (j=0;j<g->n;++j) {
            if (A[i][j]==INF) printf(" * ");
            else printf("%3d ",A[i][j]);
        }
        printf("\n");
    }
}

//플로이드 워셜 알고리즘. (k,i,j 순서대로 최신화)
void floyd(GraphType *g) {
    int i,j,k;
    for (i=0;i<g->n;++i) {
        for (j=0;j<g->n;++j) {
            A[i][j] = g->weight[i][j];
        }
    }
    printA(g);

    for (k=0;k<g->n;++k) {
        for (i=0;i<g->n;++i) {
            for (j=0;j<g->n;++j) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
    }
    printA(g);
}

int main() {
    GraphType g = { 7,
	{{ 0,  7,  INF, INF,   3,  10, INF },
	{ 7,  0,    4,  10,   2,   6, INF },
	{ INF,  4,    0,   2, INF, INF, INF },
	{ INF, 10,    2,   0,  11,   9,   4 },
	{ 3,  2,  INF,  11,   0, INF,   5 },
	{ 10,  6,  INF,   9, INF,   0, INF },
	{ INF, INF, INF,   4,   5, INF,   0 } }
	};
	floyd(&g);
    return 0;
}