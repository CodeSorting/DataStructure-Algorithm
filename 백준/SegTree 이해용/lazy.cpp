#include <iostream>
#include <vector>

using namespace std;

class LazySegmentTree {
private:
    vector<int> tree, lazy;
    int n;

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) { // Lazy 값이 있다면 업데이트 수행
            tree[node] += (end - start + 1) * lazy[node]; // 범위 크기만큼 증가
            if (start != end) { // 리프 노드가 아니라면 자식에게 lazy 전파
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0; // 처리 후 초기화
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {
        propagate(node, start, end);

        if (r < start || end < l) return; // 범위 밖이면 무시
        if (l <= start && end <= r) { // 완전히 포함되면 Lazy 처리
            lazy[node] += val;
            propagate(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        updateRange(node * 2, start, mid, l, r, val);
        updateRange(node * 2 + 1, mid + 1, end, l, r, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1]; // 부모 값 갱신
    }

    int queryRange(int node, int start, int end, int l, int r) {
        propagate(node, start, end);

        if (r < start || end < l) return 0; // 범위 밖
        if (l <= start && end <= r) return tree[node]; // 완전히 포함된 경우

        int mid = (start + end) / 2;
        return queryRange(node * 2, start, mid, l, r) +
               queryRange(node * 2 + 1, mid + 1, end, l, r);
    }

public:
    LazySegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, node * 2, start, mid);
            build(arr, node * 2 + 1, mid + 1, end);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    void updateRange(int l, int r, int val) {
        updateRange(1, 0, n - 1, l, r, val);
    }

    int queryRange(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    LazySegmentTree segTree(arr);

    cout << "구간 합 (0~4): " << segTree.queryRange(0, 4) << endl; // 1+2+3+4+5 = 15
    segTree.updateRange(1, 3, 2); // 1~3 구간에 +2
    cout << "구간 합 (0~4) (업데이트 후): " << segTree.queryRange(0, 4) << endl; // 1+4+5+6+5 = 21

    return 0;
}
