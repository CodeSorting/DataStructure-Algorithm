#include <iostream>
#include <algorithm>
using namespace std;

int l,c;
char A[15],P[16];
bool isvowel[26];
void backtrack(int pos,int prev,int consonant, int vowel){//위치,이전,자음,모음
  // L개의 문자를 다 쓴 경우: 조건에 맞으면 현재 암호 출력하고 리턴
  if(pos==l){
    if(consonant >= 2 && vowel >= 1) puts(P);//최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성
    return;
  }
  // 아직 사용하지 않은 암호들 하나씩 시도
  for(int i=prev+1; i<c; i++){
    P[pos] = A[i];
    backtrack(pos+1, i, consonant + !isvowel[A[i]-'a'], vowel + isvowel[A[i]-'a']); //위치+1,이전+1,현재자음+추가한자음,현재 모음+추가한모음
    // P[pos]는 어차피 다시 덮어씌워질 것이므로 안 돌려놔도 됨
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>l>>c;
  for (int i=0;i<c;i++){
    cin>>A[i];
  }
  sort(A,A+c); //사전순이라 그렇다.
  isvowel[0] = isvowel[4] = isvowel[8] = isvowel[14] = isvowel[20] = true; //모음
  backtrack(0,-1,0,0);
}