#include <iostream>
using namespace std;
typedef long long ll;
ll n,a,b,res[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    char op;
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>a>>op>>b;
        if (op=='+') {
            int cur = a+b;
            if (i==0) res[i] = cur - 1;
            else res[i] = cur - res[i-1];
        }
        else if (op=='-') {
            int cur = a-b;
            if (i==0) res[i] = cur;
            else res[i] = cur * res[i-1];
        }
        else if (op=='*') {
            res[i] = a*a*b*b;
        }
        else {
            if (a%2) res[i] = (a+1)/2;
            else res[i] = a/2;
        }
    }
    for (int i=0;i<n;++i) {
        cout<<res[i]<<'\n';
    }   
}