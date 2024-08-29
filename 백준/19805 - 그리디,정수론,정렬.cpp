#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,flower[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for (int i=1;i<=n;++i){
    cin>>flower[i];
  }
  sort(flower+1,flower+1+n);
  ll sum = 0;
  for (int i=n;i>=2;--i){
    if (flower[i]%2==0){
      sum += (flower[i]-1);
    }
    else{
      sum += flower[i];
    }
  }
  if (n%2==1){ //n이 홀수면 가장 작은 값을 더하고 짝수면 안 쓰니 flower[1]을 추가하지 않는다.
    if (flower[1]%2==1) sum += flower[1];
    else sum += flower[1]-1;
  }
  cout<<sum;
}