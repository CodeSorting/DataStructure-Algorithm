#include <iostream>
#include <algorithm>
using namespace std;

int n,m,arr[8];
int res[8];
void dfs(int depth){
  if (depth==m){
    for (int i=0;i<m;++i){
      cout<<res[i]<<' ';
    }
    cout<<'\n';
    return;
  }
  int check = -1; //같은 수 거르기용
  //4 4 /1 1 2 2에서
  //1111 -> depth 4일때 return되면 111인상태에서 1이 아닌 2가 발생하여 1112가됨.
  for (int i=0;i<n;++i){
    if (check==arr[i]) continue; 
    check = arr[i];
    res[depth] = arr[i];
    dfs(depth+1);
    res[depth] = -1; //백트래킹
  }
  return;
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