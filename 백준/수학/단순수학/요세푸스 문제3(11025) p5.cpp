#include <iostream>
using namespace std;
/*와.. 감탄밖에 안나오네...
[1, ..., k - 1, k, k + 1, ..., n] -> [k + 1, ..., n, 1, ..., k - 1]
이때 (n - 1, k)에서 마지막으로 남는 사람을 안다면,
두 번째 배열에서 해당 위치의 사람을 구하는 식으로 (n, k)에서 마지막으로 남는 사람을 O(1)에 구할 수 있다.
따라서 O(1)의 공간복잡도, O(n)의 시간복잡도에 정답을 구할 수 있다.
*/
int main(){
    int n,k;
    cin>>n>>k;
    // f(0,k) = 0, f(n,k) = (f(n-1,k) + k-1 mod n) + 1
    int f = 0;
    for(int i = 1; i <= n; i++) {
        f = (f+k-1) % i + 1;
    }
    cout<<f;
}