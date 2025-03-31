#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll; //주의점 : XOR을 짝수번 하면 XOR 안한거랑 똑같으니 (end-start+1)%2==1일 때만 xor한다.

//init(a, tree, 1, 0, n-1);
void init(vector<ll> &a, vector<ll> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        ll mid = (start+end)/2;
        init(a, tree, node<<1, start, mid);
        init(a, tree, (node<<1)+1, mid+1, end);
        tree[node] = (tree[node<<1] ^ tree[(node<<1)+1]); 
    }
}
void update_lazy(vector<ll> &tree, vector<ll> &lazy, int node, int start, int end) {
    if (lazy[node] != 0) { //업데이트 안된게 있다면 딱 자식까지만 업데이트
        if ((end-start+1)%2==1) tree[node] ^= lazy[node]; //홀수번째에만 XOR 연산
        if (start != end) { //자식이 있다면 업데이트
            lazy[node<<1] ^= lazy[node];
            lazy[(node<<1)+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}
//update_range(tree, lazy, 1, 0, n-1, left-1, right-1, diff);
void update_range(vector<ll> &tree, vector<ll> &lazy, int node, int start, int end, int left, int right, ll diff) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        if ((end-start+1)%2==1) tree[node] ^= diff; //홀수번째에만 XOR 연산
        if (start != end) { //자식이 있다면 업데이트
            lazy[node<<1] ^= diff;
            lazy[(node<<1)+1] ^= diff;
        }
        return;
    }
    int mid = (start+end)/2;
    update_range(tree, lazy, node<<1, start, mid, left, right, diff);
    update_range(tree, lazy, (node<<1)+1, mid+1, end, left, right, diff);
    tree[node] = (tree[node<<1] ^ tree[(node<<1)+1]);
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
    return (lsum ^ rsum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin>>n;
    vector<ll> a(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<ll> tree(tree_size);
    vector<ll> lazy(tree_size);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    init(a, tree, 1, 0, n-1); // 초기 구성
    cin>>m;
    while (m--) {
        int what;
        cin >> what;
        if (what == 1) {
            int left, right;
            ll diff;
            cin >> left >> right >> diff;
            update_range(tree, lazy, 1, 0, n-1, left, right, diff);
        } else if (what == 2) {
            int left, right;
            cin >> left >> right;
            cout << query(tree, lazy, 1, 0, n-1, left, right) << '\n';
        }
    }
    return 0;
}
