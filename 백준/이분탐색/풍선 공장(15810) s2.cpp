#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll n,m;
bool isPossible(ll mid,vector<ll> &v) {
    ll sum = 0;
    for (int i=0;i<n;++i) {
        sum += mid/v[i];
    }
    if (sum>=m) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    vector<ll> v(n);
    for (int i=0;i<n;++i) {
        cin>>v[i];
    }
    ll left = 1, right = 1e15,res = 1e15;
    while (left<=right) {
        ll mid = (left+right)/2;
        if (isPossible(mid,v)) {
            res = mid;
            right = mid-1;
        }
        else {
            left = mid+1;
        }
    }
    cout<<res;
}