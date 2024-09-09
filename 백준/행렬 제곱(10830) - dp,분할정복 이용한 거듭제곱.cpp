#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> v;

int n;

v matrixMultiply(v &a,v &b){ // 행렬 거듭제곱
  v c(n*n);
  for (int i=0;i<n;++i){
    for (int j=0;j<n;++j){
      for (int k=0;k<n;++k){
        c[i*n+j] = (c[i*n+j] + a[i*n+k] * b[k*n+j]) % 1000;
      }
    }
  }
  return c;
}

v matrixPower(v &a,ll p){ // 행렬 거듭제곱 분할정복
  if (p==1) return a;
  v c = matrixPower(a,p/2);

  c = matrixMultiply(c,c); // 짝수면 여기까지
  if (p%2) c = matrixMultiply(c,a); // 홀수면 a 한번 더 곱하기
  return c;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll b;
  cin>>n>>b;
  v a(n*n), R;
  for (int i=0;i<n*n;++i){
    cin>>a[i];
  }

  R = matrixPower(a,b);

  for (int i=0;i<n;++i){
    for (int j=0;j<n;++j){
      cout<<R[i*n+j]%1000<<" ";
    }
    cout<<'\n';
  }
}