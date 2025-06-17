#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    if (x < n || x > 26 * n)
    {
        cout << "!";
        return 0;
    }
    string res = "";
    for (int i = 0; i < n; ++i)
    {
        int remaining = n - i - 1;
        for (int val = 1; val <= 26; ++val)
        {
            if (x - val <= remaining * 26 && x - val >= remaining)
            {
                res += (char)('A' + val - 1);
                x -= val;
                break;
            }
        }
    }
    cout << res;
}