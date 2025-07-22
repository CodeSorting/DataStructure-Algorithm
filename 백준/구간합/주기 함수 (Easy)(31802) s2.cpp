#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
/*
10(주기)
1(0~1) 2(1~2) 3(2~3) 1(3~4) 2(4~5) 3(5~6) 1(6~7) 2(7~8) 3(8~9) 1(9~10)
2 5 (3+1+2) = 6

hap
1(0~1) 3(0~2) 6(0~3) 7 9 12 13 15 18 19
*/
ll p;
ll A[100002],hap[100002];
ll a,b,ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>p;
    for (int i=0;i<p;++i) {
        cin>>A[i];
    }
    hap[0] = A[0];
    for (int i=1;i<p;++i) hap[i] = hap[i-1] + A[i];
    cin>>a>>b;
    if (a==b) { cout<<0; return 0; }
    if (b-a>=p) {
        ans += (b-a)/p * hap[p-1];
        a += (b-a)/p * p;
    }
    while (a<=0 || b<=0) {
        a += p;
        b += p;
    }
    for (int i=a;i<b;++i) {
        ans += A[i%p];
    }
    cout<<ans;
}