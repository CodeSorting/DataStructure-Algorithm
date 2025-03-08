#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
/*
중요한점 : 수빈이가 짝수초에 접근한 위치는 짝수초에 또 방문할 수 있고
홀수초에 접근한 위치는 홀수초에 또 방문할 수 있다.
몇초에 해당 위치를 최초에 방문했는지 아는게 중요하다.
ex) 수빈이가 14초에 x에, 동생은 20초에 x를 방문했다 하자.
수빈이는 -1,1,x2로 이동가능하니 15초에 x-1,16초에 x로 다시 돌아올 수 있다.
계속 이렇게 반복하면 결국 20초에 만날 수 있다. (%2를 하고 sec를 반환하는 이유이다.)
*/
int st,ed;
bool visited[500001][2];
int getpos(int pos,int opt){
  if (opt==0) return pos-1;
  else if (opt==1) return pos+1;
  else return pos*2;
}
int bfs(){
  queue<pair<int,int>> q;
  q.push({st,0});

  memset(visited,false,sizeof(visited));
  visited[st][0]=true;

  while (!q.empty()){
    int cur = q.front().first;
    int sec = q.front().second;
    q.pop();

    int brothercur = ed + sec*(sec+1)/2; //동생의 이동거리
    if (brothercur>500000) return -1; //좌표가 500000 이내여야한다.
    if (visited[brothercur][sec%2]) return sec; //도달했다면 sec를 반환한다.
    ++sec;
    for (int opt=0;opt<3;opt++){
      int next = getpos(cur,opt);
      if (next<0 || next>500000) continue;
      if (visited[next][sec%2]) continue;
        visited[next][sec%2]=true;
      q.push({next,sec});
    }
  }
  return -1; //결구 안되었을 경우
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>st>>ed;
  cout<<bfs();
}