#include <iostream>
using namespace std;
/*
3
2 0 1
1 2 0일때 2 0 1을 돌려서 0 1 2로 순서대로 맞추면 된다.
*/
int n,ans,P[49],S[49],order[49];
bool valid(){ //처음 i번째 위치에 있던 카드를 최종적으로 플레이어 P[i] 에게 보내야한다.
  for (int i=0;i<n;++i){
    if (P[order[i]]!= i%3) return false;
  }
  return true;
}

void move(){ //움직이기
  int tmp[48];
  for (int i=0;i<n;++i) tmp[S[i]] = order[i];
  for (int i=0;i<n;++i) order[i] = tmp[i];
}

void solve(int cycle){
  if (valid()){ //달성했다면 끝내기
    ans = cycle;
    return;
  }
  if (cycle>n*2550){
    ans = -1;
    return;
  }
  move();
  solve(cycle+1);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for (int i=0;i<n;++i) order[i] = i; //순서 배열. 계속 바뀜.
  for (int i=0;i<n;++i) cin>>P[i]; //맨 처음 i번째 위치에 있던 카드를 최종적으로 플레이어 P[i] 에게 보내야한다.
  for (int i=0;i<n;++i) cin>>S[i]; //섞는 방법 배열
  solve(0); //백트래킹으로 가지치기
  cout<<ans;
}