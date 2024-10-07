#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std; //22352 항체인식

int map1[31][31]; //주사놓은 곳을 map2로 값을 놓고 그 주변 공간을 map2와 같은 값이 되게 한다.
int map2[31][31]; //그런 다음 map2와 비교하면서 다른 값을 찾는다.
bool visited[31][31];
int n,m;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
bool impossible = false;
void bfs(int i,int j,int bef,int aft) {
    queue<pair<int,int>> q;
    q.push({i,j});
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        visited[y][x] = true;
        for (int dir=0;dir<4;++dir) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (nx<0 || ny<0 || ny>=n || nx>=m) continue;
            if (!visited[ny][nx]) {
                if (map1[ny][nx]==bef) {
                    map1[ny][nx] = aft;
                    q.push({ny,nx});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            cin>>map1[i][j];
        }
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            cin>>map2[i][j];
        }
    }
    bool injected = false;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            if (!injected && map1[i][j]!=map2[i][j]) {
                bfs(i,j,map1[i][j],map2[i][j]);
                map1[i][j] = map2[i][j];
                injected = true;
            }
        }
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            if (map1[i][j]!=map2[i][j]) {
                impossible = true;
                break;
            }
        }
    }
    if (impossible) cout<<"NO";
    else cout<<"YES";
}