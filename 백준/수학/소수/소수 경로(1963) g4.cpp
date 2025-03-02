#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

bool isPrime[10001];
bool visited[10001];
int t;
int st,ed;
void checkprime() {
    for (int i=2;i*i<=10000;++i){
        if (isPrime[i]==true){
            for (int j=2;i*j<=10000;++j){
                isPrime[i*j]=false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (int i=1;i<10000;++i) isPrime[i] = true;
    checkprime();
    
    while (t--) {
        cin>>st>>ed;
        memset(visited,0,sizeof(visited));
        queue<pair<int,int>> q;
        q.push({st,0});
        visited[st] = true;
        bool flag = false;

        while (!q.empty()) {
            int cur = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if (cur==ed) {
                cout<<cnt<<'\n';
                flag = true;
                break;
            }
            for (int i=0;i<4;++i) {
                int next;
                for (int j=0;j<10;++j) {
                    string s = to_string(cur);
                    s[i] = j + '0';
                    next = stoi(s);
                    
                    if (next>=10000 || next<1000) continue; //범위
                    if (!isPrime[next]) continue; //소수 x
                    if (visited[next]) continue; //방문
                    
                    visited[next] = true;
                    q.push({next,cnt+1});
                }
            }
        }
        if (!flag) cout<<"Impossible"<<'\n';
    }
}