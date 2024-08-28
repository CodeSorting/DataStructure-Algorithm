#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n,m,t,x,y;
bool areFriends[10][10]; //친구를 나타내는 2차원 배열
int countParings(bool taken[10]){
  int firstFree = -1; //남은 학생들 중 가장 번호가 빠른 학생을 찾는다.
  for (int i=0;i<n;++i){
    if (!taken[i]){
      firstFree = i;
      break;
    }
  }
  //기저 사례 : 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
  if (firstFree==-1) return 1;
  int ret = 0;
  for (int p=firstFree+1;p<n;++p){
    if (!taken[p] && areFriends[firstFree][p]){
      taken[firstFree] = taken[p] = true;
      ret += countParings(taken);
      taken[firstFree] = taken[p] = false;
    }
  }
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>t;
  while (t--){
    cin>>n>>m;
    bool taken[10];
    memset(taken,0,sizeof(taken));
    memset(areFriends,0,sizeof(areFriends));
    for (int i=0;i<m;++i){
      cin>>x>>y;
      areFriends[x][y] = true;
      areFriends[y][x] = true;
    }
    cout<<countParings(taken)<<'\n';
  }
}