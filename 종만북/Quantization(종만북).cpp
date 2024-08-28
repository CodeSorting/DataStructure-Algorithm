#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 987654321;
int n,m;
int A[101],pSum[101],pSqSum[101];
void precalc(){
    sort(A,A+n); //정렬 먼저 하기
    pSum[0] = A[0]; //구간 합 구하기
    pSqSum[0] = A[0]*A[0]; //구간 제곱 합 구하기
    for (int i=1;i<n;++i){
        pSum[i] = pSum[i-1] + A[i];
        pSqSum[i] = pSqSum[i-1] + A[i]*A[i];
    }
}
int minError(int lo,int hi){
    //부분합을 이용해 A[lo]~A[hi]까지의 합을 구한다.
    int sum = pSum[hi] - (lo==0 ? 0 : pSum[lo-1]);
    int sqSum = pSqSum[hi] - (lo==0 ? 0 : pSqSum[lo-1]);
    //평균을 반올림한 값으로 이 수들을 표현한다
    int m = int(0.5+(double)sum/(hi-lo+1));
    //sum(A[i]-m)^2를 전개한 결과를 부분합으로 표현
    int ret = sqSum - 2*m*sum + m*m*(hi-lo+1);
    return ret;
}
int dp[101][101];
int quantize(int from,int parts){
    //기저 사례: 모든 숫자를 다 양자화 했을 때
    if (from==n) return 0;
    //기저 사례 : 숫자는 아직 남았는데 더 묶을 수 없을 때 아주 큰 값을 반환한다.
    if (parts==0) return INF;
    int &ret = dp[from][parts]; //메모이제이션
    if (ret!=-1) return ret;
    
    ret = INF;
    for (int partsize=1;from+partsize<=n;++partsize){
        ret = min(ret,minError(from,from+partsize-1)+quantize(from+partsize,parts-1));
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
        cin>>n>>m;
        for (int i=0;i<n;++i){
            cin>>A[i];
        }
        memset(dp,-1,sizeof(dp));
        precalc();
        cout<<quantize(0,m)<<'\n';
    }
}