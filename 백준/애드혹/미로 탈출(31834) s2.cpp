#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,s,e;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while (t--) {
        cin>>n>>s>>e;
        if ((s==1 && e==n) || (s==n && e==1)) cout<<0<<'\n'; //1자로 이동하면 끝
        else if (1<s && s<n) { //e가 1이나 n
            if (abs(e-s)==1) cout<<1<<'\n';
            else cout<<2<<'\n';
        }
        else if (1<e && e<n) cout<<1<<'\n'; //s가 1이나 n
    }
}