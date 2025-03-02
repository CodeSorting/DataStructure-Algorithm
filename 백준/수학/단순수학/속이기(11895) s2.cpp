#include <iostream>
#include <algorithm>
using namespace std;
//X집합과 Y집합이 결과가 같으면 둘이 xor 연산하면 항상 0이 나옴.
//모든 arr을 xor 연산하고 0이 나오면 가장 작은 수 출력
//0이 안 나오면 X집합,Y집합의 생성이 불가능하니 0 출력
int n,arr[1000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>arr[0];
    int now = arr[0];
    int hap = arr[0];
    for (int i=1;i<n;++i){
        cin>>arr[i];
        now = now ^ arr[i];
        hap += arr[i];
    }
    if (now==0){
        sort(arr,arr+n);
        cout<<hap-arr[0];
    }
    else{
        cout<<0;
    }
}