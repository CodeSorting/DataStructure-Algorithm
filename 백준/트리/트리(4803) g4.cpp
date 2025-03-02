#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m,st,ed,ans;
bool visited[501];
vector<int> tree[501];
bool flag;
bool DFS(int idx, int before){ //현재 인덱스, 전 노드
    visited[idx] = true;

    for(int i = 0; i < tree[idx].size(); i++){
        int next = tree[idx][i];
        if(next == before)  continue; // 바로 이전에 방문한 곳인 경우 pass

        if(visited[next]) return false;
        if(DFS(next, idx)==false) return false;
    }
    return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int count=0;
  while (true){
    cin>>n>>m;
    if (n==0 && m==0) break;
    for (int i=1;i<=500;i++){
      tree[i].clear();
    }
    memset(visited,false,sizeof(visited));
    ans=0;
    for (int i=0;i<m;i++){
      cin>>st>>ed;
      tree[st].push_back(ed);
      tree[ed].push_back(st);
    }
    
    flag = false;
    for (int i=1;i<=n;i++){
      if (!visited[i]){
        if (DFS(i,0)) ans++;
      }
    }
    count++; //출력
    cout << "Case " << count;
    if (ans==0) cout << ": No trees." << '\n';
    else if (ans==1) cout << ": There is one tree." << '\n';
    else cout << ": A forest of " << ans << " trees." << '\n';
  }
}