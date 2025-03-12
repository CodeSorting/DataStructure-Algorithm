#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int n,m; //n차원, 점의 개수
ll dist;
ll arr[1000][1000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<m;++i) { 
        for (int j=0;j<n;++j) {
            cin>>arr[j][i];
        }
    }
    vector<ll> ans(n); // 맨해튼 거리는 합 / m이어야함.
    for (int i=0;i<n;++i) {
        sort(arr[i],arr[i]+m);
        ans[i] = arr[i][m/2];
        for (int j=0;j<m;++j) {
            dist += abs(arr[i][j]-ans[i]);
        } 
    }
    cout<<dist<<'\n';
    for (ll &x : ans) cout<<x<<' ';
}