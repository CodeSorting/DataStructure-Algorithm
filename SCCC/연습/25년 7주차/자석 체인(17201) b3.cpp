#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    bool isConnected = true,flag;
    int n; cin>>n;
    char ch; cin>>ch;
    if (ch=='1') flag = true;
    else flag = false;
    for (int i=1;i<(n<<1);++i) {
        cin>>ch;
        if (flag) {
            if (ch=='1') {
                isConnected = false;
                break;
            }
            flag = false;
        }
        else {
            if (ch=='2') {
                isConnected = false;
                break;
            }
            flag = true;
        }
    }
    if (isConnected) cout<<"Yes";
    else cout<<"No";
}