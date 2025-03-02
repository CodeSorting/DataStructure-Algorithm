#include <iostream>
using namespace std;
typedef long long ll;

ll arr[] = {1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,1162261467,3486784401,10460353203,
    31381059609,94143178827,282429536481,847288609443,2541865828329,7625597484987,22876792454961,68630377364883,205891132094649,617673396283947,1853020188851841,
    5559060566555523,16677181699666569,50031545098999707,150094635296999121,450283905890997363,1350851717672992089,4052555153018976267};
ll n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    if (n==0) { //예외 처리
        cout<<"NO";
        return 0;
    }
    for (int i=39;i>=0;--i) {
        if (n==0) {
            cout<<"YES";
            return 0;
        }
        if (n>=arr[i]) {
            n -= arr[i];
        };
    }
    if (n==0) cout<<"YES";
    else cout<<"NO";
}
/*
사실 위의 코드는 많이 비효율적임.
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long int x;
    cin >> x;

    // 0은 삼삼한 수가 아님
    if (x == 0) {
        cout << "NO";
        return 0;
    }

    // x를 3으로 나누며 확인
    while (x > 0) {
        if (x % 3 == 2) { // 나머지가 2인 경우
            cout << "NO";
            return 0;
        }
        x /= 3; // 3으로 나누기
    }

    // 모든 조건 통과 시 삼삼한 수
    cout << "YES";
    return 0;
}
*/