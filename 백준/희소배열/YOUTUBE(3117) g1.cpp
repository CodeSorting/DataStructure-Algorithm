#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N,K,M,dp[100001][30]; //학생수,동영상수,남은 수업시간

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>N>>K>>M;
  M--;
  vector<int> v(N);
  for (int i=0;i<N;++i){
    cin>>v[i];
  }
  for (int i=1;i<=K;++i){
    cin>>dp[i][0]; //2 3 4 1 4 5
  }
  // 작은 j부터 배열을 채워가면서 전체 배열을 채울 수 있다.
  // i에서 2^(j+1)번 이동한 후의 정점은 i에서 2^j번*2번 이동하는 것
  // dp[i][j+1] = dp[ dp[i][j] ][j]
  for (int j=1;j<30;++j){
    for (int i=1;i<=K;++i){
      dp[i][j] = dp[dp[i][j-1]][j-1];
    }
  }
  for (int i : v){
    int a = i,b = M;
    for (int j=29;j>=0;--j){ //M(남은시간)이 0이 될때까지
      if (b>=1<<j){
        a = dp[a][j];
        b -= 1<<j;
      }
    }
    cout<<a<<' ';
  }
}
