#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX 200000
/*
처음에 트리가 주어져 있고, (i) 간선 하나를 끊어라. (ii) 두 정점 u, v 사이에 경로가 존재하는지 알아내라.
당연히 N과 Q는 매우 커서 O(NQ) 같은 건 안 됨.
어떻게 생각해 봐도 빨리 풀 수는 없어 보이는데... 그럼 혹시 이런 문제는 풀 수 있나요?
처음엔 간선이 한 개도 없고, (i) 두 정점 u, v 사이에 간선을 만들어라. (ii) 두 정점 u, v 사이에 경로가 존재하는지 알아내라.
이건 풀 수 있습니다. 바뀐 것은 크게 쿼리 (i)인데, 끊는 것의 반대인 합치는 경우, 유니온 파인드를 사용해 양쪽 정점을 union해 가고,
(ii) 쿼리가 오면 두 정점이 같은 집합 안에 속하는지만 판단하면 됩니다. 따라서 총합 O(Qlog*N)의 시간에 해결됩니다.
오프라인 쿼리 : 쿼리를 입력받으면 바로 처리하는게 아니라 입력 다 받고 유리한 상태에서 풀기
*/
struct UnionFind {
    int uf[MAX];
    UnionFind() {fill(uf,uf+MAX,-1);}
    int find(int a) {
        if (uf[a]<0) return a;
        return uf[a] = find(uf[a]);
    }
    bool merge(int a,int b) {
        a = find(a);
        b = find(b);
        if (a==b) return false; //거꾸로 이어준 거니 순차적으로 진행하면 끊어지게 된 것이다.
        uf[b] = a;
        return true;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q,query[MAX*2][3],parent[MAX];
    cin>>n>>q;
    UnionFind arr;
    q += n-1;
    for (int i=1;i<n;++i) {
        cin>>parent[i];
        --parent[i]; //0-index
    }
    for (int i=0;i<q;++i) {
        cin>>query[i][0]>>query[i][1];
        --query[i][1];
        if (query[i][0]==1) {
            cin>>query[i][2];
            --query[i][2];
        }
    }
    stack<bool> res; //거꾸로 출력할거라 스택 사용
    for (int i=q-1;i>=0;--i) {
        if (query[i][0]==0) {
            arr.merge(query[i][1],parent[query[i][1]]); //반대로 묶음.
        }
        else {
            int u = arr.find(query[i][1]), v = arr.find(query[i][2]);
            res.push(u==v);
        }
    }
    while (!res.empty()) {
        if (res.top()) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
        res.pop();
    }
}