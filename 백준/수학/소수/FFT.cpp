#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);

// FFT 구현
void fft(vector<cd> &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (cd &x : a) x /= n;
    }
}

// 큰 수 곱셈
vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);
    
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);
    
    vector<int> result(n);
    for (int i = 0; i < n; i++) result[i] = round(fa[i].real());
    
    // 자리 올림 처리
    for (int i = 0; i < n - 1; i++) {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }
    
    while (result.size() > 1 && result.back() == 0) result.pop_back();
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string sa, sb;
    cin>>sa>>sb;
    vector<int> a, b;
    // 숫자를 벡터로 변환 (뒤집어서 저장)
    for (int i=sa.size()-1;i>=0;--i) a.push_back(sa[i] - '0');
    for (int i=sb.size()-1;i>=0;--i) b.push_back(sb[i] - '0');

    vector<int> result = multiply(a, b);
    
    // 결과 출력 (뒤집어서 출력)
    for (auto it = result.rbegin(); it != result.rend(); it++) cout << *it;
}
