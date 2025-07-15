#include <iostream>
#include <cstring>
using namespace std;

int t,n,m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while (t--) {
        cin>>n>>m;
        int arr[n+1][n+1];
        int rhap[n+2],chap[n+2];
        memset(rhap,0,sizeof(rhap));
        memset(chap,0,sizeof(chap));
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                cin>>arr[i][j]; 
            }
        }
        int idx = n-1;
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                rhap[i] += arr[i][j];
                chap[i] += arr[j][i];
            }
        }
        int r1,c1,r2,c2,v;
        while (m--) {
            int r1,c1,r2,c2,v,var;
			cin>>r1>>c1>>r2>>c2>>v;
			var = (c2-c1+1)*v; 
			for(int i=r1-1;i<r2;++i) rhap[i] += var;
			var = (r2-r1+1)*v; 
			for(int i=c1-1;i<c2;++i) chap[i] += var;
        }

        //출력
        for (int i=0;i<n;++i) cout<<rhap[i]<<' ';
        cout<<'\n';
        for (int i=0;i<n;++i) cout<<chap[i]<<' ';
        cout<<'\n';
    }
}