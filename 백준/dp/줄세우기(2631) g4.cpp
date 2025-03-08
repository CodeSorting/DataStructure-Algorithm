#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int arr[201],dp[201];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>arr[i];
  }
  for (int i=1;i<=n;i++){ //dp로 LIS 구현 O(n^2)
    dp[i] = 1;
    for (int j=1;j<i;j++){
      if (arr[i]>arr[j]) dp[i] = max(dp[i],dp[j]+1);
    }
  }
  int LIS = 1;
  for (int i=1;i<=n;i++){
    if (dp[i]>LIS) LIS = dp[i];
  }
  cout<<n-LIS;
}