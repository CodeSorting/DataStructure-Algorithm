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

int distance[MAX_VERTICES]; //최단 경로 거리
int visited[MAX_VERTICES]; //방문 여부

int choose(int distance[],int n,int visited[]) {
    int i,min,minpos;
    min = INT_MAX;
    minpos = -1;
    for (int i=0;i<n;++i) {
        if (distance[i] < min && !visited[i]) {
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}

//현 상태 출력 : distance, visited 출력
void print_status(GraphType *g) {
    static int step = 1;
    printf("STEP %d: ",step++);
    printf("distance: ");
    for (int i=0;i<g->n;++i) {
        if (distance[i] == INF) printf(" * ");
        else printf("%2d ",distance[i]);
    }
    printf("\n");
    printf(" visited: ");
    for (int i=0;i<g->n;++i) {
        printf("%2d ",visited[i]);
    }
    printf("\n\n");
}

void shortest_path(GraphType *g,int start) {
    int i,u,w;
    for (int i=0;i<g->n;++i) {
        distance[i] = g->weight[start][i]; //거리 초기화
        visited[i] = FALSE;
    }
    visited[start] = TRUE;
    distance[start] = 0; //시작점 셋팅
    for (int i=0;i<g->n-1;++i) {
        print_status(g);
        u = choose(distance,g->n,visited); //distance가 최소인 다음 값 찾기
        visited[u] = TRUE;
        for (w=0;w<g->n;++w) {
            if (!visited[w]) {
                if (distance[u] + g->weight[u][w] < distance[w]) {
                    distance[w] = distance[u] + g->weight[u][w];
                }
            }
        }

    }
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
	shortest_path(&g, 0);
    return 0;
}