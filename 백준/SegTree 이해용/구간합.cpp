#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

class SegmentTree {
private:
    vector<ll> tree; //값 저장할 배열
    int n; //배열 사이즈

    void build(vector<ll>& arr, ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = arr[start];  // 리프 노드 저장
        } else {
            int mid = (start + end) / 2;
            build(arr, node * 2, start, mid);
            build(arr, node * 2 + 1, mid + 1, end);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];  // 부모 노드는 자식 노드의 합
        }
    }

    ll query(ll node, ll start, ll end, ll l, ll r) {
        if (r < start || end < l) return 0;  // 범위를 벗어남
        if (l <= start && end <= r) return tree[node];  // 완전히 포함됨
        int mid = (start + end) / 2;
        return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
    }

    void update(ll node, ll start, ll end, ll idx, ll val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(node * 2, start, mid, idx, val);
            } else {
                update(node * 2 + 1, mid + 1, end, idx, val);
            }
            tree[node] = tree[node * 2] + tree[node * 2 + 1];  // 값 갱신
        }
    }
public:
    SegmentTree(vector<ll>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    int query(ll l, ll r) {
        return query(1, 0, n - 1, l, r);
    }

    void update(ll idx, ll val) {
        update(1, 0, n - 1, idx, val);
    }
};

int main() {
    vector<ll> arr = {1, 2, 3, 4, 5};
    SegmentTree segTree(arr);

    cout << "구간 합 (1~3): " << segTree.query(1, 3) << endl;  // 2 + 3 + 4 = 9
    segTree.update(2, 10);  // arr[2] = 10
    cout << "구간 합 (1~3) (업데이트 후): " << segTree.query(1, 3) << endl;  // 2 + 10 + 4 = 16

    return 0;
}
