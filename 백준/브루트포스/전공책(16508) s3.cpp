#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[26],n,selected[26];
pair<int,string> p[16];
const int INF = 1e9+7;
int ans = 1e9+7;

bool isPossible() { // 개수가 충분한지
    for (int i=0;i<26;++i) {
        if (arr[i]>selected[i]) return false;
    }
    return true;
}

void dfs(int cnt,int money) {
    if (cnt==n) {
        if (isPossible()) ans = min(ans,money);
        return;
    }
    int price = p[cnt].first;
    for (int i=0;i<p[cnt].second.length();++i) {
        ++selected[p[cnt].second[i] - 'A']; // 선택했을 때
    }
    dfs(cnt+1,money+price);
    for (int i=0;i<p[cnt].second.length();++i) {
        --selected[p[cnt].second[i] - 'A']; // 취소하고 선택 안했을 때를 본다.
    }
    dfs(cnt+1,money);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    for (int i=0;i<s.size();++i) ++arr[s[i]-'A'];

    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>p[i].first>>p[i].second;
    }
    dfs(0,0);

    if (ans==INF) cout<<-1;
    else cout<<ans;
}