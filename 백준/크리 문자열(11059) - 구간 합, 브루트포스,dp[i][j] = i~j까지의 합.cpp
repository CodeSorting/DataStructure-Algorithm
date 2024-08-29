#include <iostream>
#include <string>
using namespace std;

string s;
int dp[1001][1001],ans;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>s;
  int k = s.size();
  for (int i=0;i<k;++i){ // 누적합 셋팅, dp[i][j] = i~j까지의 길이 합
    dp[i][i] = s[i]-'0';
    for (int j=i+1;j<k;++j){
      dp[i][j] = dp[i][j-1] + s[j]-'0';
    }
  }

  for (int i=0;i<k;++i){
    int idx = i;
    for (int j=i+1;j<k;j=j+2){
      if (dp[i][j]%2==0 && dp[i][j]/2==dp[i][idx]){ // i~j까지의 합의 절반이 i~idx까지의 합일때
        ans = max(ans,j-i+1);
      }
      idx++; //idx는 1씩, j는 2씩 늘어나야 절반이 된다.
    }
  }
  cout<<ans;
}