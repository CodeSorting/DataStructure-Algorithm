#include <iostream>
#include <algorithm>
using namespace std;
int factorys[1000003];
int n;
long long ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int B,C;
    cin>>n>>B>>C;
    for (int i=1;i<=n;++i) cin >> factorys[i];
    if (C >= B) {
        // 묶음보다 단품이 더 싸거나 같으면 전부 단품으로 처리
        for (int i = 1; i <= n; ++i) {
            ans += (long long)factorys[i] * B;
        }
    }
    else {
        for (int i=1;i<=n;++i) {
            // Case 1: i+1 > i+2 -> 두 공장 묶음을 먼저 처리
            if (factorys[i+1] > factorys[i+2]) {
                int two = min(factorys[i], factorys[i+1] - factorys[i+2]);
                factorys[i] -= two;
                factorys[i+1] -= two;
                ans += (long long)two * (B + C);
            }

            // Case 2: 세 공장 묶음 처리
            int three = min({factorys[i], factorys[i+1], factorys[i+2]});
            factorys[i] -= three;
            factorys[i+1] -= three;
            factorys[i+2] -= three;
            ans += (long long)three * (B + 2 * C);

            // Case 3: 남은 두 공장 묶음 처리
            int two = min(factorys[i], factorys[i+1]);
            factorys[i] -= two;
            factorys[i+1] -= two;
            ans += (long long)two * (B + C);

            // Case 4: 단품 처리
            ans += (long long)factorys[i] * B;
            factorys[i] = 0;
        }
    }
    cout<<ans;
}
