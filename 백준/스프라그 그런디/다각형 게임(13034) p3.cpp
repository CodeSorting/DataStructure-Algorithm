#include <iostream>
using namespace std;
typedef long long ll;

int n;
/*
스프라그 그런디 정리
그런디 수
변 개수 = n(n-1)/2
0 -> {0}
1 -> 그런디 수 = {0}
2 -> 변 1개 {0(0),1(0)} -> 1
3 -> 변 3개 = 변 3개 {0,1}
4 -> 
5 -> 변 10개 = 변 5개 + 대각선 5개(교차 불가능이면 2개)
6 -> 변 12개 = 변 6개 + 대각선 6개(교차 불가능이면 2개)

그런디 수 = temp-2
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ll res = 0;
    ll temp;
    for (int i=0;i<n;++i) {
        cin>>temp;
        res ^= (temp-2);
    }
    
}