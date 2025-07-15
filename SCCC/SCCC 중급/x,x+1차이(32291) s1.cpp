#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>x;
    if (x==1) {
        cout<<1;
        return 0;
    }
    vector<ll> a;
    x += 1;
    for (ll i=1;i*i<=x;++i) {
        if (x%i==0) {
            a.push_back(i);
            a.push_back(x/i);
        }
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    if (a[a.size()-1]==x) a.pop_back();
    for (ll i=0;i<a.size();++i) {
        cout<<a[i]<<' ';
    }
}