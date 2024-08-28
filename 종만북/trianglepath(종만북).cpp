#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[100][100],dp[100][100],n;
//부분 문제의 최적구조를 가지면 전체해도 최적됨
int path(int y, int x) {
    //기저 : 마지막 케이스까지 도달했으면 끝
    if (y == n - 1) return arr[y][x];
    //메모이제이션
    int& ret = dp[y][x];
    if (dp[y][x] != -1) return ret;

    //부문문제 두경우중 가장 큰 수
    return ret = max(path(y + 1, x),path(y + 1, x + 1)) + arr[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c;
    cin >> c;
    while (c--) {
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                cin >> arr[i][j];
        cout << path(0, 0) << '\n';
    }
}
/*
#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][101]={0,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,n,number(0);
    cin>>t;
    while (t--){
        cin>>n;
        number=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<=i;j++){
                cin>>dp[i][j];
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<=i;j++){
                if (j==0) dp[i][j]=dp[i-1][0]+dp[i][j];
                else if (i==j) dp[i][j]=dp[i-1][j-1]+dp[i][j];
                else dp[i][j]=max(dp[i-1][j-1]+dp[i][j],dp[i-1][j]+dp[i][j]);

                number=max(number,dp[i][j]);
            }
        }
        cout<<number<<'\n';
    }
}
*/
