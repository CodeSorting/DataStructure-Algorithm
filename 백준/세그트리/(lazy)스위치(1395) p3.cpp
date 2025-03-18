#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll; //구간 합 구하기

void update_lazy(vector<ll> &tree, vector<ll> &lazy, int node, int start, int end) {
    if (lazy[node] != 0) { //업데이트 안된게 있다면 딱 자식까지만 업데이트
        tree[node] = (end-start+1)-tree[node];
        if (start != end) { 
            lazy[node<<1] = !lazy[node<<1];
            lazy[(node<<1)+1] = !lazy[(node<<1)+1];
        }
        lazy[node] = 0;
    }
}
//업데이트가 다름.
void update_range(vector<ll> &tree, vector<ll> &lazy, int node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        tree[node] = (end-start+1) - tree[node];
        if (start != end) {
            lazy[(node<<1)] = !lazy[(node<<1)]; //반전 시키기
            lazy[(node<<1)+1] = !lazy[(node<<1)+1];
        }
        return;
    }
    int mid = (start+end)/2;
    update_range(tree, lazy, (node<<1), start, mid, left, right);
    update_range(tree, lazy, (node<<1)+1, mid+1, end, left, right);
    tree[node] = tree[node<<1] + tree[(node<<1)+1];
}
//query(tree, lazy, 1, 0, n-1, left-1, right-1)
ll query(vector<ll> &tree, vector<ll> &lazy, int node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start+end)/2;
    ll lsum = query(tree, lazy, node<<1, start, mid, left, right);
    ll rsum = query(tree, lazy, (node<<1)+1, mid+1, end, left, right);
    return lsum + rsum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<ll> tree(tree_size);
    vector<ll> lazy(tree_size);
    //init(a, tree, 1, 0, n-1); 초기 구성이 필요 없음.
    while (m--) {
        int what;
        cin >> what;
        if (what == 0) {
            int left, right;
            ll diff;
            cin >> left >> right;
            update_range(tree, lazy, 1, 0, n-1, left-1, right-1);
        } else {
            int left, right;
            cin >> left >> right;
            cout << query(tree, lazy, 1, 0, n-1, left-1, right-1) << '\n';
        }
    }
    return 0;
}
