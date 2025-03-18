#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,m;
ll arr[3];
ll power(ll a,ll b,ll c) {
    if (b==0) return 1;
    ll ret = power(a,b/2,c);
    if (b%2) return ret * ret % c * a % c;
    return ret * ret % c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n+1;++i) {
        cin>>arr[i];
    } // arr[2]^arr[1]^arr[0] mod m
    cin>>m;
    if (n==0) {
        cout<<arr[0] % m;
    }
    else if (n==1) {
        cout<<power(arr[1],arr[0],m);
    }
    else {
        if (arr[2]%m==0) { cout<<0; return 0;}
        ll x = power(arr[1],arr[0],m-1); //페르마의 소정리 이용
        cout<<power(arr[2],x,m);
    }
}
/*
arr2^arr1^arr0 계산하기 어려움.
페르마의 소정리인 a^m-1 = 1 mod m 이므로
x = (arr1^arr0) mod m-1로 지수를 줄인다.
arr2^(arr1^arr0 mod (m-1)) mod m
*/