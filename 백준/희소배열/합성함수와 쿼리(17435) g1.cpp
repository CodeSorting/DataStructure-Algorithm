#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int MAX = 500001;
const int MAX_D = 19; //2^k>=500000인 최소의 k

int M,Q,nxt[MAX][MAX_D];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>M;
  for (int i=1;i<=M;++i){
    cin>>nxt[i][0];
  }
  // 작은 j부터 배열을 채워가면서 전체 배열을 채울 수 있다.
  // i에서 2^(j+1)번 이동한 후의 정점은 i에서 2^j번*2번 이동하는 것
  // next[i][j+1] = next[ next[i][j] ][j]
  for (int j=1;j<MAX_D;++j){
    for (int i=1;i<=M;++i){
      nxt[i][j] = nxt[nxt[i][j-1]][j-1];
    }
  }

  cin>>Q;
  for (int i=0;i<Q;++i){
    int n,x;
    cin>>n>>x;
    for (int j=MAX_D-1;j>=0;--j){
      if (n >= 1<<j){
        n -= 1<<j;
        x = nxt[x][j];
      }
    }
    cout<<x<<'\n';
  }
}