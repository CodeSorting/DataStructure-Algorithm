#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const ll MOD = 1e12;
ll n;
ll res=1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (ll i=1;i<=n;++i) {
        res *= i;
        while (res%10==0) { res /= 10; }
        res %= MOD;
    }
    res %= 100000;
    int k = to_string(res).size();
    if (k<5) {
        string res2 = "";
        res2 += (5-k) * '0';
        res2 += to_string(res);
        cout<<res2;
    }
    else cout<<res;
}