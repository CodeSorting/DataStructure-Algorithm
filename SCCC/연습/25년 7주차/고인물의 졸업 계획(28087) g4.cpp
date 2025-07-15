#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
ll n,m;
bool cmp(p a,p b) {
    return a.first>b.first;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    vector<pair<int,int>> v(m);
    for (int i=0;i<m;++i) {
        cin>>v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(),v.end(),cmp);
    ll sum = 0,tn = (n<<1);
    vector<int> res;
    for (int i=0;i<m;++i) {
        if (sum>=n && sum<=tn) break;
        int cur = sum + v[i].first;
        if ((cur>=n && cur<=tn) || (cur<tn)) {
            sum = cur;
            res.emplace_back(v[i].second);      
        }
    } 
    cout<<res.size()<<'\n';
    for (int i : res) cout<<i<<'\n';
}