#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAX_COLOR = 1000001;

int n;
int parent[MAX_COLOR];
int edgeCount[MAX_COLOR];
int selfCount[MAX_COLOR];
int sizes[MAX_COLOR];
bool used[MAX_COLOR+1];
int find(int a) {
    if (parent[a]==a) return a;
    return parent[a] = find(parent[a]);
}
void Union(int a,int b) {
    a = find(a);
    b = find(b);
    if (a==b) {
        edgeCount[a] += 1;
        return;
    }
    if (sizes[a]<sizes[b]) swap(a,b);
    parent[b] = a; // 더 큰 쪽인 a에 합치기
    sizes[a] += sizes[b];
    edgeCount[a] += edgeCount[b] + 1;
    selfCount[a] += selfCount[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<int> top(n),bottom(n);
    for (int i=0;i<n;++i) cin>>top[i];
    for (int i=0;i<n;++i) cin>>bottom[i];
    for (int i=0;i<MAX_COLOR;++i) parent[i] = i;
    for (int i=0;i<MAX_COLOR;++i) sizes[i] = 1;
    for (int i=0;i<n;++i) {
        int a = top[i],b = bottom[i];
        used[a] = true; used[b] = true;
        if (a==b) {
            int pa = find(a);
            ++selfCount[pa];
        }
        else {
            Union(a,b);
        }
    }
    long long ans = 0;
    for (int i=0;i<MAX_COLOR;++i) {
        if (find(i)==i && used[i]) {
            int d = sizes[i]; //색 개수
            int c = edgeCount[i] + selfCount[i]; //간선수 + 자기자신수 (카드수)
            if (d==1) {
                ++ans; //d == 1	한 색만 있음	ans += 1
            }
            else {
                if (c>=d) ans += d;//c >= d	카드 수가 색 수보다 많음 → 사이클 있음
                else ans += (d-1); //c < d	카드 수가 부족함 → 트리 구조	ans += d - 1
            }
        }
    }
    cout<<ans;
}
/*#include <iostream>
#include <vector>
using namespace std;
const int MAX_COLOR = 1000000;

struct DSU {
    vector<int> parent;
    vector<int> size; // 각 집합의 노드 수
    // 각 대표(루트)별로 두 면의 색깔이 다른 카드(엣지)의 개수
    vector<int> edgeCount;
    // 각 대표별로 자기 루프(동일 색깔 카드)의 개수
    vector<int> selfCount;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        edgeCount.resize(n, 0);
        selfCount.resize(n, 0);
        for (int i=0;i<n;++i) parent[i] = i;
    }
    int find(int a) {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    // merge 두 집합을 합치고, edgeCount와 selfCount를 합산
    void unite(int a, int b, int extraEdge = 0) {
        a = find(a);
        b = find(b);
        if (a == b) {
            edgeCount[a] += extraEdge;
            return;
        }
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        edgeCount[a] += edgeCount[b] + extraEdge; // 새 카드 추가
        selfCount[a] += selfCount[b];
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<int> top(n), bottom(n);
    for (int i=0;i<n;++i) cin >> top[i];
    for (int i=0;i<n;++i) cin >> bottom[i];
    DSU dsu(MAX_COLOR + 1);
    vector<bool> used(MAX_COLOR + 1, false);
    for (int i=0;i<n;++i){
        int a = top[i], b = bottom[i];
        used[a] = true;
        used[b] = true;
        if (a == b) {
            int pa = dsu.find(a);
            dsu.selfCount[pa]++;
        }
        else {
            dsu.unite(a, b, 1);
        }
    }
    // 이제 DSU의 각 대표 집합별로 기여 가능한 최대 색깔 수를 계산
    // 각 연결 요소에서는 총 노드 수 d와 카드 수 c (= edgeCount + selfCount)가 있다.
    // 만약 카드 수 c >= d 라면, 모든 색깔 (d개) 를 윗면에 표시할 수 있고,
    // 그렇지 않으면 (트리 형태) d - 1개만 가능하다.
    long long answer = 0;
    for (int i=0;i<=MAX_COLOR;++i){
        if (dsu.find(i) == i && used[i]) {
            int d = dsu.size[i]; // 연결 요소에 속한 색깔의 수
            int c = dsu.edgeCount[i] + dsu.selfCount[i]; // 해당 연결 요소에 있는 카드 수
            // 연결 요소가 하나의 노드만 있을 때 (자기루프만 있는 경우)
            if(d==1) {
                // 적어도 한 장의 카드가 있어야 표시 가능, 카드가 있으면 1, 없으면 0
                // 여기 used[i]==true이면 반드시 카드가 존재함.
                answer += 1;
            }
            else {
                if(c >= d) answer += d;
                else answer += (d - 1);
            }
        }
    }
    cout<<answer;
}
*/