#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int t;
string a,b;
ll n,m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while (t--) {
        cin>>a>>b;
        n = a.size();
        m = b.size();
        ll ans1 = stoll(a)*stoll(b);
        string ans2;
        if (m>n) {
            swap(a,b);
            swap(n,m); // 924 1736 -> 1736 924
        } // a가 더 긴 문자열
        int cur = 0;
        int diff = n-m;
        for (int i=0;i<n;++i) {
            if (cur<diff) {
                ans2 += a[i];
            }
            else {
                int a_tmp = a[i]-'0';
                int b_tmp = b[i-diff]-'0';
                ans2 += to_string(a_tmp*b_tmp);
            }
            ++cur;
        }
        if (to_string(ans1)==ans2) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
}