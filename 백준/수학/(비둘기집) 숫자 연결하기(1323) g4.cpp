#include <iostream>
#include <set>
#include <string>
using namespace std;
typedef long long ll;
set<ll> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k,cur; cin>>n>>k;
    cur = n; //2 
    int cnt = 0;
    string tmp = "";
    while (true) {
        tmp += to_string(n); // 2 -> 문자 2
        cur = stoll(tmp); // 다시 숫자 2
        cur %= k; // 나머지 계산
        tmp = to_string(cur); // 나머지 나눈걸로 바꿈.
        ++cnt;
        if (cur==0) {
            cout<<cnt;
            return 0;
        }
        if (s.count(cur)) break;
        s.insert(cur);
    }
    cout<<-1;
}