#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> p;

int a,b;
bool visited[1000001][2];
queue<pair<p,bool>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b;
    q.push({{a,0},false});
    visited[a][0] = true;
    while (!q.empty()) {
        int cur = q.front().first.first;
        int cnt = q.front().first.second;
        bool used = q.front().second;
        q.pop();
        if (cur==b) {
            cout<<cnt;
            return 0;
        }
        for (int i=0;i<3;++i) {
            if (i==0) {
                if (cur+1>b) continue;
                if (visited[cur+1][used]) continue;
                q.push({{cur+1,cnt+1},used});
                visited[cur+1][used] = true;
            }
            else if (i==1) {
                if (cur*2>b) continue;
                if (visited[cur*2][used]) continue;
                q.push({{cur*2,cnt+1},used});
                visited[cur*2][used] = true;
            }
            else if (i==2) {
                if (used) continue;
                if (cur*10>b) continue;
                if (visited[cur*10][used]) continue;
                q.push({{cur*10,cnt+1},true});
                visited[cur*10][used] = true;
            }
        }
    }
}