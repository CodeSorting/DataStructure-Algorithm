#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while (t--) {
        int n,l,r;
        cin>>n>>l>>r;
        l--; r--;
        vector<ll> a(n);
        for (int i=0;i<n;++i) cin>>a[i];
        int m = r-l+1;
        vector<ll> rarr(a.begin()+l,a.end());
        vector<ll> larr(a.begin(),a.begin()+r+1);
        sort(larr.begin(),larr.end());
        sort(rarr.begin(),rarr.end());
        ll lsum = 0, rsum = 0;
        for (int i=0;i<m;++i) {
            lsum += larr[i];
        }
        for (int i=0;i<m;++i) {
            rsum += rarr[i];
        }
        cout<<min(lsum,rsum)<<'\n';
    }
}
