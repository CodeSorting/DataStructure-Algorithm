#include <iostream>
#include <algorithm>
using namespace std;
int n,arr[100001],dp[1000001]; //값이 1~100만임. 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i) cin>>arr[i];
    int Max = 0;
    for (int i=0;i<n;++i) {
        int cur = arr[i];
        dp[cur] = max(dp[cur-1]+1,dp[cur]);
        Max = max(Max,dp[cur]);
    }
    cout<<Max;
}