#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
    if (b==0) return a;
    return gcd(b,a%b);
}
//약수의 개수가 홀수개 = 완전제곱수
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a,b;
    cin>>a>>b;
    int squareCount = 0;
    for (ll i=sqrt(a);i*i<=b;++i) {
        if (i*i>a) squareCount += 1;
    }
    if (!squareCount) cout<<0;
    else {
        ll gcdValue = gcd(b-a,squareCount);
        cout<<squareCount/gcdValue<<"/"<<(b-a)/gcdValue;
    }
}