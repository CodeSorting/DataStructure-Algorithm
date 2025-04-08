#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int res = 0,temp;
    for (int i=0;i<n;++i) {
        cin>>temp;
        res ^= temp;
    }
    if (res!=0) cout<<"koosaga";
    else cout<<"cubelover";
    return 0;
}