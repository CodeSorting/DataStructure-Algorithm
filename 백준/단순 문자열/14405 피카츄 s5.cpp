#include <iostream>
#include <string>
using namespace std;

string s;
bool isImpossible = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    int i;
    for (i=0;i<s.size();) {
        if (s[i] == 'p' && s[i+1] == 'i') i += 2;
        else if (s[i] == 'k' && s[i+1] == 'a') i += 2;
        else if (s[i] == 'c' && s[i+1] == 'h' && s[i+2] == 'u') i += 3;
        else isImpossible = true;
        if (isImpossible) break;
    }
    if (s.size() > i || isImpossible) cout<<"NO";
    else if (s.size() == i) cout<<"YES";
}