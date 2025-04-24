#include <iostream>
#include <cmath>
using namespace std;
typedef long double ld;
int arr[1001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m; cin>>m;
    ld temp;
    while (cin>>temp) {
        temp += 1e-9;
        ++arr[m*(int)(temp*1000000) / 1000000];
    }
    for (int i=0;i<m;++i) {
        cout<<arr[i]<<' ';
    }
}