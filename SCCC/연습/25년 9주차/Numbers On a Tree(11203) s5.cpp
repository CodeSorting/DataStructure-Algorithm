#include <iostream>
#include <string>
using namespace std;

int h;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>h;
    long long n = (1<<(h+1))-1;
    long long idx = 1;
    if (cin>>s) {
        int siz = s.size();
        for (int i=0;i<siz;++i) {
            char cur = s[i];
            if (cur=='L') idx = (idx<<1);
            else idx = (idx<<1) + 1;
        }
    }
    cout<<n-idx+1;
}