#include <iostream> //플로이드 워셜
using namespace std;

bool dist[257][257];
int n,m,s,e;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  while (m--) {
    cin>>s>>e;
    dist[s][e] = true;
  }

  for (int k=1;k<=n;++k){
    for (int i=1;i<=n;++i){
      for (int j=1;j<=n;++j){
        if (dist[i][k] && dist[k][j]) dist[i][j] = true; //사이가 true면 둘이 이을 수 있다.
      }
    }
  }

  for (int i=1;i<=n;++i) {
    for (int j=1;j<=n;++j) {
      if (dist[i][j] && dist[j][i]){ //둘다 서로 앞에 있으면 모순(비교 불가능)
        cout<<-1;
        return 0;
      }
    }
  }

  for (int i=1;i<=n;++i){
    int l=1;
    int r=n;
    for (int j=1;j<=n;++j) {
        if (dist[i][j]) r--;
        else if (dist[j][i]) l++;
    }
    cout<<l<<' '<<r<<'\n';
  }
}
