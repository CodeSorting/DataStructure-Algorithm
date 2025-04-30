#include <iostream>
using namespace std;
char arr[2000];
int cnt = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    for (int i=1;i<=n;++i) cin>>arr[i];
    char res; cin>>res;
    if (n==1) {
        if (arr[1]==res) cout<<0;
        else cout<<1;
        return 0;
    }
    char cur = arr[1];
    for (int i=2,j=3;i<=n-3;i=i+2,j=j+2) {
        if (arr[i]=='&') {
            if (cur=='T' && arr[j]=='T') cur = 'T';
            else if (cur=='T' && arr[j]=='F') cur = 'F';
            else if (cur=='F' && arr[j]=='T') cur = 'F';
            else if (cur=='F' && arr[j]=='F') cur = 'F';
        }
        else {
            if (cur=='T' && arr[j]=='T') cur = 'T';
            else if (cur=='T' && arr[j]=='F') cur = 'T';
            else if (cur=='F' && arr[j]=='T') cur = 'T';
            else if (cur=='F' && arr[j]=='F') cur = 'F';
        }
    } // T & F 처럼 2개만 남음. 어차피 0,1,2 중 1개이다.
    if (arr[n-1]=='&') {
        if (res=='T') { // & -> T
            if (cur=='F') ++cnt;
            if (arr[n]=='F') ++cnt;
        }
        else if (res=='F') { // & -> F
            if (cur=='T' && arr[n]=='T') ++cnt;
        }
    }
    else {
        if (res=='T') { // | -> T
            if (cur=='F' && arr[n]=='F') ++cnt;
        }
        else if (res=='F') { // | -> F
            if (cur=='T') ++cnt;
            if (arr[n]=='T') ++cnt;
        }
    }
    cout<<cnt;
}