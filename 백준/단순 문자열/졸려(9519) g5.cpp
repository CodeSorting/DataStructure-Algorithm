#include <iostream>
#include <string>
#include <vector>
using namespace std;
int x;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>x>>s;
    int n = s.size();
    int c = n/2;
    int cnt = 0;
    vector<string> v;
    v.push_back(s);
    string t = s;
    while (true) { //다시 돌아올 때까지 걸리는 cnt
        string temp = "";
        ++cnt;
        for (int i=0;i<c;++i) {
            temp += t[i];
            temp += t[n-1-i];
        }
        if (n%2==1) temp += t[c]; 
        if (temp==s) break;
        v.push_back(temp);
        t = temp;
    }
    int pos = (cnt - (x % cnt)) % cnt;
    cout<<v[pos];
}