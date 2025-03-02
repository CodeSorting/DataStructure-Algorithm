#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
총 3가지의 기능이 필요함.
1. n x n을 쓸 수 있는지 확인(check)
2. map을 nxn으로 업데이트하는 함수(update)
3. dfs로 가지치기하면서 찾기(dfs)
*/
int total = 0;
int map[11][11];
int paper[5] = {5,5,5,5,5};
int res = 101; //최댓값
vector<pair<int,int>> v;

bool check(int y,int x,int size){ //n x n을 쓸수 있는지 체크
  for (int i=0;i<=size;i++){
    for (int j=0;j<=size;j++){
      if (map[y+i][x+j] == 0) return false;
    }
  }
  return true;
}

void update(int y,int x,int s,int attached){ //n x n 종이로 업데이트
  for (int i=0;i<=s;i++){
    for (int j=0;j<=s;j++){
      map[y+i][x+j] = attached;
    }
  }
}

void dfs(int y,int x,int cnt){
  //1을 찾을 때 까지 증가
  while (map[y][x]==0){ //map이 전부 0이면 res 최신화(경우의 수 완료)
    x++;
    if (x>=10){
      y++;
      if (y>=10){
        res = min(res,cnt);
      }
      x=0;
    }
  }

  if (res<=cnt) return; //현재까지의 최솟값보다 크다면 더 살펴볼 필요가 없다.(가지치기)
  //모든 종이에 대하여 탐색
  for (int i=4;i>=0;i--){
    if (x+i>=10 || y+i>=10 || paper[i]==0) continue; //좌표 넘어가거나 그 종이 더이상 못 쓰면 가지치기
    if (check(y,x,i)){
      paper[i]--;
      update(y,x,i,0);
      dfs(y,x,cnt+1);
      //다시 돌려놓기
      paper[i]++;
      update(y,x,i,1);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i=0;i<10;i++){
    for (int j=0;j<10;j++){
      cin>>map[i][j];
      if (map[i][j]==1){
        total++; //덮어야할 1의 개수
      }
    }
  }
  if (total==0){ //예외처리
    cout<<0;
    return 0;
  }
  else if(total==10*10){ //예외처리
    cout<<4;
    return 0;
  }
  dfs(0,0,0);
  if (res==101){
    cout<<-1;
  }
  else{
    cout<<res;
  }
}