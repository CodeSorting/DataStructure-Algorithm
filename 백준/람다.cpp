#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
function<void(int,int)> dfs = [&](int depth,int cur) -> void {
    if (depth==v.size()) return;
    cur ^= 1<<depth;
    if (check_uniqueness(cur) && check_minimality(cur)) keys.insert(cur);
    else dfs(depth+1,cur);
    cur ^= 1<<depth;
    dfs(depth+1,cur);
};
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 10;
    vector<int> parent(n+1);
    for (int i=1;i<=n;++i) parent[i] = i;
    function<int(int)> Find = [&](int x) -> int {
        return x==parent[x] ? x : parent[x] = Find(parent[x]);
    };
    auto Union = [&](int a,int b) {
        a = Find(a), b = Find(b);
        a < b ? parent[b] = a : parent[a] = b;
    }
}