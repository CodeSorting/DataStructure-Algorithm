#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k; cin>>k;
    int res = 0;
    for (int i=2;i*i<=k;++i) {
        int cnt = 0;
        while (k%i==0) {
            ++cnt;
            k /= i;
        } 
        res += cnt;
    }
    if (k!=1) ++res; //예외
    int ret = (int)log2(res);
    if (log2(res)==ret) cout<<ret;
    else cout<<ret+1;
}