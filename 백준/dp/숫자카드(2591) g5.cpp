#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;
int dp[41],n; //dp[n] = 최대로 가능한 n개의 카드배치

//12334의 개수 = 1233 + 4랑 123 + 34 (34 안 넘게 조심하자.)
//12345 = 1234 + 5이다.
//즉 dp[5] = dp[4] + dp[3]이다.
//단, 맨 뒤의 수나 그 전의 수가 0이 되버리면 안되므로 조심하자.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    n = s.size();
    dp[0]=1;
    for (int i=1;i<n;++i) {
        int cur = (s[i-1]-'0') * 10 + (s[i]-'0');
        if (cur<=34 && s[i-1]!='0') { //123 05면 안된다.
            if (i==1) dp[i] = 1;
            else dp[i] = dp[i-2]; 
        }
        if (s[i]!='0') dp[i] += dp[i-1]; //460에서 46 + 0이라면 1~34라는 카드 수에 위배됨.
    }
    cout<<dp[n-1];
}