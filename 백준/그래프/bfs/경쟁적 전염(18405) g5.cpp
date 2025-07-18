#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Virus {
    int type, time, y, x;
};
int n,k,s,x,y;
int map[201][201];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
bool cmp(Virus &a,Virus &b) {
    return a.type < b.type;
}
void bfs(vector<Virus> &v) {
    queue<Virus> q;
    for (int i=0;i<v.size();++i) q.push(v[i]);
    while (!q.empty()) {
        int cur_type = q.front().type;
        int cur_time = q.front().time;
        int cy = q.front().y;
        int cx = q.front().x;
        q.pop();
        if (cur_time==s) return;
        for (int i=0;i<4;++i) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 1 || ny > n || nx < 1 || nx > n) continue;
            if (map[ny][nx]) continue;
            map[ny][nx] = cur_type;
            q.push({cur_type,cur_time+1,ny,nx});
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    vector<Virus> v;
    int a,b,c;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            cin>>map[i][j];
            if (map[i][j]) v.push_back({map[i][j],0,i,j});
        }
    }
    cin>>s>>y>>x;
    sort(v.begin(), v.end(), cmp);
    bfs(v);
    cout<<map[y][x];
}