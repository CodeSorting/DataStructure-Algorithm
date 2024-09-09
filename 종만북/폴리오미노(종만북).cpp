#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 10000000;
int n,dp[101][101];
int poly(int n,int first){
    if (n==first) return 1;
    int &ret = dp[n][first];
    if (ret!=-1) return ret;
    ret = 0;
    for (int second=1;second<=n-first;++second){
        int add = second + first - 1;
        add *= poly(n-first,second);
        add %= MOD;
        ret += add;
        ret %= MOD;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        cin>>n;
        memset(dp,-1,sizeof(dp));
        int sum = 0;
        for (int i=1;i<=n;++i){
            sum = (sum + poly(n,i)) % MOD;
        }
        cout<<sum<<'\n';
    }
}