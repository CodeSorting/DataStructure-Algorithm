#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,m; //건물, 도로 개수 (노드, 간선)
ll adj[101][101]; //인접 행렬
//플로이드 워셜 이용
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if (i==j) adj[i][j]=0;
            else adj[i][j]=1e17; //무한대
        }
    }
    int a,b;
    for (int i=0;i<m;++i) {
        cin>>a>>b;
        adj[a][b] = 1;
        adj[b][a] = 1; //양방향 도로    
    }
    for (int k=1;k<=n;++k) {
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    ll ans = 1e17,node1 = 1,node2 = 1;
    for (int i=1;i<=n;++i) {
        for (int j=i+1;j<=n;++j) {
            int cur1 = i, cur2 = j;
            ll Sum = 0;
            for (int k=1;k<=n;++k) {
                if (k==cur1 || k==cur2) continue; // 현재 노드 제외
                ll dist = min(adj[k][cur1] + adj[cur1][k],adj[k][cur2] + adj[cur2][k]);
                Sum += dist;
            }
            if (ans > Sum) {
                ans = Sum;
                node1 = cur1;
                node2 = cur2;
            }
        }
    }
    if (node1>node2) cout<<node1<<" "<<node2<<" "<<ans<<"\n";
    else cout<<node2<<" "<<node1<<" "<<ans<<"\n";
}