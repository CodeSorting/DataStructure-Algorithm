#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> p;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<vector<int>> v(n+1);
    int a,b;
    for (int i=0;i<n;++i) {
        cin>>a>>b;
        v[b].push_back(a);
    }
    long long ans = 0;
    for (int i=1;i<=n;++i) {
        if (v[i].size()<=1) continue;
        sort(v[i].begin(),v[i].end());
        for (int j=0;j<v[i].size();++j) {
            int left = (j > 0) ? v[i][j] - v[i][j - 1] : 1e9;
            int right = (j + 1 < v[i].size()) ? v[i][j + 1] - v[i][j] : 1e9;
            ans += min(left,right);
        }
    }
    cout<<ans;
}