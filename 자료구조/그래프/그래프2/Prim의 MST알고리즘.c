#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
	int n;	
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int selected[MAX_VERTICES]; //선택됐는지 판단배열
int distance[MAX_VERTICES]; //거리배열

//최소 dist[v] 값을 찾는 정점을 반환
int get_min_vertex(int n) {
	int v, i;
	for (i = 0; i < n; i++)
		if (!selected[i]) { //선택 안된 인덱스 찾고 break
			v = i;
			break;
		}
	for (i = 0; i < n; i++) //거리 최소인 인덱스 찾기
		if (!selected[i] && (distance[i] < distance[v])) v = i;
	return (v);
}

//프림 알고리즘
void prim(GraphType* g, int s) {
	int i, u, v;

	for (u = 0; u < g->n; u++) //모든 거리 INF로 초기화
		distance[u] = INF;
	distance[s] = 0; //시작 거리 = 0
	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE; //선택됨
		if (distance[u] == INF) return;
		printf("정점 %d 추가\n", u);
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF) //연결 여부 확인
				if (!selected[v] && g->weight[u][v] < distance[v]) //선택 안 되었고 가중치가 거리배열의 값보다 낮을 때
					distance[v] = g->weight[u][v];
	}
}

int main() {
    /*
    GraphType a;
    int n;
    scanf("%d",&n);
    a.n = n;
    int st,ed,value;
    for (int i=0;i<n;++i) {
        scanf("%d %d %d",st,ed,value);
        a.weight[st][ed] = value;
    } 이렇게 입력을 넣을 수도 있다.
    */
	GraphType g = { 7,
	{{ 0, 29, INF, INF, INF, 10, INF },
	{ 29,  0, 16, INF, INF, INF, 15 },
	{ INF, 16, 0, 12, INF, INF, INF },
	{ INF, INF, 12, 0, 22, INF, 18 },
	{ INF, INF, INF, 22, 0, 27, 25 },
	{ 10, INF, INF, INF, 27, 0, INF },
	{ INF, 15, INF, 18, 25, INF, 0 } }
	};
	prim(&g, 0);
	return 0;
}