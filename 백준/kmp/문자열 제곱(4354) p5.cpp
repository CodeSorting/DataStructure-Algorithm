#include <bits/stdc++.h> //kmp,실패함수만 만들어도 문제를 풀 수 있다.
using namespace std;
typedef vector<int> v;

//getpi에서 i와 j는 투포인터처럼 구현되어있다.
v getPi(string p){ //pi배열 만들기 
  int m = p.size();
  int j=0;
  v pi(m,0); //pi배열
  for (int i=1;i<m;++i){ //pi[i]만들기
    while (j>0 && p[i]!=p[j]){ //서로 안 같다면 j-1번째로 초기화해야한다.
      j = pi[j-1];
    }
    if (p[i]==p[j]){ //서로 같다면 pi[i]에 +1
      pi[i] = ++j;
    }
  }
  return pi;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  while (true){
    cin>>s;
    if (s==".") return 0;
    int sz = s.size();
    v table = getPi(s); //실패함수 모음집
    int div = sz-table[sz-1]; //div는 중복되지 않은 최대 접두사의 길이 ababab에서 6-4=2
    if (sz%div) cout<<1<<'\n'; //나머지가 있다면 반복되어도 답은 1이다. ex) abcab
    else cout<<sz/div<<'\n'; //수열 길이에서 중복되지 않은 최대 접두사의 길이를 나눈다.
  }
}