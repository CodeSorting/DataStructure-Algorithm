#include <iostream>
using namespace std;
typedef long long ll;

ll q,a,d,x,floor,number;
ll getleft(ll a,ll d,ll n){
  return (n - 1)*(2*a + (n - 2)*d)/2 + 1; //1 + 등차수열 합공식
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>q;
  while (q--){
    cin>>a>>d>>x;
    ll start=1,end=1000000;

    while (start<=end){
      ll mid = (start+end)/2;
      ll left = getleft(a,d,mid); //mid층의 제일 왼쪽 칸
      if (left<=x){
        start = mid+1;
        number = left;
        floor = mid;
      }
      else{
        end = mid-1;
      }
    }
    cout<<floor<<" "<<x-number+1<<'\n'; //층, 몇번째 숫자
  }
}