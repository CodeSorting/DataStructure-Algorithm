#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int n,m,h;
int hy,hx;//집의 위치
int ans;
vector<pair<int, int>> point; //우유 위치들을 모아 놓고 하나씩 브루트포스로 방문. (but 거리로 백트래킹.)
bool visited[10];
void recur(int y, int x, int hp,int milk) {
    int go_home = abs(x - hx) + abs(y - hy);
    if (hp >= go_home) {
        ans = max(ans, milk);
    }
    for (int i=0;i<point.size();++i) {
        int need_hp = abs(y-point[i].first) + abs(x-point[i].second);
        if (visited[i]) continue;
        if (hp < need_hp) continue; //못 가는 경우
        
        visited[i] = true;
        recur(point[i].first, point[i].second, hp - need_hp + h,milk+1);
        visited[i] = false;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>h;
    int tmp;
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            cin>>tmp;
            if (tmp==1) {
                hy=i;
                hx=j;
            }
            else if (tmp==2) {
                point.push_back(make_pair(i, j));
            }
        }
    }
    recur(hy,hx,m,0); //집에서 출발
    cout<<ans;
}