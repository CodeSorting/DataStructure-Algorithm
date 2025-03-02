#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int n,arr[26];
string s;
bool cmp(int a,int b){
  return a>b;//내림차순
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for (int i=0;i<n;i++){
    cin>>s;
    int L = s.size();
    int v = 1;
    for (int j=L-1;j>=0;j--){
      arr[s[j]-'A'] += v; //차례대로 arr에 A~Z까지의 값 저장
      v*=10;
    }
  }
  sort(arr,arr+26,cmp);//그리디하게 정렬해서 큰 것을 9,8,7...로 놓기
  int num=9;
  int ret=0;
  for (int i=0;i<26;i++){
    if (arr[i]==0) break;
    ret += arr[i] * num--;
  }
  cout<<ret;
}