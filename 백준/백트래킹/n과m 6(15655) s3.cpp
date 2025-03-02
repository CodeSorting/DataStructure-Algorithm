#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,arr[9];
vector<int> v;

void dfs(int cnt,int st) {
    if (cnt==m) { //목표
        for (int i=0;i<m;++i) {
            cout<<v[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    else{
        for (int i=st;i<n;++i) {
            v.push_back(arr[i]);
            dfs(cnt+1,i+1);
            v.pop_back();
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;++i) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    dfs(0,0);
}