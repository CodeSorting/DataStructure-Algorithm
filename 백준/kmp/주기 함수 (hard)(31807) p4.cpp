#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
ll p,A[300005],hap[300005],a,b,ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>p;
    for (int i=0;i<p;++i) cin>>A[i];
    
    //kmp 알고리즘으로 주기 찾기
    vector<int> pi(p, 0);
    for (int i=1;i<p;++i) {
        int j = pi[i-1];
        while (j>0 && A[i]!=A[j]) j = pi[j-1];
        if (A[i]==A[j]) pi[i] = ++j;
    }
    int jugi = p - pi[p-1]; //주기 변수
    
    //구간 합
    hap[0] = A[0];
    for (int i=1;i<jugi;++i) hap[i] = hap[i-1] + A[i];
    cin>>a>>b;
    if (a==b) { cout<<0; return 0; }
    if (b-a>=jugi) {
        ans += (b-a)/jugi * hap[jugi-1];
        a += (b-a)/jugi * jugi;
    }
    while (a<=0 || b<=0) {
        a += jugi;
        b += jugi;
    }
    for (int i=a;i<b;++i) {
        ans += A[i%jugi];
    }
    cout<<ans;
}