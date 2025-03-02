#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    private:
        vector<long long> tree;
        int n;
    
        void build(vector<int>& arr, int node, int start, int end) {
            if (start == end) {
                tree[node] = arr[start];
            } else {
                int mid = (start + end) / 2;
                build(arr, node * 2, start, mid);
                build(arr, node * 2 + 1, mid + 1, end);
                tree[node] = tree[node * 2] * tree[node * 2 + 1];
            }
        }
    
        long long query(int node, int start, int end, int l, int r) {
            if (r < start || end < l) return 1; // 곱셈에서 항등원은 1
            if (l <= start && end <= r) return tree[node];
            int mid = (start + end) / 2;
            return query(node * 2, start, mid, l, r) * query(node * 2 + 1, mid + 1, end, l, r);
        }
    
        void update(int node, int start, int end, int idx, int val) {
            if (start == end) {
                tree[node] = val;
            } else {
                int mid = (start + end) / 2;
                if (idx <= mid) {
                    update(node * 2, start, mid, idx, val);
                } else {
                    update(node * 2 + 1, mid + 1, end, idx, val);
                }
                tree[node] = tree[node * 2] * tree[node * 2 + 1];
            }
        }
    
    public:
        SegmentTree(vector<int>& arr) {
            n = arr.size();
            tree.resize(4 * n, 1);
            build(arr, 1, 0, n - 1);
        }
    
        long long query(int l, int r) {
            return query(1, 0, n - 1, l, r);
        }
    
        void update(int idx, int val) {
            update(1, 0, n - 1, idx, val);
        }
};
    