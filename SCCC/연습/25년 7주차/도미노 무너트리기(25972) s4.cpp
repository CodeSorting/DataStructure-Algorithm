#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<p> v(n);
    for (int i=0;i<n;++i) cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    int cnt = 1;
    for (int i=0;i<n-1;++i) {
        p cur = v[i];
        if (cur.first+cur.second<v[i+1].first) ++cnt;
    }
    cout<<cnt;
}