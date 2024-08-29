#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int dp[101][101],n,triangle[101][101],cache[101][101];
int path2(int y,int x){
    if (y==n-1) return triangle[y][x];
    int &ret = cache[y][x];
    if (ret!=-1) return ret;
    return ret = max(path2(y+1,x),path2(y+1,x+1)) + triangle[y][x];
}

int count(int y,int x){
    //기저 사례 : 맨 아랫층에 도달했을 경우
    if (y==n-1) return 1;
    int &ret = dp[y][x];
    if (ret!=-1) return ret;
    ret = 0;
    if (path2(y+1,x+1)>= path2(y+1,x)) ret += count(y+1,x+1);
    if (path2(y+1,x+1)<= path2(y+1,x)) ret += count(y+1,x);
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
        memset(cache,-1,sizeof(cache));
        for (int i=0;i<n;++i){
            for (int j=0;j<=i;++j){
                cin>>triangle[i][j];
            }
        }
        cout<<count(0,0)<<'\n';
    }
}