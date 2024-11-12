#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,cnt=0,temp;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    v.resize(n);
    for (int i=0;i<n;++i) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    while (true) {
        if (v.size()==1) break;
        ++cnt;
        v[v.size()-2] += v[v.size()-1];
        v.pop_back();
        v[0] -= 1;
        if (v[0]==0) v.erase(v.begin());
    }
    cout<<cnt;
}