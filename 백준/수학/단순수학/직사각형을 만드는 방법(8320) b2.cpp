#include <iostream>
using namespace std;
//1 x 1 정사각형들을 모아 직사각형들을 만들 때 직사각형의 만들 수 있는 경우의 수 (돌렸을 때 같으면 같은 것)
//정사각형으로 직사각형을 만드니 n을 a*b로 만든다. 즉 n의 약수들의 합임.

int arr[10001];
int add(int n){
    int cnt = 0;
    for (int i=1;i*i<=n;++i){ //중복을 피하기 위해 sqrt까지만 돈다.
        if (!(n%i)){
            ++cnt;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    arr[1] = 1;
    arr[2] = 2;
    for (int i=3;i<=n;++i){
        arr[i] = arr[i-1] + add(i);
    }
    cout<<arr[n];
}