#include <iostream>
using namespace std;
typedef long long ll;

ll n,m=1;

int main() { //카드 수 적게, 사전순
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    while (n>m) {
        m <<= 1;
        ++m;
    }
    if (n==m) cout<<1<<'\n'<<n;
    else cout<<2<<'\n'<<(n^m)<<'\n'<<n;
}