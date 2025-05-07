#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> p;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<ll> v(n);
    for (int i=0;i<n;++i) cin>>v[i];
    stack<p> s; //first: 키,second: 현재 스택에 같은 키를 가진 사람의 수(이거 고려 안하면 안됨.)
    ll ans = 0;
    for (int i=0;i<n;++i) {
        ll cur = v[i];
        int cnt = 1;
        while (!s.empty() && s.top().first<=cur) {
            ans += s.top().second;
            cnt = s.top().first==cur ? s.top().second + 1 : 1; //키가 같다면 전 애의 cnt도 가능하다.
            s.pop();
        }
        if (!s.empty()) ++ans;
        s.push({cur,cnt});
    }
    cout<<ans;
}