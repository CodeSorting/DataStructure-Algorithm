#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct{
  int start,end,index;
} Pos;
vector<Pos> v;
int n,m;
bool comp(Pos &a,Pos &b){
  if (a.start != b.start){
    return a.start<b.start; //시작점 기준 오름차순
  }
  return a.end>b.end; //start가 같으면 end 기준 내림차순
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  for (int i=1;i<=m;++i){
    int s,e;
    cin>>s>>e;
    if (s<e) v.push_back({s,e,i}); //circle이 아닐 때
    else{ //중요! circle일때 0과 n을 이어주기 위해 s-n,e+n으로 각각 넣는다. ex) n=10, 8 1일때 -2 1, 8 11이다.
      v.push_back({s-n,e,i}); 
      v.push_back({s,e+n,i});
    }
  }
  sort(v.begin(),v.end(),comp);
  vector<int> ans;
  ans.push_back(v[0].index);

  int temp = 0;
  for (int i=1;i<v.size();++i){
    if (v[temp].end<v[i].end){ //스위핑
      ans.push_back(v[i].index);
      temp = i;
    }
  }
  sort(ans.begin(),ans.end()); //ans정렬
  ans.erase(unique(ans.begin(),ans.end()),ans.end()); //중복된 값 없애기(s-n,e+n을 모두 넣었으니)
  for (int i=0;i<ans.size();++i){
    cout<<ans[i]<<' ';
  }
}
