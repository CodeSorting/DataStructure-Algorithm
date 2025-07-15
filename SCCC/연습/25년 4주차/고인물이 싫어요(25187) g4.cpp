#include <iostream>
#include <algorithm>
using namespace std;

int n,m,q;
int parent[100001],clean[100001],dirty[100001];
int find(int a) {
    if (parent[a]<0) return a;
    return parent[a] = find(parent[a]);
}

void Union(int a,int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa!=pb) {
        if (pa>pb) swap(pa,pb);
        clean[pa] += clean[pb];
        dirty[pa] += dirty[pb];
        parent[pb] = pa;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i=0;i<100001;++i) {
        parent[i] = -1;
    }
    cin>>n>>m>>q;
    int water;
    for (int i=1;i<=n;++i) {
        cin>>water;
        if (water) clean[i]++;
        else dirty[i]++;
    }
    int a,b;
    for (int i=0;i<m;++i) {
        cin>>a>>b;
        Union(a,b);
    }
    for (int i=0;i<q;++i) {
        cin>>a;
        a = find(a);
        if (clean[a]>dirty[a]) cout<<"1\n";
        else cout<<"0\n";
    }
}