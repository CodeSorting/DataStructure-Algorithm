#include <iostream>
using namespace std; 

const int MOD = 1e9 + 7;
int n,dp[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if (n == 1) { // 예외 처리
        cout<<3;
        return 0;
    }
    dp[1] = 3;
    dp[2] = 8;
    for (int i=3;i<=n;++i) {
        dp[i] = ( (dp[i-1] * 2) % MOD + (dp[i-2] * 2) % MOD ) % MOD;
    }
    cout<<dp[n];
}