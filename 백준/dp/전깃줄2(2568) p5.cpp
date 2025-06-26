#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<pair<int,int>> v(n);
    for (int i=0;i<n;++i) {
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    vector<int> idx,ans,lis;
    lis.push_back(v[0].second);
    idx.push_back(0);
    for (int i=1;i<n;++i) {
        int cur = v[i].second;
        if (lis.back()<cur) {
            lis.push_back(cur);
            idx.push_back(lis.size()-1);
        }
        else {
            int lower = lower_bound(lis.begin(),lis.end(),cur) - lis.begin();
            lis[lower] = cur;
            idx.push_back(lower);
        }
    }
    cout<<v.size()-lis.size()<<'\n';

    int now = lis.size()-1; //역추적
    for (int i=idx.size()-1;i>=0;--i) {
        if (now==idx[i]) --now; //정확히 들어맞음. 제거할 필요 X
        else ans.push_back(v[i].first); //제거 대상
    }

    sort(ans.begin(),ans.end());
    for (int i : ans) cout<<i<<'\n';
}
/*
인덱스 i:   0   1   2   3   4   5   6   7
B 값:       8   2   9   1   4   6   7  10
idx = [0, 0, 1, 0, 1, 2, 3, 4]
[8]	0
1	2	[2]	0
2	9	[2,9]	1
3	1	[1,9]	0
4	4	[1,4]	1
5	6	[1,4,6]	2
6	7	[1,4,6,7]	3
7	10	[1,4,6,7,10] 4
*/