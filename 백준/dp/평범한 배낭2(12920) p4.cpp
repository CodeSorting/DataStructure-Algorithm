#include <iostream>
using namespace std;
//O(nmk)는 시간초과, O(nmlogk)로 가야함.
int dp[10001]; //dp[i] = 물건의 무게가 i일 때 최대한의 결과

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        int v,c,k;
        cin>>v>>c>>k; //무게,만족도,개수
        int t=1,temp;
        while (k>0){
            temp = min(k,t);
            for (int j=m;j>=v*temp;j--){
                dp[j] = max(dp[j],dp[j-v*temp]+c*temp);
            }
            t *= 2; //2씩 곱해 O(k)를 O(logk)로 최적화할 수 있다.
            k -= temp;
        }
    }
    int ans = 0;
    for (int i=0;i<=m;i++){
        ans = max(ans,dp[i]);
    }
    cout<<ans;
}
/*
#include <iostream>
using namespace std;

int dp[10001]; //dp[i][j] = 물건의 무게가 i일 때 최대한의 결과

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        int v,c,k;
        cin>>v>>c>>k; //무게,만족도,개수
        int t=1,temp;
        while (k>0){
            temp = min(k,t);
            for (int j=m;j>=v*temp;j--){
                dp[j] = max(dp[j],dp[j-v*temp]+c*temp);
            }
            t *= 2; //2씩 곱해 O(k)를 O(logk)로 최적화할 수 있다.
            k -= temp;
        }
    }
    int ans = 0;
    for (int i=0;i<=m;i++){
        ans = max(ans,dp[i]);
    }
    cout<<ans;
}
*/