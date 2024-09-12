#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 2097152;

ll tree[MAX],n,q,start=2;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>q;
  while (start<=n) start<<=1;
  ll sum = 0;
  while (q--){
    ll a,i,j;
    cin>>a>>i>>j;
    if (a==1){ //값 변경
      i += start-1;
      tree[i] += j;
      while (i>1){
        i >>=1;
        tree[i] = tree[i*2] + tree[i*2+1];
      }
    }
    else{ //합 구하기
      i += start-1;
      j += start-1;
      if (i==j){
        cout<<tree[i]<<'\n';
        continue;
      }
      if (i>j) swap(i,j);
      sum = 0;
      while (i!=j){
        if (i%2){
          sum += tree[i];
          i = i/2+1;
        }
        else i/=2;
        if (j%2==0){
          sum += tree[j];
          j = j/2-1;
        }
        else j/=2;
        if (i>=j){
          if (i==j) sum += tree[i];
          break;
        }
      }
      cout<<sum<<'\n';
    }
  }
}