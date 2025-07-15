#include <iostream>
#include <algorithm>
using namespace std;

int n,m,arr[100000];
bool light(int mid) {
    if (arr[0]>mid || n-arr[m-1]>mid) return false;
    for (int i=0;i<m-1;++i) {
        if (arr[i+1]-arr[i]>mid*2) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int x;
    for (int i=0;i<m;++i) {
        cin>>arr[i];
    }
    int height = 100000;
    int low = 0,high = 100000;
    while (low<=high) {
        int mid = (low+high)/2;
        if (light(mid)) {
            height = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    cout<<height;
}