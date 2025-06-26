#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> p;
int n,D[101],ans;
bool cmp(p &a,p &b) {
    if (a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<pair<int,int>> v;
    v.resize(n);
    for (int i=0;i<n;++i) {
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end(),cmp);
    for (int i=0;i<n;++i){
        D[i] = 1;
        for (int j=0;j<i;++j){
            if (v[i].second>v[j].second){
                D[i] = max(D[i],D[j]+1);
            }
        }
    }
    for (int i=0;i<n;++i){
        ans = max(ans,D[i]);
    }
    cout<<n-ans; //A를 정렬한 상태에서 B의 LIS를 구한 값이 끊지 않고 연결 가능한 최대 전깃줄 개수이니 n-ans가 끊어야할 최소 개수이다.
}