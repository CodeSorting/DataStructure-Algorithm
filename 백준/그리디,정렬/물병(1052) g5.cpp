#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> ans;
ll n,k;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for (int i=24;i>=0;--i) {
        ll factor = (1<<i);
        if (n>=factor) {
            n -= factor;
            ans.push_back(factor);
        }
    }
    if (ans.size()<=k) {
        cout<<0;
        return 0;
    }
    int res = 0;
    while (ans.size()>k) {
        ll cur1 = ans.back(); ans.pop_back(); //cur2>cur1
        ll cur2 = ans.back(); ans.pop_back();
        res += cur2-cur1;
        ans.push_back((cur2<<1));
    }
    cout<<res;
}