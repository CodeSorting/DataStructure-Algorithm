#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 987654321;
string N;
int classify(int a,int b){
    string M = N.substr(a,b-a+1);
    if (M==string(M.size(),M[0])) return 1;

    bool progressive = true;
    for (int i=0;i<M.size()-1;++i){
        if (M[i+1]-M[i] != M[1]-M[0]){
            progressive = false;
        }
    }

    if (progressive && abs(M[1]-M[0])==1) return 2;
    bool alternating = true;
    for (int i=0;i<M.size();++i){
        if (M[i]!=M[i%2]){
            alternating = false;
        }
    }
    if (alternating) return 4;
    if (progressive) return 5;
    return 10;
}
int dp[10002];
int memorize(int begin){
    if (begin==N.size()) return 0;
    int &ret = dp[begin];
    if (ret!=-1) return ret;
    ret = INF;
    for (int L=3;L<=5;++L){
        if (begin+L<=N.size()){
            ret = min(ret,memorize(begin+L)+classify(begin,begin+L-1));
        }
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
        cin>>N;
        memset(dp,-1,sizeof(dp));
        cout<<memorize(0)<<'\n';
    }
}