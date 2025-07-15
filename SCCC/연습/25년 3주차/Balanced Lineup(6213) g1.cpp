#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int N, Q;
vector<int> heights;
vector<int> minTree, maxTree;

// 세그먼트 트리 초기화
void build(int node, int start, int end) {
    if (start == end) {
        minTree[node] = maxTree[node] = heights[start];
    } else {
        int mid = (start + end) / 2;
        build((node<<1), start, mid);
        build((node<<1) + 1, mid + 1, end);
        minTree[node] = min(minTree[node<<1], minTree[(node<<1) + 1]);
        maxTree[node] = max(maxTree[node<<1], maxTree[(node<<1) + 1]);
    }
}

// 구간 [L, R]에서 최소값과 최대값을 구함
pair<int, int> query(int node, int start, int end, int L, int R) {
    if (R < start || end < L) return {INF, -INF}; // 범위를 벗어난 경우
    if (L <= start && end <= R) return {minTree[node], maxTree[node]}; // 완전히 포함되는 경우

    int mid = (start + end) / 2;
    auto left = query(node * 2, start, mid, L, R);
    auto right = query(node * 2 + 1, mid + 1, end, L, R);
    return {min(left.first, right.first), max(left.second, right.second)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>Q;
    heights.resize(N);
    minTree.resize(4 * N);
    maxTree.resize(4 * N);
    for (int i=0;i<N;++i) {
        cin>>heights[i];
    }
    build(1, 0, N - 1);
    while (Q--) {
        int A, B;
        cin>>A>>B;
        --A; --B; // 0-based index
        auto res = query(1,0,N-1,A,B);
        cout <<res.second - res.first<<'\n';
    }
}
