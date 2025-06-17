#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll n, m;
ll arr[200001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    while (true)
    {
        ll sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (m >= sum + arr[i])
                sum += arr[i];
        }
        if (sum == 0)
            break;
        m %= sum;
    }
    cout << m;
}