#include <iostream>
#include <string>
#include <vector>
using namespace std;
// KMP 알고리즘: O(n + m) : 문자열 검색 알고리즘으로, 접두사와 접미사의 일치를 이용해 불필요한 비교를 줄임
typedef vector<int> v;
// 패턴 문자열 p에 대한 접두사-접미사(pi) 배열 생성
v getPi(string p) {
  int m = p.size();
  int j = 0;
  v pi(m, 0); // pi[i]: 패턴의 0부터 i까지의 부분 문자열에서 접두사 == 접미사인 최대 길이
  for (int i = 1; i < m; ++i) {
    // 현재 문자가 일치하지 않으면 이전 pi 값을 따라가며 j 이동
    while (j > 0 && p[i] != p[j]) {
      j = pi[j - 1];
    }
    // 일치할 경우 j를 증가시키고, 해당 값을 pi에 저장
    if (p[i] == p[j]) {
      pi[i] = ++j;
    }
  }
  return pi;
}
//abcdab -> p[0]=0,p[1]=0,p[2]=0,p[3]=0,p[4]=1
// KMP 문자열 검색 함수: 문자열 s에서 패턴 p가 나타나는 시작 인덱스들 반환
v kmp(string s, string p) {
  v ans;           // 결과 인덱스 저장
  v pi = getPi(p); // 패턴의 pi 배열 계산
  int n = s.size(), m = p.size();
  int j = 0;
  for (int i = 0; i < n; ++i) { //i : s의 현재 인덱스, j : p의 현재 인덱스
    // 일치하지 않을 경우 pi 배열을 참고해 j 이동
    while (j > 0 && s[i] != p[j]) {
      j = pi[j - 1];
    }
    // 문자가 일치할 경우
    if (s[i] == p[j]) {
      // 패턴 전체 일치 시
      if (j == m - 1) {
        ans.push_back(i - m + 1); // 시작 인덱스 저장
        j = pi[j]; // 다음 매칭을 위해 j 갱신
      }
      else {
        j++; // 계속 일치하면 j 증가
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string s, p;
  getline(cin, s); // 검색 대상 문자열
  getline(cin, p); // 찾을 패턴 문자열

  v res = kmp(s, p); // KMP 실행
  cout << res.size() << "\n"; // 패턴이 등장한 횟수 출력
  for (int i : res) {
    cout << i + 1 << ' '; // 패턴이 등장한 위치들 (1-indexed) 출력
  }
}
/*
패턴: ABABAC
본문: ABABABAC

비교 흐름:
i (s[i])	s[i]	j	p[j]	결과	j 변화
0	A	0	A	일치	j → 1
1	B	1	B	일치	j → 2
2	A	2	A	일치	j → 3
3	B	3	B	일치	j → 4
4	A	4	A	일치	j → 5
5	B	5	C	❌ 불일치!	j → 3 (pi[4])
5	B	3	B	✅ 다시 일치	j → 4
6	A	4	A	일치	j → 5
7	C	5	C	일치 (끝까지)	j → 6 (매칭 성공)
*/