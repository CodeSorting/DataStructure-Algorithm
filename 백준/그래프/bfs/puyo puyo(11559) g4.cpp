#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char map[12][6];
bool visited[12][6];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int res=0,cnt;

void down(){
  for (int i=0;i<6;i++){ //열
    int tmp=11;
    for (int j=11;j>=0;j--){ //행
      if (map[j][i]!='.'){
        if (j!=tmp){
          map[tmp][i] = map[j][i];
          map[j][i] = '.';
        }
        tmp--;
      }
    }
  }
}

bool bfs(int i,int j,char c){ //좌표,해당 char
  queue<pair<int,int>> q;
  vector<pair<int,int>> v;
  memset(visited,false,sizeof(visited));

  q.push({i,j});
  visited[i][j] = true;
  v.push_back({i,j});

  while (!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for (int dir=0;dir<4;dir++){
      int ny = y + dy[dir];
      int nx = x + dx[dir];
      if (nx<0 || nx>=6 || ny<0 || ny>=12 || visited[ny][nx]) continue;
      if (map[ny][nx]==c){
        q.push({ny,nx});
        v.push_back({ny,nx});
        visited[ny][nx] = true;
      }
    }
  }
  if (v.size()>=4){//4개 이상이면 터트린다.
    for (int i=0;i<v.size();i++){
      map[v[i].first][v[i].second] = '.';
    }
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i=0;i<12;i++){
    for (int j=0;j<6;j++){
      cin>>map[i][j];
    }
  }
  while (true){
    cnt=0;
    for (int i=0;i<12;i++){
      for (int j=0;j<6;j++){
        if (map[i][j]!='.'){
          if (bfs(i,j,map[i][j])) cnt++;
        }
      }
    }
    if (cnt==0) break;
    else{
      res++;
      down();
    }
  }
  if (res) cout<<res;
  else if (res==0) cout<<0;
}