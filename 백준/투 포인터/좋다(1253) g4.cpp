#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> A(n,0);
    for (int i=0;i<n;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    int Result=0;
    for (int k=0;k<n;k++){
        long find=A[k];
        int i=0;
        int j=n-1;
        while (i<j){ // 투 포인터 알고리즘
            if(A[i]+A[j]==find){
                if (i!=k&&j!=k){ // 서로 다른 두 수의 합인데 자기자신을 좋은 수 만들기에 포함 x
                    Result++;
                    break;
                }
                else if(i==k) i++;
                else if(j==k) j--;
            }
            else if(A[i]+A[j]<find) {
                i++;
            }
            else{
                j--;
            }
        }
    }
    cout<<Result;
}