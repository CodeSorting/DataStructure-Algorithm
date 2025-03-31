#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a1,a0,c1,c2,n0;
    cin>>a1>>a0>>c1>>c2>>n0;
    int fn0 = a1*n0 + a0;
    int gn0_left = c1*n0;
    int gn0_right = c2*n0;
    if (gn0_left<=fn0 && gn0_right>=fn0) cout<<1;
    else cout<<0;
}