#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,cnt[10001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int temp;
    for (int i=0;i<n;++i) {
        cin>>temp;
        ++cnt[temp];
    }
    ll res1=1e15,res2=1e15;
    ll Max = 1e15;
    for (int i=1;i<=10000;++i) {
        ll sum = 0;
        for (int j=1;j<=10000;++j) {
            sum += cnt[j] * abs(i-j);
        }
        if (sum<Max) {
            Max = sum;
            res1 = i;
        }
    }
    Max = 1e15;
    for (int i=1;i<=10000;++i) {
        ll sum = 0;
        for (int j=1;j<=10000;++j) {
            sum += cnt[j] * (i-j) * (i-j);
        }
        if (sum<Max) {
            Max = sum;
            res2 = i;
        }
    }
    cout<<res1<<' '<<res2;
}