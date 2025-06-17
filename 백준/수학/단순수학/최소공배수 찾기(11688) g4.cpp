#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a,ll b){ return a / gcd(a, b) * b; }
int main() { //11688
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,L;
    cin>>a>>b>>L;
    ll lcms = lcm(a,b);
    ll k = L/lcms;
    if (L%lcms!=0) {
        cout<<-1;
        return 0;
    }
    vector<ll> v;
    // 최소공배수의 소인수 구하기
    for (int i=1;i*i<=lcms;++i) { 
        if (lcms%i==0) {
            v.push_back(i);
            v.push_back(lcms/i);
        }
    }
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();++i) { //소인수마다 하나씩 해보기
        ll cur = k*v[i];
        //gcd(lcms,cur)가 그 약수 v[i]와 같아야만 lcm(a,b,cur)==L이 성립
        if (gcd(lcms,cur)==v[i]) {
            cout<<cur;
            return 0;
        }
    }
    cout<<-1;
}