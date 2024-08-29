#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

class Matrix{
public:
  static int N;
  vector<vector<ll>> A;
  Matrix(){
    A = vector<vector<ll>>(N, vector<ll>(N, 0));
  }
  Matrix operator *(const Matrix O)const{
    Matrix R;
    for (int i=0;i<N;++i){
      for (int j=0;j<N;++j){
        for (int k=0;k<N;++k){
          R.A[i][j] += A[i][k] * O.A[k][j];
          R.A[i][j] %= MOD;
        }
      }
    }
    return R;
  }
};

int Matrix::N=0;

Matrix power(Matrix M,int k){
  if (k==0){ //0제곱
    Matrix E;
    for (int i=0;i<Matrix::N;++i){
      E.A[i][i] = 1;
    }
    return E;
  }
  if (k==1) return M; //1제곱 = 그대로

  Matrix R = power(M,k/2); //2이상 = 분할정복을 이용한 거듭제곱
  R = R*R;
  if (k%2) R = R*M;
  return R;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int v,e,d;
  cin>>v>>e;
  Matrix::N = v;
  Matrix M;
  for (int i=0;i<e;++i){ // 두 도로를 잇는 선은 1로 놓는다.
    int st,ed;
    cin>>st>>ed;
    st--;
    ed--;
    M.A[st][ed] = M.A[ed][st] = 1; 
  }
  cin>>d;
  M = power(M,d);
  cout<<M.A[0][0];
}
/*
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

using matrix = vector<vector<long long>>;
const int MOD = 1e9 + 7;

matrix operator * (matrix const& a, matrix const& b) {
  matrix ret(a.size(), vector<long long>(b[0].size()));
  for (int i = 0; i < a.size(); i++) for (int j = 0; j < b.size(); j++) for (int k = 0; k < b[0].size(); k++) {
    ret[i][k] = (ret[i][k] + a[i][j] * b[j][k]) % MOD;
  }
  return ret;
}

matrix pow(matrix a, int n) {
  matrix ret(a.size(), vector<long long>(a.size()));
  for (int i = 0; i < a.size(); i++) ret[i][i] = 1;
  while (n > 0) {
    if (n & 1) ret = ret * a;
    n /= 2;
    a = a * a;
  }
  return ret;
}

int main() {
  fastio;
  int n, m, k; cin >> n >> m;
  matrix A(n, vector<long long>(n));
  while (m--) {
    int a, b; cin >> a >> b; a--, b--;
    A[a][b] = A[b][a] = 1;
  }
  cin >> k;
  A = pow(A, k);
  cout << A[0][0] << '\n';
}
*/