#include <iostream>
#include <string>
#include <vector>
using namespace std; //kmp알고리즘 O(n+m)
typedef vector<int> v;

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
v kmp(string s,string p){
  v ans; //정답 배열
  v pi = getPi(p); //pi로 prefix==suffix인 최대 갯수 얻어오기
  int n = s.size(), m = p.size();
  int j = 0;
  for (int i=0;i<n;++i){ //s[i]를 차례대로 본다.
    while (j>0 && s[i]!=p[j]){ //pi배열로 중간단계 뛰어넘기
      j = pi[j-1];
    }
    if (s[i]==p[j]){ //계속 같은지 비교
      if (j==m-1){ //다 같다면 정답 배열에 넣기
        ans.push_back(i-m+1);
        j = pi[j];
      }
      else{
        j++; //같으면 계속 최신화
      }
    }
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s,p;
  getline(cin,s);
  getline(cin,p);
  v res = kmp(s,p);
  cout<<res.size()<<"\n"; //몇번 나타나는지
  for (int i : res){
    cout<<i+1<<' '; //나타나는 각각의 위치 출력
  }
}