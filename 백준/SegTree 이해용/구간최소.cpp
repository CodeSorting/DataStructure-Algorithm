#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start]; // 리프 노드
        } else {
            int mid = (start + end) / 2;
            build(arr, node * 2, start, mid);
            build(arr, node * 2 + 1, mid + 1, end);
            tree[node] = min(tree[node * 2], tree[node * 2 + 1]); // 부모는 최솟값 저장
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return INT_MAX; // 범위 밖
        if (l <= start && end <= r) return tree[node]; // 완전히 포함된 경우
        int mid = (start + end) / 2;
        return min(query(node * 2, start, mid, l, r),
                   query(node * 2 + 1, mid + 1, end, l, r));
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val; // 값 변경
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(node * 2, start, mid, idx, val);
            } else {
                update(node * 2 + 1, mid + 1, end, idx, val);
            }
            tree[node] = min(tree[node * 2], tree[node * 2 + 1]); // 값 갱신
        }
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, INT_MAX);
        build(arr, 1, 0, n - 1);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
};

int main() {
    vector<int> arr = {5, 2, 6, 3, 7, 1};
    SegmentTree segTree(arr);

    cout << "구간 최솟값 (1~4): " << segTree.query(1, 4) << endl; // 2
    segTree.update(3, 0); // arr[3] = 0
    cout << "구간 최솟값 (1~4) (업데이트 후): " << segTree.query(1, 4) << endl; // 0

    return 0;
}
