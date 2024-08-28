#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int t,n,dp[101][101];
string s1,s2;
//와일드카드, 원문, 와일드카드 길이 i까지 비교, 원문 j까지 비교
bool match(const string& s1, const string& s2, int i, int j) {
    int& ret = dp[i][j];
    if (ret != -1) return ret; //메모이제이션

    while (i < s1.size() && j < s2.size() && (s1[i] == '?' || s1[i] == s2[j])){
        i++, j++; //같은 부분 계속 확인하기
    } 
    if (i == s1.size()) return ret = (j == s2.size()); // 사이즈 같으면 매칭됨.
    //*를 만나서 끝난 경우: *에 몇 글자를 대응해야 할지 재귀 호출하면서 확인한다.
    if (s1[i] == '*'){
        for (int skip = 0; skip + j <= s2.size(); skip++){
            if (match(s1, s2, i + 1, j + skip)){
                return ret = true;
            } 
        }
    }  
    return ret = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while (t--){
        cin>>s1; cin>>n;
        vector<string> ans;
        while (n--){
            memset(dp,-1,sizeof(dp));
            cin>>s2;
            if (match(s1,s2,0,0)) ans.push_back(s2);
        }
        sort(ans.begin(),ans.end());
        for (string s : ans){
            cout<<s<<'\n';
        }
    }
}