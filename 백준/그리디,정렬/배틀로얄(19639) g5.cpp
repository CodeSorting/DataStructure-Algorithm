#include <iostream>
#include <vector>
using namespace std;

int x, y, m;
int enemy[100001], hp[100001];
vector<int> res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> x >> y >> m;
    for (int i = 1; i <= x; ++i) cin >> enemy[i];
    for (int i = 1; i <= y; ++i) cin >> hp[i];
    int curhp = m;
    int j = 1;
    for (int i = 1; i <= x; ++i) {
        // 적을 상대할 수 없는 상태면, 아이템 먹자
        while (curhp <= enemy[i] && j <= y) {
            curhp += hp[j];
            if (curhp > m) curhp = m; // 최대 체력 초과 방지
            res.push_back(j); // 아이템 먹은 행동
            ++j;
        }
        if (curhp <= enemy[i]) {
            cout << 0;
            return 0;
        }
        curhp -= enemy[i];
        res.push_back(-i);
    }
    while (j <= y) {
        curhp += hp[j];
        if (curhp > m) curhp = m;
        res.push_back(j);
        ++j;
    }

    for (int act : res) cout << act << '\n';
}