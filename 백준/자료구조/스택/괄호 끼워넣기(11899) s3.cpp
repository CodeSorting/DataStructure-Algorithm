#include <stack>
#include <iostream>
using namespace std;
stack<char> s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    char temp;
    int cnt = 0;
    while (cin>>temp) {
        if (temp==')') {
            if (!s.empty() && s.top()=='(') s.pop();
            else s.push(temp);
        }
        else {
            s.push(temp);
        }
    }
    while (!s.empty()) {
        cnt++;
        s.pop();
    }
    cout<<cnt;
}