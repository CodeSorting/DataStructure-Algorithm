#include <iostream>
#include <algorithm>
using namespace std;

int r,c;
char map[501][501]; // 걍 늑대 상하좌우를 울타리를 줘서 막아버리면 된다. 근데 배열 범위는 조심하고..
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
//S=양,W=늑대,.=빈칸,D=울타리
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>r>>c;
    for (int i=0;i<r;++i) {
        for (int j=0;j<c;++j) {
            cin>>map[i][j];
        }
    }
    for (int i=0;i<r;++i) {
        for (int j=0;j<c;++j) {
            if (map[i][j]=='.' || map[i][j]=='D' || map[i][j]=='S') continue;
            else if (map[i][j]=='W') {
                for (int dir=0;dir<4;++dir) {
                    int ny = i + dy[dir];
                    int nx = j + dx[dir];
                    if (ny<0 || nx<0 || ny>=r || nx>=c) continue;
                    if (map[ny][nx]=='S') { // 바로 한 칸 근처가 양일 경우
                        cout<<0; //불가능
                        return 0;
                    }
                    else if (map[ny][nx]=='.') {
                        map[ny][nx] = 'D';
                    }
                }
            }
        }
    }
    cout<<1<<'\n';
    for (int i=0;i<r;++i) {
        for (int j=0;j<c;++j) {
            cout<<map[i][j];
        }
        cout<<'\n';
    }
}