#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ll; //2A+1 소수판정 문제

int t,cnt=0;
int lis[3] = {2,7,61};
ll temp;
ll power(ll a,ll b,ll c){
    if (b==0) return 1;
    temp = power(a,b/2,c) % c;
    if (b%2==0) return temp * temp % c;
    else return temp * temp % c * a % c;
}

bool check(ll n,int a){ //밀러 라빈 소수판정
  if (n%a==0) return true;
  ll d = n-1; //n-1 = d x 2^r꼴로 한 다음 r을 계속 2로 나눠주면서 나머지가 -1(n-1)이면 소수다.
  while (d%2==0){
    if (power(a,d,n)==n-1) return true;
    d /= 2;
  }
  ll temp = power(a,d,n); //a^d=1 (mod n) 만족하면 소수다.
  return temp==1 || temp==n-1;
}

bool prime(ll n){
  for (int i=0;i<3;++i){
    if (!check(n,lis[i])) return false; //check가 거짓이면 소수가 아님.
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>t;
  while (t--){
    ll n;
    cin>>n;
    if (prime(2*n+1)) cnt++; //소수이다.
  }
  cout<<cnt;
}