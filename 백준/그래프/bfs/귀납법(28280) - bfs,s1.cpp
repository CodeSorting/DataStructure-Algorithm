#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int t,n,cnt;
bool visited[4000001];
void init() {
    for (int i=0;i<4000001;++i) {
        visited[i] = false;
    }
    cnt = -1;
}

void bfs(int n) {
    queue<pair<int,int>> q;
    q.push({1,0});
    visited[1] = true;
    while (!q.empty()) {
        int cur = q.front().first;
        int count = q.front().second;
        q.pop();

        if (cur==n) {
            cnt = count;
            return;
        }
        if ((cur<<1)<=4000001 && !visited[(cur<<1)]) {
            visited[(cur<<1)] = true;
            q.push({(cur<<1),count+1});
        }
        if (cur-1>=1 && !visited[cur-1]) {
            visited[cur-1] = true;
            q.push({cur-1,count+1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while (t--) {
        cin>>n;
        init();
        bfs(n);
        if (cnt==-1) cout<<"Wrong proof!"<<'\n';
        else cout<<cnt<<'\n';
    }
}