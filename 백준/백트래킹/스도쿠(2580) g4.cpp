#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[9][9],L;
vector<pair<int,int>> v;
bool flag = false;
bool check(int y,int x,int value){ //value가 가능한지 확인
  //위아래,좌우로 같은 값 있다면 불가능.
  for (int i=0;i<9;i++){
    if (map[i][x]==value) return false;
    if (map[y][i]==value) return false;
  }
  //3*3칸 안에 있으면 불가능
  int part_y = y / 3;
  int part_x = x / 3;
  part_x *= 3;
  part_y *= 3;
  for (int i = part_y; i < part_y + 3; i++) {
    for (int j = part_x; j < part_x + 3; j++) {
      if (map[i][j] == value) return false;
    }
  }
  return true;
}

void dfs(int cur){
  if (flag) return;
  if (cur==L){ //0인거 다 해결
    for (int i=0;i<9;i++){
      for (int j=0;j<9;j++){
        cout << map[i][j];
      }
      cout<<'\n';
    }
    flag = true;
  }
  else{
    int ny = v[cur].first;
    int nx = v[cur].second;
    for (int i=1;i<=9;i++){
      if (check(ny,nx,i)){
        map[ny][nx] = i;
        dfs(cur+1);
        //다시 초기화시켜주기(아닐 수도 있으므로)
        map[ny][nx] = 0;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i=0;i<9;i++){
    for (int j=0;j<9;j++){
      cin>>map[i][j];
      if (map[i][j]==0){
        v.push_back({i,j});
      }
    }
  }
  L = v.size(); //0이 있는 개수
  dfs(0);
}