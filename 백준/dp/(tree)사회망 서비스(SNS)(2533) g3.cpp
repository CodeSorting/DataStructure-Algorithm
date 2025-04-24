#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000001
int n;
vector<int> adj[MAX];
int dp[MAX][2]; //0 = 얼리 어덥터, 1 = 일반인
bool visited[MAX];
void dfs(int cur) {
    visited[cur] = true;
    dp[cur][0] = 1;
    for (int i=0;i<adj[cur].size();++i) {
        int next = adj[cur][i];
        if (visited[next]) continue;
        dfs(next);
        dp[cur][1] += dp[next][0]; // 일반인의 경우 자식이 무조건 얼리어야함.
        dp[cur][0] += min(dp[next][0],dp[next][1]); // 얼리어덥터의 경우 자식 상관 없음.
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int u,v;
    for (int i=0;i<n;++i) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout<<min(dp[1][0],dp[1][1]);
}