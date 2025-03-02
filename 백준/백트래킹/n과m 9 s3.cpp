#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,arr[8],res[8];
bool visited[8];
void dfs(int cnt){
  if (cnt==m){ // 조건만족시
    for (int i=0;i<m;++i){
      cout<<res[i]<<' ';
    }
    cout<<'\n';
    return;
  }

  int tmp=0;
  for (int i=0;i<n;++i){
    if (!visited[i] && arr[i]!=tmp){ // 방문 x, 중복 x
      res[cnt] = arr[i];
      tmp = res[cnt];
      
      visited[i] = true; 
      dfs(cnt+1);
      visited[i] = false; // 백트래킹
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  for (int i=0;i<n;++i){
    cin>>arr[i];
  }
  sort(arr,arr+n);
  dfs(0);
}