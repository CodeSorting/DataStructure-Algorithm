#include <cstdio>
#include <algorithm>
using namespace std;
int D[1001],A[1001];
int main(){
    int n,ans=0;
	scanf("%d",&n);
    for (int i=0;i<n;++i) scanf("%d",A+i);
    for (int i=0;i<n;++i){
        D[i] = 1;
        for (int j=0;j<i;++j){
            if (A[i]<A[j]){
                D[i] = max(D[i],D[j]+1);
            }
        }
    }
    for (int i=0;i<n;++i){
        ans = max(ans,D[i]);
    }
    printf("%d",ans);
}