#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll; //특정 원소값 구하기

void init(vector<ll> &a,vector<ll> &tree,int node,int start,int end) {
    if (start==end) tree[node] = a[start];
    else {
        int mid = (start+end)/2;
        init(a,tree,node<<1,start,mid);
        init(a,tree,(node<<1)+1,mid+1,end);
        tree[node] = tree[node<<1] + tree[(node<<1) + 1];
    }
}
void update_lazy(vector<ll> &tree,vector<ll> &lazy,int node,int start,int end) {
    if (lazy[node]!=0) {
        tree[node] += (end-start+1)*lazy[node];
        if (start!=end) {
            lazy[node<<1] += lazy[node];
            lazy[(node<<1) + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
void update_range(vector<ll> &tree,vector<ll> &lazy,int node,int start,int end,int left,int right,ll diff) {
    update_lazy(tree,lazy,node,start,end);
    if (left>end || right<start) return;
    if (left<=start && end<=right) {
        tree[node] += (end-start+1)*diff;
        if (start!=end) {
            lazy[node<<1] += diff;
            lazy[(node<<1) + 1] += diff;
        }
        return;
    }
    int mid = (start+end)/2;
    update_range(tree,lazy,node<<1,start,mid,left,right,diff);
    update_range(tree,lazy,(node<<1)+1,mid+1,end,left,right,diff);
    tree[node] = tree[node<<1] + tree[(node<<1) + 1];
}
ll query(vector<ll> &tree,vector<ll> &lazy,int node,int start,int end,int left,int right) {
    update_lazy(tree,lazy,node,start,end);
    if (left > end || right < start) return 0; //범위 x
    if (left<=start && end<=right) return tree[node]; //완전히 포함
    int mid = (start+end)/2;
    return query(tree,lazy,node<<1,start,mid,left,right) + query(tree,lazy,(node<<1)+1,mid+1,end,left,right);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n;
    vector<ll> a(n);
    for (int i=0;i<n;++i) cin>>a[i];
    int h = (int)ceil(log2(n))+1;
    int tree_size = (1<<h);
    vector<ll> tree(tree_size);
    vector<ll> lazy(tree_size);
    init(a,tree,1,0,n-1);
    cin>>m;
    while (m--) {
        int what;
        cin>>what;
        if (what==1) {
            int left,right,diff;
            cin>>left>>right>>diff;
            update_range(tree,lazy,1,0,n-1,left-1,right-1,diff);
        }
        else {
            int idx;
            cin>>idx;
            cout<<query(tree,lazy,1,0,n-1,idx-1,idx-1)<<'\n';
        }
    }
}