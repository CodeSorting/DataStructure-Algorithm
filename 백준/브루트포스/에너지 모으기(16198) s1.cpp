#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,res=-1e9,arr[11];
bool visited[11];
void dfs(ll value,int size) {
    if (size==2) {
        res = max(res,value);
        return;
    }
    int one,two;
    for (int i=1;i<n-1;++i) {
        if (visited[i]) continue;
        int j = i+1;
        while (j<n-1 && visited[j]) ++j; one = j;
        j = i-1;
        while (j>0 && visited[j]) --j; two = j;
        int temp = arr[one]*arr[two];
        
        visited[i] = true;
        value += temp;
        dfs(value,size-1);
        visited[i] = false;
        value -= temp;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>arr[i];
    }
    dfs(0,n);
    cout<<res;
}