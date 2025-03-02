#include <iostream>
#include <string>
using namespace std;

int n;
string s1,s2;
int cnt1[26],cnt2[26];
bool poss = true;
char vowel[5] = {'a','e','i','o','u'};
/*
8
durumari
duramuri -> YES 
1. 한 단어를 재배열해 다른 단어를 만들 수 있어야 한다.
2. 두 단어의 첫 글자와 마지막 글자는 서로 동일해야 한다.
3. 각 단어에서 모음(a, e, i, o, u)을 제거한 문자열은 동일해야 한다. 알파벳 소문자
*/
string remove(string &s) {
    string res = "";
    for (int i=0;i<n;++i) {
        bool isVowel = false;
        for (int j=0;j<5;++j) {
            if (s[i]==vowel[j]) {
                isVowel = true;
                break;
            }
        }
        if (!isVowel) res += s[i];
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>s1>>s2;
    if (s1[0]!=s2[0] || s1[n-1]!=s2[n-1]) poss = false; //1번

    string tmp1 = remove(s1); //3번
    string tmp2 = remove(s2);
    if (tmp1!=tmp2) poss = false;

    for (int i=0;i<n;++i) { //2번번
        ++cnt1[s1[i]-'a'];
        ++cnt2[s2[i]-'a'];
    }
    for (int i=0;i<26;++i) {
        if (cnt1[i]!=cnt2[i]) {
            poss = false;
            break;
        }
    }
    if (poss) cout<<"YES";
    else cout<<"NO";
}