#include <iostream>
#include <algorithm>
using namespace std;

int n,s,arr[51],st;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for (int i=0;i<n;++i){
    cin>>arr[i];
  }
  cin>>s;

  while (s>0 && st<n){
    int maxidx=st;
    for (int i=st;i<=min(n-1,st+s);++i){ //구간 안의 최댓값
      if (arr[i]>arr[maxidx]) maxidx = i;
    }
    for (int i=maxidx;i>st;--i){
      swap(arr[i],arr[i-1]);
      s--;
    }
    st++; //가장 큰 값을 맨 앞으로 놨으니 다음 수부터 정렬하기
  }
  for (int i=0;i<n;++i){
    cout<<arr[i]<<' ';
  }
}