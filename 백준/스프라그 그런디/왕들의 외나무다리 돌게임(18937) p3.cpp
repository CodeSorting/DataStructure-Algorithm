#include <iostream>
using namespace std;
typedef long long ll;

int n;
string s;
/*
스프라그 그런디 정리
그런디 수
1 -> 불가능
2 -> 0
3 -> 1
4 -> 1칸 앞으로(1), 2칸 앞으로(0) -> 2
5 -> 1칸 앞으로(2), 2칸 앞으로(1), 3칸 앞으로(0) -> 4
그런디 수 = temp-2
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ll res = 0;
    ll temp;
    for (int i=0;i<n;++i) {
        cin>>temp;
        res ^= (temp-2);
    }
    cin>>s;
    if (s=="Blackking") {
        if (res) cout<<"Blackking";
        else cout<<"Whiteking";
    }
    else {
        if (res) cout<<"Whiteking";
        else cout<<"Blackking";
    }
}