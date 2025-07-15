#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;
string arr[1001],arr2[1001];
vector<string> v;
char compare[5] = {'B','S','G','P','D'};
bool cmp(string a, string b) {
    int a_grade = 0, b_grade = 0;
    for (int i = 0; i < 5; ++i) {
        if (a[0] == compare[i]) a_grade = i;
        if (b[0] == compare[i]) b_grade = i;
    }
    if (a_grade == b_grade) {
        int a_num = stoi(a.substr(1,a.size()-1));
        int b_num = stoi(b.substr(1,b.size()-1));
        return a_num > b_num;
    }
    return a_grade < b_grade;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>arr[i]; arr2[i] = arr[i];
    }
    sort(arr2,arr2+n,cmp);
    bool isOk = true;
    for (int i=0;i<n;++i) {
        if (arr[i]!=arr2[i]) {
            v.push_back(arr2[i]);
            isOk = false;
        }
    }
    sort(v.begin(),v.end(),cmp);
    if (isOk) cout<<"OK";
    else {
        cout<<"KO\n"<<v[0]<<' '<<v[1];
    }
}