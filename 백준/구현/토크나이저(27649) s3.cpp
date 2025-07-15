#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> tokens;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string input;
    getline(cin,input);
    string token,temp;
    //< > && || ( ) 공백 
    for (int i=0;i<input.size();++i) {
        char cur = input[i];
        if (isalpha(cur) || isdigit(cur) || cur=='$' || cur=='?' || cur=='+' || cur=='_') {
            token += cur;
        }
        else {
            if (token!="") {
                tokens.push_back(token);
                token = "";
            }
            if (cur=='<' || cur=='>' || cur=='(' || cur==')') {
                temp = "";
                temp += cur;
                tokens.push_back(temp);
            }
            else if (cur=='&' || cur=='|') {
                temp = "";
                temp += cur; temp += cur;
                ++i;
                tokens.push_back(temp);
            }
        }
    }
    if (token!="") {
        tokens.push_back(token);
    }
    for (string s : tokens) {
        cout<<s<<' ';
    }
}