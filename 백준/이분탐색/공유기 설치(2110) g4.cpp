#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int n,c;
ll arr[200000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>c;
    for (int i=0;i<n;++i) {
        cin>>arr[i];
    }
    sort(arr,arr+n); //이분 탐색을 위한 오름차순 정렬
    ll st=1,ed=arr[n-1]-arr[0]; //최소 거리는 1, 최대 거리는 처음 집과 마지막 집 사이의 거리
    ll res = 0; //중요한 건 다음 거리로 했을 때 만족을 하나 안 하나임.
    while (st<=ed) {
        ll mid = (st+ed)/2;
        ll cnt = 1;

        ll pre = arr[0]; //이전 설치 공유기
        for (int i=1;i<n;++i) {
            if (arr[i]-pre>=mid) { //현재 - 전 설치 공유기가 결과의 최소 기준인 mid를 넘어야함.
                ++cnt;
                pre = arr[i];
            }
        }
        if (cnt>=c) { //모두 만족하면 업데이트
            res = max(res,mid);
            st = mid+1;
        }
        else ed=mid-1;
    }
    cout<<res;
}