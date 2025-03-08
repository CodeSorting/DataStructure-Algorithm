#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
/*
1. 빙산이 두 덩이 이상으로 나뉘었는지, 빙산이 다 녹아 없어졌는지
2. 1년 마다 빙산의 인접한 칸에 0의 개수만큼 빙산의 높이를 줄이기
*/
int map[301][301];
int tmp[301][301];
bool visited[301][301];
int n,m; //행,열
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void check(int i,int j){ //큰 빙하가 몇 덩어리인지 체크한다.
  queue<pair<int,int>> q;
  q.push({i,j});
  while (!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for (int i=0;i<4;i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny<0 || nx<0 || ny>=n || nx>=m) continue;
      if (map[ny][nx] != 0 && !visited[ny][nx]){
        q.push({ny,nx});
        visited[ny][nx] = true;
      }
    }
  }
}
void meltice(){ //빙하 녹이기
  memset(tmp, 0, sizeof(tmp));

  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      if (map[i][j] == 0) continue;
      int water = 0;
      for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (map[nx][ny] == 0) {
          water++;
        }
      }
      int val = map[i][j] - water;
      if (val > 0) tmp[i][j] = val;
    }
  }

  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      map[i][j] = tmp[i][j];
    }
  }
} 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin>>map[i][j];
    }
  }
  int time=0;
  while (true){
    int cnt=0;
    for (int i=0;i<n;i++){
      for (int j=0;j<m;j++){
        if (!visited[i][j] && map[i][j] != 0){
          check(i,j);
          cnt++;
        }
      }
    }
    if (cnt==0){ //결국 안 나눠지면 0 출력
      cout<<0;
      break;
    }
    if (cnt>=2){ //2덩어리 이상으로 나눠지면 바로 출력
      cout<<time;
      break;
    }
    time++;
    meltice();
    memset(visited,false,sizeof(visited));
  }
}