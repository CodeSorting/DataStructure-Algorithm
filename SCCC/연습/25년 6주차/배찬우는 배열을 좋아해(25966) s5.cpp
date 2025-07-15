#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,q;
int arr[3001][3001];
int idx[3001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>q;
    
    for (int i=0;i<n;++i) {
        idx[i] = i;
        for (int j=0;j<m;++j) {
            cin>>arr[i][j];
        }
    }       
    for (int i=0;i<q;++i) {
        int query; cin>>query;
        if (query) {
            int a,b; cin>>a>>b;
            swap(idx[a],idx[b]);
        }
        else {
            int a,b,c; cin>>a>>b>>c;
            arr[idx[a]][b] = c;
        }
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) 
            cout<<arr[idx[i]][j]<<' ';
        cout<<'\n';
    }
}