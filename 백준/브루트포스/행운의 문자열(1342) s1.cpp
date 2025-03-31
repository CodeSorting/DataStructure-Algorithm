#include <iostream>
#include <algorithm>
using namespace std;

string s;
int arr[27],cnt=0;
void dfs(int idx,string cur) {
    if (idx==s.size()) {
        ++cnt;
        return;
    }
    for (int i=0;i<26;++i) {
        if (arr[i]==0) continue;
        if (cur!="" && cur[cur.size()-1]==(char)('a'+i)) continue; //마지막 + 추가 글자가 같으면 안됨.
        --arr[i];
        dfs(idx+1,cur+(char)('a'+i));
        ++arr[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    for (int i=0;i<s.size();++i) {
        ++arr[s[i]-'a'];
    }
    dfs(0,"");
    cout<<cnt;
}