#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll ST_MAX = 1<<18;
const int INF = 1e9+1;

struct SegTree{
  int start;
  int arr[ST_MAX];
  SegTree(){
    start = ST_MAX/2;
    fill(arr,arr+ST_MAX,INF); //최솟값을 구하기 위해 세팅
  }
  void settree(int n,int k){ arr[start+n] = k; }

  void construct(){
    for (int i=start-1;i>0;--i){
      arr[i] = min(arr[i*2],arr[i*2+1]);
    }
  }

  void update(int n,int k){
    n += start;
    arr[n] = k;
    while (n>1){
      n /=2;
      arr[n] = min(arr[n*2],arr[n*2+1]);
    }
  }

  int getmin(int s,int e){ return getmin(s,e,1,0,start); }
  int getmin(int s,int e,int node,int ns,int ne){
    if (e<=ns || s>=ne) return INF;
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
      ST.update(a-1,b);
    }
    else{
      cout<<ST.getmin(a-1,b)<<'\n';
    }
  }
}