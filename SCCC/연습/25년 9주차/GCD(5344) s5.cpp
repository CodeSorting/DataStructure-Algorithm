#include <iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b) {
    if (a%b==0) return b;
    return gcd(b,a%b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    while (n--) {
        ll a,b; cin>>a>>b;
        cout<<gcd(a,b)<<'\n';
    }
}