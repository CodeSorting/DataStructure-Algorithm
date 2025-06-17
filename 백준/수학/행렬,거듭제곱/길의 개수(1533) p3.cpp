#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MOD 1000003
typedef long long ll;
typedef vector<vector<ll>> vll;

ll n,s,e,t;
vll matMul(const vll& A,const vll& B) {
    int n = A.size();
    vll C(n,vector<ll>(n,0));
    for (int i=0;i<n;++i) {
        for (int k=0;k<n;++k) {
            if (A[i][k]) {
                for (int j=0;j<n;++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
    }
    return C;
}
vll matPow(const vll& A,ll e) {
    int n = A.size();
    if (e==0) {
        vll I(n,vector<ll>(n,0));
        for (int i=0;i<n;++i) I[i][i] = 1;
        return I;
    }
    if (e&1) return matMul(matPow(A,e-1),A);
    else {
        auto half = matPow(A,e/2);
        return matMul(half,half);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>s>>e>>t;
    char ch;
    vll arr(n*5,vector<ll>(n*5,0));
    //여러 시간 걸리는 것을 1분 단위로 쪼개주어서 이어줌.
    for (int i=0;i<n;++i) { 
        for (int j=1;j<5;++j) {
            arr[i*5+j][i*5+j-1] = 1;
        }
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            cin>>ch;
            int temp = ch-'0';
            if (temp>=1) arr[i*5][j*5+temp-1] = 1; //1-index
        }
    }
    vll ans = matPow(arr,t);
    --s,--e;
    cout<<ans[s*5][e*5];
}
/*
가중치가 있는 경우에는 어떻게 해야할까요?
만약 두 정점 u, v의 거리가 3이라면, 두 정점 사이에 정점 2개를 추가로 넣어서 가중치가 1인 간선만을 이용해 그래프를 다시 만들 수 있습니다.
이제 구현 방법을 생각해봅시다.
모든 간선에 대해 더미 노드를 넣는다? 정점이 너무 많아지게 됩니다. 네트워크 플로우 문제에서 많이 사용했던 정점 분할 테크닉을 이용합시다.
정점 v를 {v, v1, v2, v3, v4}로 분할을 하고, 간선 (v4, v3), (v3, v2), (v2, v1), (v1, v)를 만들어줍시다.
만약 간선 (u, v)의 거리 dist가 1이라면 그대로 추가를 하고, dist가 1보다 크다면 (u, v(dist-1))을 추가해주면 됩니다.
행렬의 사이즈는 5N이 되고, T번 거듭제곱을 하기 때문에 O(N3logT)라는 효율적인 시간 복잡도로 해결할 수 있습니다.
*/