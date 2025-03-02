#include <iostream>
using namespace std;
typedef long long ll;

ll l,r,k; //l~r(자연수) 사이의 첫 k개의 항 k는 2~5이다.
/*
x,x+d,x+2d..x+(k-1)d x,d도 자연수
합 = k(2x + (k-1)d)/2
k가 홀수라면 합은 중간항 x k개다.
l<중간항xk<r이다.
k=3일 때 l<3(x+d)<r 즉 6이상의 3의 배수
k=5일 때 l<5(x+2d)<r 즉 15이상의 5의 배수
k가 짝수라면
k=2일 때 l<2x+d<r 즉 3이상의 자연수
k=4일 때 l<4x+6d<r 즉 10 이상이긴 함.
10 16 22
14 20 26
18 24 30
22 28 34
... 
10~14 사이에는 2의 배수에서 1개가 빠짐.
14 이상부터는 2의 배수
*/
ll max(ll a,ll b) {
    if (a>b) return a;
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>l>>r>>k;
    int res = 0;
    if (k==3) { //6 이상의 3배수 13 17 1개개
        int minval = max(l,6);
        for (int i=minval;i<=r;++i) {
            if (i%3==0) ++res;
        }
        cout<<res;
    }
    else if (k==5) { //15 이상의 5배수    15 24
        int minval = max(l,15);
        for (int i=minval;i<=r;++i) {
            if (i%5==0) ++res;
        }
        cout<<res;
    }
    else if (k==2) {
        res = max(r - max(l, 3) + 1, 0);
        cout<<res;
    }
    else { //k==4 14 20 4개  13 20 4개  10 16 3개  10 17 3개
        int minval = max(l,10);
        for (int i=minval;i<=r;++i) {
            if (i%2==0 && i!=12) ++res;
        }
        cout<<res;
    }
}
/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int l, r, k;
    cin >> l >> r >> k;

    if (k == 2) {
        cout << max(0, r - max(l, 3) + 1) << endl;
    }
    else if (k == 3) {
        cout << max(0, r / 3 - (max(l, 6) - 1) / 3) << endl;
    }
    else if (k == 4) {
        cout << max(0, r / 2 - (max(l, 14) - 1) / 2) + (l <= 10 && 10 <= r) << endl;
    }
    else {
        cout << max(0, r / 5 - (max(l, 15) - 1) / 5) << endl;
    }

    return 0;
}
*/