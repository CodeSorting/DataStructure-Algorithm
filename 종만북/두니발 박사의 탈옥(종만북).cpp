#include <iostream>
#include <cstring>
using namespace std;

int n,d,p,t,connected[51][51],deg[51]; //[i][j] = i번 마을에서 j번 마을을 잇는 산길이 있음, [i] = i번 마을과 연결된 마을 개수
double dp[51][101];
double search(int here,int days){
    //기저사례
    if (days==0) return (here == p ? 1.0 : 0.0);
    //메모이제이션
    double &ret = dp[here][days];
    if (ret > -0.5) return ret;

    ret = 0.0;
    for (int there=0;there<n;++there){
        if (connected[here][there]){
            ret += search(there,days-1) / deg[there];
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c;
    cin>>c;
    cout.precision(8);
    cout<<fixed;
    while (c--){
        cin>>n>>d>>p;
        memset(dp,-1,sizeof(dp));
        memset(deg,0,sizeof(deg));
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                cin>>connected[i][j];
                deg[i] += connected[i][j]; //i번째 마을과 연결된 마을의 개수를 더해준다.
            }
        }
        cin>>t;
        int tmp;
        for (int i=0;i<t;++i){
            cin>>tmp;
            //확률 계산한거 넣기
            cout<<search(tmp,d)<<' ';
        }
        cout<<'\n';
    }
}