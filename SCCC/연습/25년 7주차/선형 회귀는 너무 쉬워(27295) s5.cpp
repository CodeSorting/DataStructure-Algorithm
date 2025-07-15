#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,b,X,Y;
ll gcd(ll a,ll b) {
    if (a%b==0) return b;
    return gcd(b,a%b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>b;
    ll x,y;
    for (int i=0;i<n;++i) {
        cin>>x>>y;
        X += x; Y += y;
    }
    Y -= n*b; //(yi-b)의 합 구함. 이제 xi의 합을 나누면 됨.
    if (X==0) { //예외
        cout<<"EZPZ";
        return 0;
    }
    int sign = 1;
    if (X<0) { sign *= -1; X *= -1; }
    if (Y<0) { sign *= -1; Y *= -1; }
    if (Y%X==0) cout<<(Y/X)*sign;
    else {
        ll k = gcd(Y,X);
        Y /= k; X /= k;
        cout<<Y*sign<<'/'<<X;
    }
}