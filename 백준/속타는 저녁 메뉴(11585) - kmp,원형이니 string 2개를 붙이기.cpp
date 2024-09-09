#include <iostream>
#include <string>
#include <vector>
using namespace std; //kmp알고리즘 O(n+m)
typedef vector<int> v;

int gcd(int a, int b) {
  if (a<b){
    swap(a, b);
  }
  while (b != 0) {
    int temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}
//getpi,kmp에서 i와 j는 투포인터처럼 구현되어있다.
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
  for (int i=0;i<n-1;++i){ //s[i]를 차례대로 본다. 이 문제에서는 마지막 배열에서 -1을 해줘야 s==p면 한 번 더 찾아지는걸 없앨 수 있다.
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
  int n;
  cin>>n;
  string s="",p="";
  char tmp;
  for (int i=0;i<n;++i){
    cin>>tmp;
    s += tmp;
  }
  for (int i=0;i<n;++i){
    cin>>tmp;
    p += tmp;
  }

  p += p; //원형인것을 한번 더 붙이는것처럼 생각한다.

  v res = kmp(p,s);
  int cnt = res.size();
  int g = gcd(n,cnt);
  cout<<cnt/g<<'/'<<n/g;
}