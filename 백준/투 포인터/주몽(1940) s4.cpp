#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    long m;
    cin>>n>>m; // 6개,합이 9
    vector<int> A(n,0);
    for (int i=0;i<n;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end()); //투 포인터 조건 : 정렬은 해야함.
    int count=0;
    int i=0;
    int j=n-1;
    while (i<j){
        if (A[i]+A[j]<m){
            i++;
        }
        else if (A[i]+A[j]>m){
            j--;
        }
        else{
            count+=1;
            i++;
            j--;
        }
    }
    cout<<count<<"\n";
}