#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int n,res=0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while (t--) {
        cin>>n;
        vector<pair<int,int>> v(n);
        unordered_set<int> s[20001];
        for (int i=0;i<n;++i) {
            cin>>v[i].first>>v[i].second;
            v[i].first += 10000;
            v[i].second += 10000;
            s[v[i].first].insert(v[i].second);
        }
        res = 0;
        for (int i=0;i<n;++i) {
            for (int j=i+1;j<n;++j) {
                //두 점 잡고 그 길이 기준으로 정사각형 만들기
                int x1 = v[i].first, y1 = v[i].second;
                int x2 = v[j].first, y2 = v[j].second; 
                int diffx = x1-x2, diffy = y1-y2;
                int x3 = x1+diffy, y3 = y1-diffx;
                int x4 = x2+diffy, y4 = y2-diffx;
                if (x3>20000 || x4>20000 || y3>20000 || y4>20000) continue;
                if (x3<0 || x4<0 || y3<0 || y4<0) continue;
                if (s[x3].find(y3)!=s[x3].end() && s[x4].find(y4)!=s[x4].end()) {
                    res = max(res,diffx*diffx+diffy*diffy);
                }
            }
        }
        cout<<res<<'\n';
    }
}