#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef __int128 ll;
ll m,a,c,x0,n,g;
typedef vector<vector<ll>> vll;
//행렬 곱
vll matMul(const vll& A,const vll& B) {
    int n = A.size();
    vll C(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k)
            if (A[i][k]) {
                for (int j = 0; j < n; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % m;
                }
            }
    }
    return C;
}
//행렬 거듭제곱
vll matPow(const vll& A, ll e) {
    int n = A.size();
    if (e == 0) { //단위행렬
        vll I(n, vector<ll>(n, 0));
        for (int i = 0; i < n; ++i) I[i][i] = 1;
        return I;
    }
    if (e & 1) return matMul(matPow(A, e-1), A);
    else {
        auto half = matPow(A, e/2);
        return matMul(half, half);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long temp;
    cin>>temp; m = temp; //Xn+1 = (aXn + c) mod m
    cin>>temp; a = temp; //xn+1 = (8xn + 7) mod 11 -> x5 mod 3 출력하기
    cin>>temp; c = temp;
    cin>>temp; x0 = temp;
    cin>>temp; n = temp;
    cin>>temp; g = temp;
    vll v = {{a,c},{0,1}};
    vll res = matPow(v,n);
    __int128 tmp = (res[0][0] * x0 + res[0][1]) % m;
    tmp = tmp % g;
    long long answer = (long long)tmp;
    cout << answer;    
}