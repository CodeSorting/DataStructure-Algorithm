#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> Matrix;
const ll MOD = 1000000007;
ll N,M;
Matrix A = {{1,1},{1,0}};

ll gcd(ll a,ll b){ //유클리드 호제론
  if (b==0) return a;
  return gcd(b,a%b);
}

Matrix multiply(Matrix a,Matrix b){ //행렬곱
  int r = a.size();
  int c = b[0].size();
  int k = b.size();
  Matrix ret = Matrix(r,vector<ll>(c,0));

  for (int i=0;i<r;++i){
    for (int j=0;j<c;++j){
      for (int K=0;K<k;++K){
        ret[i][j] += (a[i][K] * b[K][j]) % MOD;
        ret[i][j] %= MOD;
      }
    }
  }
  return ret;
}

Matrix power(Matrix m,ll n){ //행렬 거듭제곱
  if (n==1) return m;
  Matrix half = power(m,n/2);
  if (n%2==0) return multiply(half,half);
  else return multiply(multiply(half,half),m);
}

ll fib(ll n){ //피보나치 수열의 행렬의 거듭제곱으로 나타내고 분할정복을 이용한다.
  if (n==1) return 1;
  else return power(A,n-1)[0][0];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>N>>M;
  if (N>M) swap(N,M);
  cout<<fib(gcd(N,M));
}