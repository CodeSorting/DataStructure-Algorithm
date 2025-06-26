#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int k,arr[10000];
vector<int> res[10]; //각 층에 대한 벡터
void dfs(int depth,int st,int ed) {
    if (st>=ed) return;
    int mid = (st+ed)/2;
    res[depth].push_back(arr[mid]);
    dfs(depth+1,st,mid);
    dfs(depth+1,mid+1,ed);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>k;
    int cnt = 1<<k;
    for (int i=0;i<cnt-1;++i) {
        cin>>arr[i];
    }
    dfs(0,0,cnt);
    for (int i=0;i<k;++i) {
        for (int j=0;j<res[i].size();++j) {
            cout<<res[i][j]<<' ';
        }
        cout<<'\n';
    }
}