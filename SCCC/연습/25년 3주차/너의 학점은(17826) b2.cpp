#include <iostream>
#include <algorithm>
using namespace std;

int arr[50],n; // O(nlogn)
bool cmp(int a,int b) {
    return a>b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i=0;i<50;++i) {
        cin>>arr[i];
    }
    cin>>n;
    sort(arr,arr+50,cmp);
    int ans = 0;
    for (int i=0;i<50;++i) {
        if (arr[i]==n) {
            ans = i+1;
            break;
        }
    }
    if (ans>=1 && ans<=5) cout<<"A+";
    else if (ans>=6 && ans<=15) cout<<"A0";
    else if (ans>=16 && ans<=30) cout<<"B+";
    else if (ans>=31 && ans<=35) cout<<"B0";
    else if (ans>=36 && ans<=45) cout<<"C+";
    else if (ans>=46 && ans<=48) cout<<"C0";
    else cout<<"F";
}
/* O(n)
#include <iostream>
#include <algorithm>
using namespace std;

int arr[50],n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i=0;i<50;++i) {
        cin>>arr[i];
    }
    cin>>n;
    int ans = 1;
    for (int i=0;i<50;++i) {
        if (arr[i]>n) {
            ++ans;
        }
    }
    if (ans>=1 && ans<=5) cout<<"A+";
    else if (ans>=6 && ans<=15) cout<<"A0";
    else if (ans>=16 && ans<=30) cout<<"B+";
    else if (ans>=31 && ans<=35) cout<<"B0";
    else if (ans>=36 && ans<=45) cout<<"C+";
    else if (ans>=46 && ans<=48) cout<<"C0";
    else cout<<"F";
}
*/