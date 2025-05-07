#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
ll n,h,o,d,res;
bool cmp(pair<ll,ll> &a,pair<ll,ll> &b) { //끝 기준으로 먼저 오름차순 정렬을 해야 d를 잘 이용할 수 있다.
    if (a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<pair<ll,ll>> v(n);
    priority_queue<ll,vector<ll>, greater<ll>> pq;

    for (int i=0;i<n;++i) {
        cin>>h>>o;
        if (h>o) swap(h,o);
        v[i].first = h; v[i].second = o;
    }
    sort(v.begin(),v.end(),cmp);
    cin>>d;
    ll cnt = 0;
    for (int i=0;i<n;++i) {
        ll ed = v[i].second;
        ll st = ed-d;
        while (!pq.empty() && pq.top()<st) { //길이 위치 최신화
            --cnt;
            pq.pop();
        }
        if (v[i].first>=st) {
            ++cnt;
            pq.push(v[i].first);
            res = max(res,cnt);
        }
    }
    cout<<res;
}