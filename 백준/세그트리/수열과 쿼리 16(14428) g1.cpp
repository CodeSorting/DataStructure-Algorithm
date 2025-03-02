#include <iostream>
#include <algorithm> //수열과 쿼리 17과는 다르게 index를 출력해야되어서 P로 자료구조를 만들어야한다.
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll ST_MAX = 1<<18;
const int INF = 1e9+1;

struct SegTree{
  int start;
  P arr[ST_MAX];
  SegTree(){
    start = ST_MAX/2;
    fill(arr,arr+ST_MAX,P(INF,-1)); //최솟값을 구하기 위해 세팅
  }
  void settree(int n,int k){ arr[start+n] = P(k,n); } //value, index

  void construct(){
    for (int i=start-1;i>0;--i){
      arr[i] = min(arr[i*2],arr[i*2+1]);
    }
  }

  void update(int n,int k){
    n += start;
    arr[n].first = k;
    while (n>1){
      n /=2;
      arr[n] = min(arr[n*2],arr[n*2+1]);
    }
  }

  P getmin(int s,int e){ return getmin(s,e,1,0,start); }
  P getmin(int s,int e,int node,int ns,int ne){
    if (e<=ns || s>=ne) return P(INF,-1);
    if (s<=ns && ne<=e) return arr[node];
    int mid = (ns+ne)/2;
    return min(getmin(s,e,node*2,ns,mid),getmin(s,e,node*2+1,mid,ne));
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,m;
  cin>>n;
  SegTree ST;
  for (int i=0;i<n;++i){
    int tmp;
    cin>>tmp;
    ST.settree(i,tmp);
  }

  ST.construct();

  cin>>m;
  for (int i=0;i<m;++i){
    int q,a,b;
    cin>>q>>a>>b;
    if (q==1){
      ST.update(a-1,b); //index, value
    }
    else{
      cout<<ST.getmin(a-1,b).second+1<<'\n'; //index 출력
    }
  }
}