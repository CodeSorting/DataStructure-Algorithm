#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
bool flag;
vector<int> arr(10000);
bool prev_permutation(vector<int> &a, int n){ 
    int i=n-1;
    while (i>0 && a[i-1]<=a[i]) i -= 1; //끝에서부터 연속해 작아지는 수
    if (i<=0) return false; //오름차순의 경우

    int j=n-1; 
    while (a[j]>=a[i-1]) j -= 1; 

    swap(a[i-1],a[j]); //i-1~n-1범위에서 두번째로 큰 원소(i-1)와 첫번째로 큰 원소(j) 교환
    j=n-1;

    while (i<j) { //범위 안 최신화
        swap(a[i], a[j]);
        i += 1;
        j -= 1;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }
    if (prev_permutation(arr, n)){
        for (int i=0;i<n;++i){
            cout<<arr[i]<<' ';
        }
    }
    else cout<<-1;
}