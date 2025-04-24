#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

pair<int,int> taste[11];
int n;
int mindiff = 2147483647;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>taste[i].first>>taste[i].second;
    }
    for (int i=1;i<(1<<n);++i) { //어차피 최대 1024번임.
        int s=1,b=0;
        for (int j=0;j<n;++j) {
            if (i & (1<<j)) {
                s *= taste[j].first;
                b += taste[j].second;
            }
        }
        mindiff = min(mindiff,abs(s-b));
    }
    cout<<mindiff;
}
/* 비트마스킹 없을 경우
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

pair<int,int> taste[11];
int n;
int mindiff = 2147483647;
void dfs(int curs,int curb,int cnt) {
    if (cnt==n) return;
    int nexts = curs*taste[cnt].first;
    int nextb = curb-taste[cnt].second;
    mindiff = min(mindiff,abs(nexts-nextb));
    dfs(nexts,nextb,cnt+1);
    dfs(curs,curb,cnt+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>taste[i].first>>taste[i].second;
    }
    dfs(1,0,0);
    cout<<mindiff;
}
*/