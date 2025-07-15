#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> p;
bool cmp(p &a,p &b) {
    if (a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<p> v(n);
    for (int i=0;i<n;++i) cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.begin()+n,cmp);
    int cnt = 1;
    p cur = v[0];
    for (int i=1;i<n;++i) {
        if (cur.second<=v[i].first) {
            ++cnt;
            cur = v[i];
        }
    }
    cout<<cnt;
}
