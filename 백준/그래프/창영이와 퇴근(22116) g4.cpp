#include <iostream>
#include <algorithm>//22116
#include <vector>
#include <queue>
#include <climits>
#include <tuple>
using namespace std;
typedef long long ll;
typedef tuple<ll,int,int> t;
int n;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int arr[1001][1001];
int dist[1001][1001];
int INF;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            cin>>arr[i][j];
        }
    }
    priority_queue<t,vector<t>,greater<t>> pq; //오름차순 우선순위큐
    if (n==1) { cout<<0<<'\n'; return 0; }
    ll ans = 0;
    for (int i=0;i<1001;++i) 
        for (int j=0;j<1001;++j)
            dist[i][j] = INT_MAX;
    INF = INT_MAX;
    dist[0][0] = 0;
    pq.push(make_tuple(abs(arr[0][0]-arr[0][1]),0,1));
    pq.push(make_tuple(abs(arr[0][0]-arr[1][0]),1,0));

    while (!pq.empty()) {
        t cur = pq.top();
        ll num = get<0>(cur);
        int y = get<1>(cur);
        int x = get<2>(cur);
        pq.pop();
        if (dist[y][x]!=INF) continue;
        dist[y][x] = num;
        ans = max(ans,num);
        if (y==n-1 && x==n-1) break;
        for (int i=0;i<4;++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny<0 || nx<0 || ny>=n || nx>=n) continue;
            if (dist[ny][nx]!=INF) continue;
            pq.push(make_tuple(abs(arr[y][x]-arr[ny][nx]),ny,nx));
        }
    }
    cout<<ans;
}