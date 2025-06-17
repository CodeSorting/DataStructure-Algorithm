#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int n,m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    vector<int> v1,v2;
    int how_exchange = 0;
    if (n>m) how_exchange = 1;
    char a = '0'+how_exchange;
    for (int i=0;i<s.size();++i) {
        if (s[i]==a) v1.push_back(i);
        if (t[i]==a) v2.push_back(i);
    }
    ll cnt1=0,cnt2=0;
    for (int i=0;i<min(n,m);++i) {
        ll a = v1[i],b = v2[i];
        ll diff = abs(b-a);
        if (diff%2) {
            if (cnt1>cnt2) {
                cnt1 += (diff-1)/2;
                cnt2 += (diff+1)/2; 
            }
            else {
                cnt1 += (diff+1)/2;
                cnt2 += (diff-1)/2;
            }
        }
        else {
            cnt1 += diff/2;
            cnt2 += diff/2;
        }
    }
    cout<<cnt1*cnt1+cnt2*cnt2;
}