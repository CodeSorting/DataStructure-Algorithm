#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll N,L,I; //N자리 2진수 1 개수 L개 이용해서 K번째 수 구하기
ll dp[32][32]; //i자리 이진수 중에서 1을 최대 j개까지 쓸 수 있는 경우의 수
// 끝이 0일 때 : dp[i-1][j] + 끝이 1일 때 : dp[i-1][j-1]
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>L>>I;
    string ans = "";
    for (int i=0;i<32;++i) { //32비트 조합식 초기
        dp[i][0] = 1; dp[i][i] = 1;
        for (int j=1;j<i;++j) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    for (int i=N;i>0;--i) {
        ll sum = 0;
        for (int j=0;j<=L;++j) {
            sum += dp[i-1][j]; // i번째 비트를 0으로 했을 때 가능한 개수
        }
        if (I <= sum) {
            ans += '0';
        } else {
            ans += '1';
            I -= sum;
            --L; // 1 하나 사용했으므로 줄임
        }
    }
    cout<<ans;
}