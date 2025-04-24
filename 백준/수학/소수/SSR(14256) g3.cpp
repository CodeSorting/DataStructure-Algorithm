#include <iostream>
#include <cmath>
using namespace std;

int n,m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int ans = 0;
    for (int i=1;i<=n;++i) {
        int cur = i,res = 1; // cur = 현재 값, res = 소인수분해 결과값
        for (int j=2;j*j<=cur;++j) { //소인수분해
            int cnt = 0; 
            while (cur%j==0) {
                ++cnt;
                cur /= j;
            }
            if (cnt%2) res *= j; //홀수 번 곱은 정수가 안되니 저장.
        }
        res = res*cur;
        ans += (int)sqrt(m/res);
    }
    cout<<ans;
}