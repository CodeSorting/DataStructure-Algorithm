#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001
int n,r,q;
vector<ll> adj[MAX];
ll dp[MAX];
bool visited[MAX];
void dfs(int cur) {
    visited[cur] = true;
    for (int i=0;i<adj[cur].size();++i) {
        int next = adj[cur][i];
        if (visited[next]) continue;
        dfs(next);
        dp[cur] += dp[next];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>r>>q;
    for (int i=0;i<n-1;++i) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1;i<=MAX-1;++i) dp[i] = 1;
    dfs(r);
    for (int i=0;i<q;++i) {
        int query; cin>>query;
        cout<<dp[query]<<'\n';
    }
}