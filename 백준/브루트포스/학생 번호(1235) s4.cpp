#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string arr[1001];
int k;
bool strSame(string a,string b) {
    if (a==b) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>arr[i];
    }
    int siz = arr[0].size();
    for (k=1;k<=siz;++k) {
        bool isSame = false;
        for (int i=0;i<n;++i) {
            for (int j=i+1;j<n;++j) {
                string a = arr[i].substr(siz-k,siz);
                string b = arr[j].substr(siz-k,siz);
                if (strSame(a,b)) {
                    isSame = true;
                }
            }
            if (isSame) break;
        }
        if (!isSame) break;
    }
    cout<<k;
}