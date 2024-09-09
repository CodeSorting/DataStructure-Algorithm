#include <bits/stdc++.h>
using namespace std;
typedef vector<int> v;
//ex) abcdab에서는 abcd만 사용해도 된다.(abcdabcdabcd..) 반복되기 위한 최소를 찾기 위해 접두사==접미사인 최댓값을 구해야한다.(실패함수 이용)
v getPi(string s){
  int m = s.size();
  int j=0;
  v pi(m,0);
  for (int i=1;i<m;++i){
    while (j>0 && s[i]!=s[j]){
      j = pi[j-1];
    }
    if (s[i]==s[j]){
      pi[i] = ++j;
    }
  }
  return pi;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int L;
  cin>>L;
  string s;
  cin>>s;
  v pi = getPi(s);
  cout<<L-pi[L-1];
}