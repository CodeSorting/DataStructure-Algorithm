#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define double long double
using namespace std;
typedef long long ll;
const double eps = 1e-9;

double f(ll A, ll B, ll C, ll D, double x) {
    return A * x * x * x + B * x * x + C * x + D;
}

double find_integer_root(ll A, ll B, ll C, ll D) {
    for (ll i = -1000000; i <= 1000000; i++) {
        if (f(A, B, C, D, i) == 0) {
            return i;
        }
    }
    return 0; // 정수해를 문제에서 보장해줌.
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin>>N;
    while (N--) {
        ll A, B, C, D;
        cin>>A>>B>>C>>D;
        double x1 = find_integer_root(A, B, C, D); // 정수해 하나 찾기

        ll B2 = B + A * x1; // 조립제법
        ll C2 = C + B2 * x1;

        ll D2 = B2 * B2 - 4 * A * C2; // 판별식
        vector<double> roots = {x1}; // 정수 해 추가

        if (D2 >= 0) {
            double x2 = (-B2 - sqrt((double)D2)) / (2.0 * A);
            double x3 = (-B2 + sqrt((double)D2)) / (2.0 * A);
            roots.push_back(x2);
            roots.push_back(x3);
        }

        sort(roots.begin(), roots.end());
        roots.erase(unique(roots.begin(), roots.end(), 
            [](double a, double b) { return fabs(a - b) < eps; }), roots.end()); // 중복 제거, 정렬
        for (double root : roots) {
            cout<<root<<' ';
        }
        cout<<'\n';
    }
}
