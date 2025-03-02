#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,arr1[1001],arr2[1001],res=0;
int cnt1=0,cnt2=1;
bool cmp(int a,int b) { //내림차순
    return a>b;
}
/*
방법은 2가지다.
1. 오름차순 정렬로 cnt++
2. 내림차순 정렬하고 reverse로 cnt++
*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>arr1[i];
        arr2[i] = arr1[i];
    }
    for (int i=n-1;i>0;--i) {
        for (int j=0;j<i;++j) {
            if (arr1[j]>arr1[j+1]){
                swap(arr1[j],arr1[j+1]);
                ++cnt1;
            }
        }
    }
    for (int i=n-1;i>0;--i) {
        for (int j=0;j<i;++j) {
            if (arr2[j]<arr2[j+1]){
                swap(arr2[j],arr2[j+1]);
                ++cnt2;
            }
        }
    }
    res = min(cnt1,cnt2);
    cout<<res;
}