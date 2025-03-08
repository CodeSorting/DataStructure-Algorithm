#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll n,t,ans;
vector<pair<int,int>> p; // pi,wi

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>t;
    int wi,pi;
    for (int i=0;i<n;++i) {
        cin>>wi>>pi; // wi : 초기 맛, pi : 증가 맛
        p.push_back({pi,wi}); // 순서 바꿈.
    }
    sort(p.begin(),p.end());
    for (int i=0;i<n;++i) {
        ll wn = p[i].second;
        ll pn = p[i].first;
        ans += wn + pn * (i+t-n); // 그리디,정렬 알고리즘.
        // 증가 맛이 초기 맛보다 더욱 크니 증가가 작은 걸 먼저 먹는다.
    }
    cout<<ans;
}