#include <iostream>
using namespace std;

int siz,n,m,cnt=0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>siz>>n>>m;
    int temp;
    for (int i=0;i<n+m;++i) {
        cin>>temp;
        if (temp) {
            ++cnt;
            if (cnt>siz) siz <<= 1;
        }
        else --cnt;
    }
    cout<<siz;
}