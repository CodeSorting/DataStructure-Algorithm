#include <iostream>
#include <string>
using namespace std;
unsigned long long dp[101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    for (int i=1;i<=n;++i) {
        dp[i] = dp[i-1] + 1;
        for (int j=3;j<i;++j) {
            dp[i] = max(dp[i],dp[i-j]*(j-1));        
        }
    }
    cout<<dp[n];
} 