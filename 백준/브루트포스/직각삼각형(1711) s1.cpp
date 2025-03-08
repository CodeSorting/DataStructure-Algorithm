#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Point {
    ll x, y;
};

ll dist(ll x1, ll y1, ll x2, ll y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    Point points[1501];
    for (int i=0;i<n;++i) {
        cin >> points[i].x >> points[i].y;
    }
    
    int cnt = 0;
    for (int i=0;i<n-2;++i) {
        for (int j=i+1;j<n-1;++j) {
            for (int k=j+1;k<n;++k) {
                ll d1 = dist(points[i].x, points[i].y, points[j].x, points[j].y);
                ll d2 = dist(points[j].x, points[j].y, points[k].x, points[k].y);
                ll d3 = dist(points[i].x, points[i].y, points[k].x, points[k].y);
                if (d1 + d2 == d3 || d1 + d3 == d2 || d2 + d3 == d1) {
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<"\n";
}
