#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,temp,temp2,goal;
const int ENF = 987654321;
bool visited[11];
vector<int> v[11];
vector<int> st;
int ans = ENF;
//백트래킹
void dfs(int cur,int time) {
    visited[cur] = true;
    for (int i=0;i<v[cur].size();++i) {
        if (v[cur][i]==goal) {
            ans = min(ans,time);
            visited[cur] = false;
            return;
        }
        for (int j=0;j<n;++j) {
            if (j==cur) continue;
            for (int k=0;k<v[j].size();++j) {
                if (!visited[j] && v[j][k]==v[cur][i]) {
                    dfs(j,time+1);
                }
            }
        }
    }
    visited[cur] = false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>temp;
        for (int j=0;j<temp;++j) {
            cin>>temp2;
            v[i].push_back(temp2);
            if (!temp2) {
                st.push_back(i);
            }
        }
    }
    cin>>goal;
    for (int i=0;i<st.size();++i) {
        dfs(st[i],0);
    }
    if (ans==ENF) cout<<-1;
    else cout<<ans;
}