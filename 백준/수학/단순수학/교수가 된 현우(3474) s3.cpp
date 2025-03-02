#include <iostream>
#include <algorithm>
using namespace std;

int t;
long long n;

//0이 추가되는 것 = 2x5가 추가되었을 때다. 근데 2가 항상 더 많으니 5의 개수를 구하면 답이다.
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while (t--) {
        cin>>n;
        int res = 0,num = 5; //5부터 1개시작.
        while (num<=n) {
            res += n/num;
            num *= 5;
        }
        cout<<res<<'\n';
    }    
}