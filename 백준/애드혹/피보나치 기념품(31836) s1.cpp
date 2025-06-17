#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<int> A,B;
    if (n<3) {
        A.push_back(1);
        B.push_back(2);
    }
    else {
        while (n>=3) {
            A.push_back(n);
            B.push_back(n-1); B.push_back(n-2);
            n -= 3;
        }
        if (n%3==2) {
            A.push_back(2);
            B.push_back(1);
        }
    }
    cout<<A.size()<<'\n';
    for (int i=0;i<A.size();++i) cout<<A[i]<<' ';
    cout<<'\n';
    cout<<B.size()<<'\n';
    for (int i=0;i<B.size();++i) cout<<B[i]<<' ';
}