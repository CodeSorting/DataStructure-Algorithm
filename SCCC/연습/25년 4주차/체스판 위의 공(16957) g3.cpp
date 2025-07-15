#include <iostream>
#include <algorithm>
using namespace std;

int r,c,arr[501][501];
int dy[] = {1,0,-1,0,1,-1,-1,1};
int dx[] = {0,1,0,-1,1,-1,1,-1};
int parent[501*501];
int ans[501*501];

int find(int a) {
    if (parent[a]==a) return a;
    return parent[a] = find(parent[a]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>r>>c;
    for (int i=0;i<r;++i) {
        for (int j=0;j<c;++j) {
            cin>>arr[i][j];
        }
    }
    for (int i=0;i<501*501;++i) {
        parent[i] = i;
    }
    for (int i=0;i<r;++i) {
        for (int j=0;j<c;++j) {
            int y = i;
            int x = j;
            for (int dir=0;dir<8;++dir) {
                int ny = i + dy[dir];
                int nx = j + dx[dir];
                if (ny>=r || nx>=c || ny<0 || nx<0) continue;
                if (arr[y][x]<arr[ny][nx]) continue;
                y = ny; //제일 작은 것으로 최신화
                x = nx; 
            }
            parent[i*c+j] = y*c+x;
        }
    }
    for (int i=0;i<r;++i) {
        for (int j=0;j<c;++j) {
            ans[find(i*c+j)] += 1;
        }
    }
    for (int i=0;i<r;++i) {
        for (int j=0;j<c;++j) {
            cout<<ans[i*c+j]<<' ';
        }
        cout<<'\n';
    }
}