#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> p;
int n;
bool linear(p &a,p &b,p &c) {
    return (b.first-a.first) * (c.second-a.second) == (c.first-a.first) * (b.second-a.second);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<p> v(n);
    for (int i=0;i<n;++i) {
        cin>>v[i].first>>v[i].second;
    }
    int Max = -1;
    for (int i=0;i<n;++i) {
        for (int j=i+1;j<n;++j) {
            p a = v[i]; p b = v[j];
            int cnt = 0;
            for (int k=0;k<n;++k) {
                if (linear(a,b,v[k])) ++cnt;
            }
            if (cnt>=3) Max = max(Max,cnt);
        }
    }
    cout<<Max;
}
/* O(N^2logn) 풀이
#include <iostream>
#include <algorithm>
using namespace std;
inline double f(int x, int y){
    return x == 0?1e10:1.*y/x;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    pair<int,int> p[1010];
    for (int i=0,x,y;i<n;++i){
        cin>>x>>y;
        p[i] = make_pair(x,y);
    }
    int ans = -1;
    double a[1010];
    for (int i=n;i>0;--i){
        for (int j=0;j<i;++j){
            a[j] = f(p[j].first - p[i].first, p[j].second - p[i].second);
        }
        sort(a,a+i);
        int curr = 2;
        for (int j=1;j<i;++j){
            if (a[j] == a[j-1]){
                curr += 1;
                ans = max(ans, curr);
            }
            else {
                curr = 2;
            }
        }
    }
    cout<<ans;
}
*/