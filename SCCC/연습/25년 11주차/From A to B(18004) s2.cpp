#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a,b; cin>>a>>b;
    if (a<=b) {
        cout<<b-a;
        return 0;
    }
    int cnt = 0;
    while (a>b) {
        ++cnt;
        if (a%2) ++a;
        else a /= 2;
    }
    cnt += (b-a);
    cout<<cnt;
}