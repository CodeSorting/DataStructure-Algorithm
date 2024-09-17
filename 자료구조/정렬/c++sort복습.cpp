#include <iostream>
#include <algorithm>
#include <vector> // boj-10825
#include <string>
using namespace std;
typedef pair<pair<string,int>,pair<int,int>> p;

int n;
bool cmp(p a,p b){
  if (a.first.second==b.first.second){
    if (a.second.first==b.second.first){
      if (a.second.second==b.second.second){
        return a.first.first<b.first.first; //이름순
      }
      return a.second.second>b.second.second; //수학 점수 내림차순 정렬
    }
    return a.second.first<b.second.first; //영어 점수 오름차순 정렬
  }
  return a.first.second>b.first.second; //국어 점수 내림차순 정렬
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  vector<p> v; //값 4개 저장
  v.resize(n);
  for (int i=0;i<n;i++){
    cin>>v[i].first.first>>v[i].first.second>>v[i].second.first>>v[i].second.second;
  }
  sort(v.begin(),v.end(),cmp);
  for (int i=0;i<n;i++){
    cout<<v[i].first.first<<'\n';
  }
}
