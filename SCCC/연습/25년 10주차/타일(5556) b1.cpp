#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,k,a,b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for (int i=0;i<k;++i) {
        cin>>a>>b;
        ll m = min(min(a,b),min(n-a+1,n-b+1));
        m %= 3;
        if (m!=0) cout<<m<<'\n';
        else cout<<3<<'\n';
    }
}