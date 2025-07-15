#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,arr[2501],dp[2501];
// 1개씩 다 뽑으면 최대 n임. 여기서 인접한 걸로 뽑아 경우의 수를 줄여가야함.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (ll i=0;i<n;++i) cin>>arr[i];
    for (ll i=0;i<n;++i) {
        ll remain = arr[i];
        if (i) {
            dp[i] = max(dp[i],dp[i-1]);
        }
        for (ll j=i+1;j<n;++j) {
            remain = arr[j] - remain;
            if (remain<0) break;
            else if (remain==0) dp[j] = dp[i-1] + 1;
        }
    }
    cout<<n-dp[n-1];
}