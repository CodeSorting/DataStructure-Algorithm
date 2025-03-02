#include <iostream>
#include <algorithm>
using namespace std;

int t,x1,y1,r1,x2,y2,r2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while (t--){
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        int dist = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
        int rdist1 = (r1-r2) * (r1-r2);
        int rdist2 = (r1+r2) * (r1+r2);
        if (dist == 0){
            if (r1==r2) cout<<-1<<'\n';
            else cout<<0<<'\n';
        }
        else if (dist==rdist1 || dist==rdist2) cout<<1<<'\n';
        else if (rdist1<dist && dist<rdist2) cout<<2<<'\n';
        else cout<<0<<'\n';
    }
}