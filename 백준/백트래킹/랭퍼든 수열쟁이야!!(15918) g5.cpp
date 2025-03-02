#include <iostream>
using namespace std;
//(2≤n≤12, 1≤x<y≤2n, 1≤y-x-1≤n) n범위가 크지 않아 백트래킹 가능

int n,x,y,ans,arr[25];
bool visited[13];
void dfs(int idx){
  if (idx>n){ //n까지 해결했으면 ans++
    ans++;
    return;
  }
  if (visited[idx]) dfs(idx+1); //이미 방문(해결된것)했다면 다음거 탐색하기
  else{
    int r = 2*n-idx-1; //1~r 사이에 idx의 수가 있어야 한다.
    for (int i=1;i<=r;++i){ //1~r 사이 다 확인
      int temp = i+idx+1;
      if (!arr[i] && !arr[temp]){ //둘다 0이어야함.
        arr[i] = arr[temp] = idx;
        dfs(idx+1);
        arr[i] = arr[temp] = 0; //안되면 되돌리기
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>x>>y;
  arr[x]=arr[y]=y-x-1; //둘이 같은 수이니 반드시 이렇게 가야한다.
  visited[y-x-1] = true; //1~12수 중에 해당 수는 해결함.
  dfs(1); //백트래킹
  cout<<ans;
}