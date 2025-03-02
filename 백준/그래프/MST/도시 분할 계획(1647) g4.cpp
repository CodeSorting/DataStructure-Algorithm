#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void munion(int i, int j);
int find(int a);
static vector<int> parent;

struct Edge {  
    int s, e, v;
    bool operator > (const Edge& temp) const {
        return v > temp.v;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    parent.resize(n + 1);
    
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        pq.push(Edge{ s, e, v });
    }

    int useEdge = 0;
    int result = 0;
    int maxCost = 0;  // 가장 비싼 간선을 저장할 변수

    while (useEdge < n - 1) { // MST 생성
        Edge now = pq.top();
        pq.pop();
        if (find(now.s) != find(now.e)) { // 사이클이 생기지 않으면 추가
            munion(now.s, now.e);
            result += now.v;
            maxCost = now.v; // 가장 비싼 간선 업데이트
            useEdge++;
        }
    }
    
    cout << result - maxCost; // 가장 비싼 간선을 제거한 값 출력
}

void munion(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}

int find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]); // 경로 압축
}