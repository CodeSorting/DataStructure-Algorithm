#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (true) {
        stack<char> s;
        getline(cin,str);
        bool isWrong = false;
        if (str==".") break;
        int cnt = 0;
        while (str[cnt]!='\0') {
            char cur = str[cnt];
            if (cur=='(' || cur=='[') {
                s.push(cur);
            }
            else if (cur==')') {
                if (!s.empty() && s.top()=='(') {
                    s.pop();
                }
                else {
                    isWrong = true;
                    break;
                }
            }
            else if (cur==']') {
                if (!s.empty() && s.top()=='[') {
                    s.pop();
                }
                else {
                    isWrong = true;
                    break;
                }
            }
            cnt++;
        }
        if (s.empty() && !isWrong) cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';
    }
}