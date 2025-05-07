#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[101][101];
int nhap[102],mhap[102];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n>>m;
    for (int i=0;i<n;++i) 
        for (int j=0;j<m;++j)
            cin>>arr[i][j];
    for (int i=0;i<n;++i) 
        for (int j=0;j<m;++j) 
            nhap[i] += arr[i][j]; //가로 구간 합
    for (int i=0;i<m;++i) 
        for (int j=0;j<n;++j) 
            mhap[i] += arr[i][j]; //세로 구간 합
    long long ans = -1e9;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            for (int k=i+1;k<n;++k) {
                for (int l=j+1;l<m;++l) {
                    long long res = nhap[i]+mhap[j]+nhap[k]+mhap[l];
                    res = res-arr[i][j]-arr[k][l]-arr[i][l]-arr[k][j]+(k-i-1)*(l-j-1);
                    ans = max(ans,res);
                }
            }
        }
    }    
    cout<<ans;
}
