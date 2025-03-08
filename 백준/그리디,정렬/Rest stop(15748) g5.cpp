#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll l,n,rb,rj,x,c;
  cin>>l>>n>>rj>>rb; //산 길이,정류장 개수,존의 속도, 배시의 속도
  vector<pair<int,int>> v;
  for (int i=0;i<n;i++) {
    cin>>x>>c;//정류장 위치와 맛
    v.push_back({c,x}); //맛,위치 넣음.(내림차순 정렬을 위해 바꿔줌.)
  }

  sort(v.begin(),v.end(),greater<>()); //가치가 가장 큰 stop부터 가야 하므로 가치를 기준으로 내림차순 정렬한다.
  ll cur=0,res=0;

  for (int i=0;i<v.size();i++) {
    if (cur < v[i].second) { //정류장위치보다 현재가 작다면
      res += (rj - rb) * (v[i].second - cur) * v[i].first;
      cur = v[i].second;
    }
  }
  cout<<res;
}