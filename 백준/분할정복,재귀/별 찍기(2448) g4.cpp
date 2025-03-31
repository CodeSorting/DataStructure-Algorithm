#include <iostream>
#include <cstring>
using namespace std;

char star[6144][6144];
void dfs(int y,int x,int size) {
    if (size==3) { //기본적인 별 그리기
        star[y][x] = '*';
        star[y+1][x-1] = '*';
        star[y+1][x+1] = '*';
        star[y+2][x] = '*';
        star[y+2][x-1] = '*';
        star[y+2][x-2] = '*';
        star[y+2][x+1] = '*';
        star[y+2][x+2] = '*';
    }
    else {
        dfs(y,x,size/2);
        dfs(y+size/2,x-size/2,size/2);
        dfs(y+size/2,x+size/2,size/2);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    memset(star,' ',sizeof(star));
    dfs(0,n-1,n);
    for (int i=0;i<n;++i) {
        for (int j=0;j<2*n-1;++j) {
            cout<<star[i][j];
        }
        cout<<'\n';
    }
}