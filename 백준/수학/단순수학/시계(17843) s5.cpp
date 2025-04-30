#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.fixed;
    cout.precision(10);
    int t; cin>>t;
    while (t--) {
        int h,m,s; cin>>h>>m>>s;
        int arr[3] = {0,};
        arr[0] = 3600*h + 60*m + s; //43200 초 기준
        arr[1] = 720*m + 12*s;
        arr[2] = 720*s;
        sort(arr,arr+3);
        int min_val = min(arr[1]-arr[0],min(arr[2]-arr[1],43200+arr[0]-arr[2]));
        cout<<(double)min_val / 120<<'\n';
    }
}