#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
typedef long double ld;

int n;
ld w[4];
bool visited[30][30];
int dx[] = {1,-1,0,0}; //동서남북
int dy[] = {0,0,-1,1};
ld backtrack(int y,int x,ld p,int cnt){
  if (cnt==n || p==0) return p; //모두 이동 or 확률 0
  ld sum = 0; //동서남북의 총 확률
  for (int i=0;i<4;i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (visited[ny][nx]) continue;
    visited[ny][nx] = true;
    sum += backtrack(ny,nx,p*w[i],cnt+1);
    visited[ny][nx] = false;
  }
  return sum;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for (int i=0;i<4;i++){
    cin>>w[i];
    w[i] /= 100; //확률
  }
  visited[15][15] = true;
  cout.precision(13);
  cout<<backtrack(15,15,1,0);
}