#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int a,b,n,m;
bool visited[100001];
queue<pair<int,int>> q;
int dir[8];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>a>>b>>n>>m;
    visited[n] = true; // n->m으로 a,b스카이콩콩이용
    q.push({n,0});
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cur==m) {
            cout<<cnt;
            return 0;
        }
        dir[0] = cur-1;
        dir[1] = cur+1;
        dir[2] = cur+a;
        dir[3] = cur+b;
        dir[4] = cur-a;
        dir[5] = cur-b;
        dir[6] = cur*a;
        dir[7] = cur*b;
        for (int i=0;i<8;++i) {
            int next = dir[i];
            if (next<0 || next>100000) continue;
            if (visited[next]) continue;
            visited[next] = true;
            q.push({next,cnt+1});
        }
    }
}