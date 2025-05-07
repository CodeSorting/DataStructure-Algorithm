#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int m,n,cnt;
int dp[100001],row[100001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n;
    while (m!=0 && n!=0) {
        vector<vector<int>> arr(m, vector<int>(n));
        memset(dp,0,sizeof(dp));
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                cin>>arr[i][j];
            }
        }
        for (int i=0;i<m;++i) { //한 행에서의 열 선택 끼리의 합
            for (int j=0;j<n;++j) {
                int cur = arr[i][j];
                if (j==0) dp[j] = cur;
                else if (j==1) dp[j] = max(dp[0],cur);
                else dp[j] = max(dp[j-1],dp[j-2]+cur);
            }
            row[i] = dp[n-1];
        }
        memset(dp,0,sizeof(dp));
        for (int i=0;i<m;++i) {
            int cur = row[i];
            if (i==0) dp[i] = cur;
            else if (i==1) dp[i] = max(dp[0],cur);
            else dp[i] = max(dp[i-1],dp[i-2]+cur);
        }
        cout<<dp[m-1]<<'\n';     
        cin>>m>>n;
    }
}
