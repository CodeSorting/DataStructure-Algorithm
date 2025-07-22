#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

bool removeOne(ll &x) {
    string s = to_string(x);
    size_t pos = s.find('1');
    if (pos == string::npos) return false;

    s.erase(pos, 1);
    // 남은 문자열이 다 0으로 시작하면 한 글자만 남기거나(= "0") 아니면 선행 0 제거
    size_t nz = s.find_first_not_of('0');
    if (nz == string::npos) {
        s = "0";
    } else {
        s = s.substr(nz);
    }
    x = stoll(s);
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    ll ans = 0;
    while (n > 0) {
        //맨 왼쪽부터 1을 빼면 된다.
        if (!removeOne(n)) {
            --n;
        }
        ++ans;
    }
    cout<<ans;
}
