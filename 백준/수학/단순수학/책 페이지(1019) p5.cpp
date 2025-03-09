#include <iostream>
using namespace std;
typedef long long ll;
ll check[10]; //0~9까지의 cnt배열
void plus_cnt(ll n,ll ten) {
    while (n>0) {
        check[n%10] += ten;
        n /= 10;
    }
}

void recur(ll a,ll b,ll ten) {
    // a는 일의 자리가 0이 되도록, b는 일의 자리가 9가 되도록 하면 계산이 편해진다.
    while (a%10!=0 && a<=b) {
        plus_cnt(a,ten);
        ++a;
    }
    if (a>b) return;
    while (b%10!=9 && b>=a) {
        plus_cnt(b,ten);
        --b;
    }
    ll cnt = (b/10-a/10+1); // b-a+1 * 자리수만큼 0~9에 더해준다.
    for (int i=0;i<10;++i) check[i] += cnt*ten;
    recur(a/10,b/10,ten*10);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    recur(1,n,1);
    for (int i=0;i<10;++i) cout<<check[i]<<' ';
}