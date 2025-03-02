#include <iostream>
using namespace std;

int n,m,r;
int map[301][301];
int dy[] = {1,0,-1,0}; //하우상좌
int dx[] = {0,1,0,-1};
void rotate(int cnt) {
    for (int i=0;i<cnt;++i) { //회전 배열 수
        int st = map[i][i]; //왼쪽 위부터 시작
        int cy = i;
        int cx = i;
        int dir=0;
        while (dir<4) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if (ny==i && nx==i) break;
            if (ny>=i && nx>=i && ny<n-i && nx<m-i) {
                map[cy][cx] = map[ny][nx];
                cy = ny;
                cx = nx;
            }
            else ++dir;
        }
        map[i][i+1] = st;
    }
}

int main() { //카드 수 적게, 사전순
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>r;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            cin>>map[i][j];
        }
    }
    int cnt = min(n,m)/2;
    for (int i=0;i<r;++i) {
        rotate(cnt);
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
}