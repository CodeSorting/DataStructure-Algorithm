#include <iostream>
using namespace std;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin>>s;
        if (s=="0") break;
        char cur = s[0];
        int cnt = 1;
        for (int i=1;i<s.size();++i) {
            if (cur==s[i]) {
                ++cnt;
            }
            else {
                cout<<cnt<<cur;
                cnt = 1;
                cur = s[i];
            }
        }
        cout<<cnt<<cur;
        cout<<'\n';
    }
}