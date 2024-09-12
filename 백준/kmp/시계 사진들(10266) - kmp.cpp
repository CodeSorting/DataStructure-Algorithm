#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> v;

int n;

v getPi(v &p){ //pi배열 만들기
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

string kmp(v &s,v &p){
  v ans; //정답 배열
  v pi = getPi(p); //pi로 prefix==suffix인 최대 갯수 얻어오기
  int n = s.size(), m = p.size();
  int j = 0;
  for (int i=0;i<n;++i){ //s[i]를 차례대로 본다.
    while (j>0 && s[i]!=p[j]){ //pi배열로 중간단계 뛰어넘기
      j = pi[j-1];
    }
    if (s[i]==p[j]){ //계속 같은지 비교
      if (j==m-1){ 
        return "possible";
      }
      else{
        j++; //같으면 계속 최신화
      }
    }
  }
  return "impossible";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  v s(720000,0);
  v p(360000,0);
  int tmp1,tmp2;
  for (int i=0;i<n;++i){
    cin>>tmp1;
    s[tmp1] = 1;
    s[tmp1+360000] = 1; //원형이니 이어붙이기
  }
  for (int i=0;i<n;++i){
    cin>>tmp2;
    p[tmp2] = 1;
  }
  cout<<kmp(s,p);
}