#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m,k,a,b;
int map[1002][1002],visited[1002][1002];
queue<pair<int,int>> q;
int dy[]={-1,0,1,1,0,-1}; //정육각형이므로 6방향 설정
int dx[]={1,1,1,0,-1,0};
void bfs(){
    q.push({0,0});
    visited[0][0] = true;
    while (!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int dir=0;dir<6;++dir){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (nx<0 || nx>=m || ny<0 || ny>=n || map[ny][nx]==-1) continue;
            if (!visited[ny][nx]){
                map[ny][nx] = map[y][x] + 1;
                q.push({ny,nx});
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    while (k--){
        cin>>a>>b;
        map[a][b]=-1;
    }
    bfs();
    cout<<map[n-1][m-1];
}