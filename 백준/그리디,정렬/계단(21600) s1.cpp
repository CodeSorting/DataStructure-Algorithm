#include <iostream>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    int Maxans=0;
    int stairs=0;
    for (int i=0;i<n;++i) {
        int tmp;
        cin>>tmp;
        if (tmp>stairs) {
            stairs++;
            Maxans= max(Maxans,stairs);
        }
        else { // 그리디 알고리즘. 어차피 계단이 현재 조건 만족 못해도 tmp까지는 만족시킬 수 있음.
          stairs = tmp;
        }
    }
    cout<<Maxans;
}