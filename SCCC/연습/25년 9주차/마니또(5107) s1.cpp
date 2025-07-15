#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string,string> m;
unordered_map<string,bool> visited;
int cnt = 0;
int k = 1;
void dfs(string &a) {
    string b = m[a];
    if (!visited[b]) {
        visited[b] = true;
        dfs(b);
    }
    else {
        ++cnt;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    while (n!=0) {
        string a,b;
        for (int i=0;i<n;++i) {
            cin>>a>>b;
            m[a] = b;
        }
        for (pair<string,string> p : m) {
            if (visited[p.first]) continue;
            visited[p.first] = true;
            dfs(p.first);
        }
        cout<<k<<' '<<cnt<<'\n';
        visited.clear();
        m.clear();
        cnt = 0;
        ++k;
        cin>>n;
    }
}