#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string ban[10] = {"i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"};
string s,ans;
string arr[102];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt=0;
    while (cin>>s) {
        arr[cnt]=s;++cnt; //cnt=size
    }
    ans += arr[0][0];

    for (int i=1;i<cnt;++i) {
        bool isBan = false;
        for (int j=0;j<10;++j) {
            if (arr[i]==ban[j]) isBan = true;
        }
        if (!isBan) ans += arr[i][0];
    }
    transform(ans.begin(), ans.end(), ans.begin(), ::toupper);
    cout<<ans;
}