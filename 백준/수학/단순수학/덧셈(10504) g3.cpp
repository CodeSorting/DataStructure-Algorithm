#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while (t--) {
        ll n; cin>>n;
        bool found = false;
        //2n=k(2a+k−1) = 2ak + k(k-1) 따라서 a = (2n-k(k-1)) / 2k 이다.
        for (ll k=2;k*(k+1)/2<=n;++k) {
            ll num = 2*n-k*(k-1);
            if (num%(2*k) != 0) continue; 

            ll a = num/(2*k);
            if (a >= 1) {
                found = true;
                cout<<n<<" = ";
                for (ll i=0;i<k;++i) {
                    cout<<(a + i);
                    if (i != k - 1) cout<<" + ";
                }
                cout<<'\n';
                break; //가장 짧은 것만 출력
            }
        }
        if (!found) cout<<"IMPOSSIBLE\n";
    }
}
