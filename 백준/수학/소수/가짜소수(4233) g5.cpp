#include <iostream>
using namespace std;
typedef long long ll;

ll power(ll a,ll b,ll c) {
    if (b==0) return 1;
    ll ret = power(a,b/2,c);
    if (b%2) return ret * ret % c * a % c;
    return ret * ret % c;
}
bool isPrime(ll a) {
    for (ll i=2;i*i<=a;++i) {
        if (a%i==0) return false; // 소수 x
    }
    return true; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        ll a,p;
        cin>>p>>a;
        if (a==0 && p==0) return 0;
        if (isPrime(p)) {
            cout<<"no"<<'\n'; // 대문자 써서 4번 틀림.
            continue;
        }
        ll res = power(a,p,p);
        if (res==a) cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';
    }
}