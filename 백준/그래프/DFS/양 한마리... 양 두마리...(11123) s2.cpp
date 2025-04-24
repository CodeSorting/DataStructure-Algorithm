#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int h,w;
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
char arr[101][101];
bool visited[101][101];
int cnt = 0;
void dfs(int y,int x) {
    visited[y][x] = true;
    for (int i=0;i<4;++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny>=h || nx>=w || ny<0 || nx<0) continue;
        if (!visited[ny][nx] && arr[ny][nx]=='#') {
            visited[ny][nx] = true;
            dfs(ny,nx);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--) {
        memset(visited,0,sizeof(visited));
        cnt = 0;
        cin>>h>>w;
        for (int i=0;i<h;++i) {
            for (int j=0;j<w;++j) {
                cin>>arr[i][j];
            }
        }
        for (int i=0;i<h;++i) {
            for (int j=0;j<w;++j) {
                if (arr[i][j]=='#') {
                    if (!visited[i][j]) {
                        dfs(i,j);
                        cnt++;
                    }
                }
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}