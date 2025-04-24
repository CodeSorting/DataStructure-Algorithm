#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  getline(cin, s);
  int n = s.size(); int j = 0;
  v pi(n, 0); // pi[i]: 패턴의 0부터 i까지의 부분 문자열에서 접두사 == 접미사인 최대 길이
  for (int i = 1; i < n; ++i) {
    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if (s[i] == s[j]) {
      pi[i] = ++j;
    }
  }
  int Max = pi[n-1]; //0~n-1까지의 모든 문자열과 pi[i]의 부분문자열 비교
  while (Max>0) {
    for (int i=1;i<n-1;++i) { //중간에도 있는지 확인
      if (pi[i]==Max) {
        cout<<s.substr(0,Max);
        return 0;
      }
    }
    Max = pi[Max-1];
  }
  cout<<-1;
}