#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
ll n,k,A[16],C[16][16],D[16][16]; //과목 개수,학점 수,요일
vector<pair<string,string>> v[16];
int res = 0; //합이 정확히 22가 되는 개수
int parseTime(string &t) {
    int hh = stoi(t.substr(0,2));
    int mm = stoi(t.substr(3,2));
    return hh * 60 + mm;
}
bool isPossible(int i,int j,vector<int> &idx) {
    int day2   = D[i][j];
    int start2 = parseTime(v[i][j].first);
    int end2   = parseTime(v[i][j].second);
    for (int g=0;g<i;++g) {
        int sel = idx[g];
        if (sel < 0) continue;          // g그룹에서 수강 안 했으면 패스
        if (D[g][sel] != day2) continue; // 요일이 다르면 겹침 없음
        int start1 = parseTime(v[g][sel].first);
        int end1   = parseTime(v[g][sel].second);
        // 두 구간이 겹치는 조건: start1 < end2 && start2 < end1
        if (start1 < end2 && start2 < end1) return false;
    }
    return true;
}
//학점 합,선택한 리스트 인덱스,cnt번째 선택
void dfs(int c,vector<int> &idx,int cnt) {
    if (cnt==n) {
        if (c==22) ++res;
        return;
    }
    idx.push_back(-1);
    dfs(c,idx,cnt+1); //선택 x
    idx.pop_back();

    for (int i=0;i<A[cnt];++i) {
        if (!isPossible(cnt,i,idx)) continue;
        idx.push_back(i);
        dfs(c+C[cnt][i],idx,cnt+1);
        idx.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    string s,e;
    for (int i=0;i<n;++i) {
        cin>>A[i];
        for (int j=0;j<A[i];++j) {
            cin>>C[i][j]>>D[i][j]>>s>>e;
            v[i].push_back({s,e});
        }
    }
    vector<int> list;
    dfs(0,list,0);
    cout<<res;
}