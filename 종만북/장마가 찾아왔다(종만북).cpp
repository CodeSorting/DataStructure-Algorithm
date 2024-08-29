#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int n,m;
double dp[1001][2001];
double climb(int days,int climbed){
    //기저 사례 : 이미 그 이상으로 다 올랐을 경우
    if (days==m) return (climbed>=n ? 1 : 0);
    double &ret = dp[days][climbed];
    if (ret!=-1.0) return ret;
    return ret = 0.25*climb(days+1,climbed+1) + 0.75*climb(days+1,climbed+2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        cin>>n>>m;
        for (int i=0;i<1000;++i){
            for (int j=0;j<2001;++j){
                dp[i][j] = -1.0;
            }
        }
        cout.precision(11);
        cout<<fixed<<climb(0,0)<<'\n';
    }
}