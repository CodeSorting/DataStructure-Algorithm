#include <iostream>
#include <bitset>
#include <algorithm>
#include <cstring>
using namespace std;

int n; //짧은 문자열 개수
string s; //긴 문자열
string p; //짧은 문자열
bitset<100005> v[501]; //v[i][j]는 i번째 짧은 문자열이 큰 문자열 s의 j번째 인덱스부터 등장하는지 여부
int l; //긴 문자열 사이즈
int fail[10001],len[10001],dp[100001]; //실패함수,짧은 문자열 길이,dp 배열

int solve(int index){ //top-down dp
  //큰 문자열까지 같으면 이미 끝
  if (index==l) return 0;
  //메모이제이션
  int& ret = dp[index]; //&를 써서 ret이 변경되면 cache도 변경된다.
  if (ret != -1) return ret;

  ret = solve(index + 1);

  for (int i=0;i<n;++i){//dp
    if (v[i][index]){ //kmp이용했을 때 true이면
      ret = max(ret, len[i] + solve(index + len[i])); //ret을 쓰던가 문자열을 계속 이어가거나
    }
  }
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>s;
  l = s.size();
  cin>>n;
  memset(dp,-1,sizeof(dp));

  for (int k=0;k<n;++k){
    cin>>p; //짧은 문자열
    memset(fail,0,sizeof(fail));
    int w = p.size();
    len[k] = w; //짧은 문자열 길이 저장

    for (int i=1,j=0;i<w;++i){ //실패함수 만들기
      while (j>0 && p[i]!=p[j]){
        j = fail[j-1];
      }
      if (p[i]==p[j]){
        fail[i] = ++j;
      }
    }

    for (int i=0,j=0;i<l;++i){ //kmp 실행
      while (j>0 && s[i]!=p[j]){
        j = fail[j-1];
      }
      if (s[i]==p[j]){
        if (j==w-1){
          v[k][i-j] = true; //kmp 실행 완료
          j = fail[j]; 
        }
        else ++j;
      }
    }

  }
  cout<<solve(0);
}