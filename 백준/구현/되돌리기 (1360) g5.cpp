#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,string> pis;
string ans = "";
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<pis> v;
    cin>>n;
    string a,b; int c; //입력할 것들
    v.push_back({0,""});
    for (int i=0;i<n;++i) {
        cin>>a>>b>>c;
        if (a=="type") { //type k 3 //3초에 문자 k를 뒤에 넣음.
            string last_str = v.back().second;
            v.push_back({c,last_str+b});
        }
        else { //undo 3 5 //5초에 3초 전것들 돌림.
            int idx = v.size()-1;
            for (int j=0;j<v.size();++j) {
                if (c-stoi(b)<=v[j].first) { //어디로 돌아가야할지 찾기
                    idx = j-1;
                    break;
                }
            }
            if (idx==-1) v.push_back({c,""}); //아예 다 undo면 빈 문자열 함.
            else v.push_back({c,v[idx].second}); //idx의 상태로 돌아감.
        }
    }
    if (v.back().second != "") {
        cout<<v.back().second;
    }
}