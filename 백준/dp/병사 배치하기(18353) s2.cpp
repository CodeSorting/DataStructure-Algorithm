#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,A[2001],D[2001],ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>A[i];
    }
    for (int i=0;i<n;++i) {
        D[i] = 1;
        for (int j=0;j<i;++j) {
            if (A[i]<A[j]) {
                D[i] = max(D[i],D[j]+1);
            }
        }
    }
    for (int i=0;i<n;++i) ans = max(ans,D[i]);
    cout<<n-ans;
}