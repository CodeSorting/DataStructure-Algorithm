#include <iostream>
#include <string>
using namespace std;

const int MOD = 1000000;
int dp[5001]; //dp[n] = n자리의 해석 경우의 수
string s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>s; //5000자리 이하의 것
  int n = s.size();

  if (s[0]=='0'){ //예외처리
    cout<<0;
    return 0;
  }
  dp[0] = 1;
  dp[1] = 1;

  for (int i=2;i<=n;++i){
    if (s[i-1]!='0') dp[i] = (dp[i] + dp[i-1]) % MOD;

    string tmp="";
    tmp = tmp + s[i-2] + s[i-1];
    int k = stoi(tmp); //맨 뒤 2자리
    if (k>=10 && k<=26){
      dp[i] = (dp[i] + dp[i-2]) % MOD;
    }
  }
  cout<<dp[n];
}