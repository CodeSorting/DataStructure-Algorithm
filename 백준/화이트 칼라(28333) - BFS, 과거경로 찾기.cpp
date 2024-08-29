#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

const int MAX = 1001, INF = 1e9;
int t,n,m,a,b;
vector<int> adj[MAX], pre[MAX]; // 인접 리스트, 과거 경로 찾기용 벡터
int visited[MAX];
set<int> ans;

void init(){ //초기화
  for (int i=0;i<MAX;++i){
    adj[i].clear();
    visited[i] = INF;
    pre[i].clear();
  }
  ans.clear();
}

void BFS(){
  queue<pair<int,int>> q;
  q.push({1,0});
  visited[1] = 0;
  while (!q.empty()){
    int cur = q.front().first;
    int cnt = q.front().second;
    q.pop();
    for (int i=0;i<adj[cur].size();++i){
      int next = adj[cur][i];
      if (visited[next]>cnt+1){
        visited[next] = cnt+1;
        pre[next].emplace_back(cur);
        q.push({next,cnt+1});
      }
      else if (visited[next]==cnt+1){
        pre[next].emplace_back(cur);
      }
    }
  }
}

void trace(int now,int cnt){ // 끝에서부터 과거 경로 찾기!!
  ans.insert(now);
  if (now==1){
    return;
  }

  for (int i=0;i<pre[now].size();++i){
    int next = pre[now][i];
    if (ans.find(next)==ans.end()){ // 안 찾아지면 넣기
      trace(next,cnt-1);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>t;
  while (t--){
    init();
    cin>>n>>m;
    while (m--){
      cin>>a>>b;
      adj[a].emplace_back(b);
    }
    BFS();
    trace(n,visited[n]);

    for (auto i : ans) {
      cout<<i<<" ";
    }
    cout<<"\n";
  }
}