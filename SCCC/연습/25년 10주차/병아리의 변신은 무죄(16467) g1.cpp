#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 100000007;
typedef vector<vector<ll>> vll;
ll modPow(ll a, ll b) {
    if (b == 0) return 1;
    ll half = modPow(a, b/2);
    ll res = (half % MOD * half % MOD) % MOD;
    if (b & 1) res = (res * a) % MOD;
    return res;
}
//행렬 곱
vll matMul(const vll& A,const vll& B) {
    int m = A.size();
    vll C(m, vector<ll>(m, 0));
    for (int i = 0; i < m; ++i) {
        for (int k = 0; k < m; ++k)
            if (A[i][k]) {
                for (int j = 0; j < m; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
    }
    return C;
}
//행렬 거듭제곱
vll matPow(const vll& A, ll e) {
    int m = A.size();
    if (e == 0) { //단위행렬
        vll I(m, vector<ll>(m, 0));
        for (int i = 0; i < m; ++i) I[i][i] = 1;
        return I;
    }
    if (e & 1) return matMul(matPow(A, e-1), A);
    else {
        auto half = matPow(A, e/2);
        return matMul(half, half);
    }
}

ll solve(ll k, ll N) {
    //f(n) = f(n-1) + f(n-k-1)
    if (N <= k) return 1; //이 경우 알만 남음.
    int m = k + 1;
    //matrix M (크기 (k+1)x(k+1))
    vll M(m, vector<ll>(m, 0));
    // 첫 행 [1, 0, 0, ..., 0, 1]
    M[0][0]=1;
    M[0][m-1]=1;
    for (int i = 1; i < m; ++i) M[i][i-1] = 1;
    auto P = matPow(M, N - k); // M^(N-k)
    // 초기 벡터 V = [f(k), f(k-1), ..., f(0)] = 모두 1
    ll ans = 0;
    for (int j = 0; j < m; ++j) ans = (ans + P[0][j]) % MOD;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll k,n; cin>>k>>n;
        if (k == 0) cout << modPow(2,n) << "\n";
        else cout << solve(k,n) << "\n";
    }
}
/*
f(n) = f(n-1) + f(n-k-1)
M = ┌                             ┐
    │ 1  0  0  …  0   1 │   ← 첫째 행: f(n)=f(n-1)+f(n-K-1)
    │ 1  0  0  …  0   0 │   ← 둘째 행: f(n-1)←f(n-1)
    │ 0  1  0  …  0   0 │   ← 셋째 행: f(n-2)←f(n-2)
    │ ⋮                 │
    │ 0  0  … 1  0   0 │   ← 마지막 행: f(n-K)←f(n-K)
    └                             ┘
*/