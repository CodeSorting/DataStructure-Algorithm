#include <iostream>
using namespace std;
int arr[30000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        for (int i=0;i<n;++i) cin>>arr[i];
        int cnt = 1;
        bool up = false;
        for (int i=0;i<n-1;++i) {
            if (up && arr[i]<arr[i+1]) {
                ++cnt;
                up = false;
            }
            else if (!up && arr[i]>arr[i+1]) {
                ++cnt;
                up = true;
            }
        }
        cout<<cnt<<'\n';
    }
}