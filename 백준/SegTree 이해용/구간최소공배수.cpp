#include <iostream>
#include <vector>
#include <numeric> // std::lcm 사용 (C++17부터라 안됨.)
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b; // 곱하기 전에 나눠서 오버플로 방지
}

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
            tree[node] = lcm(tree[node * 2], tree[node * 2 + 1]); // 최소 공배수 저장
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 1; // LCM 연산의 항등원은 1
        if (l <= start && end <= r) return tree[node]; // 완전히 포함된 경우
        int mid = (start + end) / 2;
        return lcm(query(node * 2, start, mid, l, r),
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
            tree[node] = lcm(tree[node * 2], tree[node * 2 + 1]); // 부모 노드 갱신
        }
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, 1);
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
    vector<int> arr = {2, 3, 4, 5, 6};
    SegmentTree segTree(arr);

    cout << "구간 최소 공배수 (1~3): " << segTree.query(1, 3) << endl; // 3, 4, 5의 LCM = 60
    segTree.update(2, 10); // arr[2] = 10
    cout << "구간 최소 공배수 (1~3) (업데이트 후): " << segTree.query(1, 3) << endl; // 3, 10, 5의 LCM = 30

    return 0;
}
