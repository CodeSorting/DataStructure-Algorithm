#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> P;

int n,k;
int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };
int map[2001][2001];
int parent[100001];
void Union(int a,int b);
int find(int a);
void merge_city(); //도시가 인접해있고 부모가 다르다면 결합한다.
void bfs(); //bfs로 상하좌우 이동

queue<P> q; //bfs용 큐
queue<P> city;//도시 합치기 위한 큐

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>k;
  for(int i=1;i<=k;++i){
    int x,y;
    cin>>x>>y;
    map[y][x] = i; //초기 문명도시 번호를 1,2,3...으로 잡아둠
    city.push({y,x});
  }
  for(int i=1;i<=k;++i) parent[i] = i; //일단 부모는 자기자신으로 초기화

  int time=0;
  while(k>1){
    merge_city(); //도시 합쳐봄
    if (k==1){
      cout<<time;
      break;
    }
    bfs();
    time++;
  }
}

void merge_city(){
  while (!city.empty()){
    int y = city.front().first;
    int x = city.front().second;
    q.push({y,x}); //큐에 넣는다.
    city.pop();
    for (int i=0;i<4;i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      int now = map[y][x];
      int next = map[ny][nx];
      if (nx<1 || nx>n || ny<1 || ny>n) continue;
      if (map[ny][nx]!=0){
        if (now!=next && find(now)!=find(next)){
          Union(now,next); //문명이 같지 않다면 합치고 k감소
          k--;
        }
      }
    }
  }
}

void bfs(){
  while (!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for (int i=0;i<4;i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (nx<1 || nx>n || ny<1 || ny>n) continue;
      if (map[ny][nx]==0){
        map[ny][nx]=map[y][x]; //초기 문명 도시 번호를 따라간다.
        city.push({ny,nx});
      }
    }
  }
}

int find(int a){
  if (parent[a] == a) return a;
  else return parent[a] = find(parent[a]);
}

void Union(int a,int b){
  a = find(a);
  b = find(b);
  if (a!=b){
    parent[a] = b;
  }
}