#include <iostream>
#include <vector>
using namespace std;

char map[6][6];
int n;
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
vector<pair<int,int>> emp;
vector<pair<int,int>> teacher;
bool isPossible = false;
bool watching(int y,int x) {
    for (int dir=0;dir<4;++dir) {
        int ny = y;
        int nx = x;
        while (nx>=0 && ny>=0 && ny<n && nx<n) {
            if (map[ny][nx]=='O') break;
            if (map[ny][nx]=='S') return false;
            ny += dy[dir];
            nx += dx[dir];
        }
    }
    return true;
}
void dfs(int cnt,int idx) {
    if (cnt==3) {
        for (pair<int,int> p : teacher) {
            if (!watching(p.first,p.second)) {
                return;
            }
        }
        isPossible = true;
        return;
    }
    for (int i=idx;i<emp.size();++i) {
        map[emp[i].first][emp[i].second] = 'O';
        dfs(cnt+1,i+1);
        map[emp[i].first][emp[i].second] = 'X';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            cin>>map[i][j];
            if (map[i][j]=='X') {
                emp.push_back({i,j});
            }
            else if (map[i][j]=='T') {
                teacher.push_back({i,j});
            }
        }
    }
    dfs(0,0);
    if (isPossible) cout<<"YES";
    else cout<<"NO";
}