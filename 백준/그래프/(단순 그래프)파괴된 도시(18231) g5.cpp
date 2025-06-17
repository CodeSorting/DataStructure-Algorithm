#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m, k;
vector<int> map[2001];
bool city[2001];
bool visited[2001];
vector<int> res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        map[u].push_back(v);
        map[v].push_back(u);
    }
    cin >> k;
    int temp;
    for (int i = 0; i < k; ++i) {
        cin >> temp;
        city[temp] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        bool flag = true;
        if (!city[i]) continue;
        for (int next : map[i]) {
            if (!city[next])
                flag = false;
        }
        if (flag) {
            visited[i] = true;
            for (int next : map[i])
                visited[next] = true;
            res.push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (city[i] && !visited[i]) {
            cout << -1;
            return 0;
        }
    }
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << ' ';
}