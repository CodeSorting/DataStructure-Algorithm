#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
//각 전봇대의 간격을 x라고 두고 거리 합을 f(x)로 하면 f(x)=|i*x-xi|의 합이다.
//x-x1 + 2x-x2 + 3x-x3...
const ll INF = 1e18;
ll n,x[100000];
ll f(int x0) {
    ll res = 0;
    for (ll i=1;i<n;++i) {
        res += abs(1LL*x0*i - x[i]);
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>x[i];
    }
    ll low=0,high=x[n-1];
    while (high-low>=3) {
        ll p = (low*2+high)/3,q = (low+high*2)/3;
        if (f(p)<=f(q)) high = q;
        else low = p;
    }
    ll res = INF;
    for (ll i=low;i<=high;++i) {
        res = min(f(i),res);
    }
    cout<<res;
}