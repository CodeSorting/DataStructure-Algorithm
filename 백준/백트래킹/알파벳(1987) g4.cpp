#include <iostream>
#include <algorithm>
using namespace std;

int R,C,res=0;
char map[20][20];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
bool visited[20][20], used[26];
void backtrack(int r,int c,int dist){
  res = max(res,dist);
  visited[r][c] = true;
  used[map[r][c]-'A'] = true;
  for (int dir=0;dir<4;dir++){
    int nr = r+dr[dir];
    int nc = c+dc[dir];
    if(nr<0 || nr>=R || nc<0 || nc>=C || visited[nr][nc]) continue;
    if(!used[map[nr][nc]-'A']) backtrack(nr, nc, dist+1);
  }
  //방문 전 상황으로 되돌림(백트래킹의 중요한점이다.)
  visited[r][c] = false;
  used[map[r][c]-'A'] = false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>R>>C;
  for (int i=0;i<R;i++){
    for (int j=0;j<C;j++){
      cin>>map[i][j];
    }
  }
  backtrack(0,0,1);
  cout<<res;
}