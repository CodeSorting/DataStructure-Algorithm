#include <iostream>
using namespace std;
typedef long long ll;

ll n,x;
/*
()는 그런디 수
0 -> 그런디 수 = 0
1 -> 0 -> 그런디 수 = 1
2 -> 그런디 수 = 0
3 -> 모두 제거(0),2개 제거(1) -> 그런디 수 = 2
4 -> 2개 제거(0) -> 그런디 수 = 1
5 -> 2개 제거(3), 4개 제거(1),모두 제거(0) -> 3
6 -> 2개 제거(4), 4개 제거(2) -> {1,0} -> 그런디 수 = 2
홀수 = (x+1)/2, 짝수 = (x-1)/2
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ll res = 0;
    for (int i=0;i<n;++i) {
        cin>>x;
        if (x%2) res ^= (x+1)/2;
        else res ^= (x-1)/2;
    }
    if (res) cout<<"koosaga";
    else cout<<"cubelover";
}