#include <iostream>
using namespace std;
typedef long long ll;
ll n;
ll a,b,a2,b2;
/*
a=1 b=1~20일 때
1 3 0 4
1 7 0 8 
1 11 0 12
1 15 0 16
1 19 0 20

a=2 b=2~21일 때
2 1 5 0 
6 1 9 0 
10 1 13 0
14 1 17 0
18 1 21 0
*/
ll trans(ll num) {
    int mod = num%4;
    if (mod==0) return num;
    else if (mod==1) return 1;
    else if (mod==2) return num+1;
    else return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while (n--) {
        cin>>a>>b;
        --a;
        a2 = trans(a);
        b2 = trans(b);
        cout<<(a2^b2)<<'\n'; //1~b2까지 구한 것과 1~a2를 구한것을 XOR 해준다.
        //즉, (1^2^3^4^5) ^ (1^2) = 교환법칙,결합법칙이 성립하므로 1^1,2^2가 서로 사라짐.
    }
}