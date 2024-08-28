#include <iostream>
#include <vector>
using namespace std;
// 타일 선택 : 가장 위쪽 그리고 왼쪽이 기준
// 덮는 방법 : 4가지 x 3칸 x (y, x)
const int coverType[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}}, //「
    {{0, 0}, {0, 1}, {1, 1}}, //ㄱ
    {{0, 0}, {1, 0}, {1, 1}}, //ㄴ
    {{0, 0}, {1, 0}, {1, -1}} //」
};

// board의 (y, x)를 type번 방법으로 덮거나, 덮었던 블록을 없앤다
// delta가 1이면 덮고, -1이면 덮었던 블록을 없앤다
// 게임판 밖으로 나가거나, 겹치거나, 검은 칸을 덮을 때 false 반환
bool set(vector<vector<int>>& board, int y, int x, int type, int delta) {
  bool ok = true;
  for (int i = 0; i < 3; i++) {
    const int ny = y + coverType[type][i][0];
    const int nx = x + coverType[type][i][1];
    if (ny < 0 || ny >= (int)board.size() || nx < 0 || nx >= (int)board[0].size()) {
      ok = false;
    } else if ((board[ny][nx] += delta) > 1) {
      ok = false;
    }
  }
  return ok;
}

// board의 모든 빈 칸을 덮을 수 있는 방법의 수를 반환
// board[i][j] = 1 이미 덮인 칸 혹은 검은 칸
// board[i][j] = 0 아직 덮이지 않은 칸
int cover(vector<vector<int>> &board) {
  // 아직 채우지 못한 칸 중 가장 윗줄 왼쪽에 있는 칸을 찾는다
  int y = -1, x = -1;
  for (int i = 0; i < (int)board.size(); i++) {
    for (int j = 0; j < (int)board[i].size(); j++) {
      if (board[i][j] == 0) { // 아직 채우지 못한 칸 찾음
        y = i;
        x = j;
        break;
      }
    }
    if (y != -1) break;
  }
  // 기저 사례: 모든 칸을 채웠으면 1을 반환
  if (y == -1) return 1;

  int ret = 0;
  for (int type = 0; type < 4; type++) {
    // 만약 board[y][x]를 type 형태로 덮을 수 있으면 재귀 호출
    if (set(board, y, x, type, 1)) {
      ret += cover(board);
    }
    // 덮었던 블록을 치운다
    set(board, y, x, type, -1);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int testCase, H, W;
  char bw[20]; 
  cin >> testCase;
  for (int t = 0; t < testCase; t++) {
    cin >> H >> W;
    vector<vector<int>> board(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
      cin >> bw;
      for (int j = 0; j < W; j++) {
        board[i][j] = (bw[j] == '#') ? 1 : 0;
      }
    }
    cout<<cover(board)<<'\n';
  }
}