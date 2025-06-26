#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
char board[11][11];
bool visited[11][11][11][11];
// 빨간 구슬, 파란 구슬, 구멍 위치
int ry, rx, by, bx, oy, ox;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
struct State {
    int ry, rx, by, bx, moves;
};
// (y, x) 구슬을 dir 방향으로 기울였을 때 최종 위치와 이동 칸 수를 cnt에 반환
void tilt(int &y, int &x, int dir, int &cnt) {
    cnt = 0;
    // 벽('#') 만나거나 구멍('O')에 빠질 때까지 이동
    while (board[y + dy[dir]][x + dx[dir]] != '#' && board[y][x] != 'O') {
        y += dy[dir];
        x += dx[dir];
        cnt++;
        if (board[y][x] == 'O') break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            cin>>board[i][j];
            if (board[i][j] == 'R') {
                ry = i; rx = j;
                board[i][j] = '.';
            }
            if (board[i][j] == 'B') {
                by = i; bx = j;
                board[i][j] = '.';
            }
            if (board[i][j] == 'O') {
                oy = i; ox = j;
            }
        }
    }
    queue<State> q;
    visited[ry][rx][by][bx] = true;
    q.push({ry, rx, by, bx, 0});
    while (!q.empty()) {
        State cur = q.front(); 
        q.pop();
        // 10회 이상 기울였으면 더 이상 진행 불가
        if (cur.moves >= 10) continue;
        for (int dir=0;dir<4;++dir) {
            int nry = cur.ry, nrx = cur.rx, rcnt;
            int nby = cur.by, nbx = cur.bx, bcnt;
            // 빨간 구슬, 파란 구슬 각각 기울이기
            tilt(nry, nrx, dir, rcnt);
            tilt(nby, nbx, dir, bcnt);
            // 파란 구슬이 구멍에 빠지면 실패
            if (board[nby][nbx] == 'O') continue;
            // 빨간 구슬만 구멍에 빠지면 성공
            if (board[nry][nrx] == 'O') {
                cout<<cur.moves + 1;
                return 0;
            }
            // 두 구슬이 같은 칸에 겹쳤다면, 더 많이 이동한 쪽을 한 칸 뒤로
            if (nry == nby && nrx == nbx) {
                if (rcnt > bcnt) {
                    nry -= dy[dir];
                    nrx -= dx[dir];
                } else {
                    nby -= dy[dir];
                    nbx -= dx[dir];
                }
            }
            // 새로운 상태라면 큐에 추가
            if (!visited[nry][nrx][nby][nbx]) {
                visited[nry][nrx][nby][nbx] = true;
                q.push({nry, nrx, nby, nbx, cur.moves + 1});
            }
        }
    }
    cout<<-1;
}
