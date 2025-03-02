#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n,res=0;
int cnt[3]; // 1/4,1/2,3/4
// 1/2는 서로끼리 처리하는게 좋음, 3/4는 1/4와 같이 처리하는게 좋음. 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    string tmp;
    for (int i=0;i<3;++i) cnt[i]=0; //분수 횟수 초기화
    for (int i=0;i<n;++i) {
        cin>>tmp;
        if (tmp=="1/4") ++cnt[0];
        else if (tmp=="1/2") ++cnt[1];
        else ++cnt[2];
    }
    res += cnt[1]/2; 
    cnt[1] = cnt[1] % 2; // 이제 1/2은 1개 아니면 0개다.

    int minval = min(cnt[0],cnt[2]);
    res += minval;
    cnt[0] -= minval;
    cnt[2] -= minval; // 1/4 = 0개 or 남음 1/2 = 1개 or 0개, 3/4 = 0개 or 남음
    while (cnt[2]!=0) {
        res++;
        cnt[2]--;
    } // 1/4 = 0개 or 남음 1/2 = 1개 or 0개, 3/4 = 0개
    if (cnt[1]%2) { //1/2가 1개 남았을 경우
        if (cnt[0]>=2) {
            res++;
            cnt[0] -= 2;
            cnt[1] = 0; // 1/4 = k개 1/2 = 0개 3/4 = 0개
            if (cnt[0]%4!=0) {
                res += cnt[0]/4;
                res++;
            }
            else {
                res += cnt[0]/4;
            }
        }
        else {
            res++;
            cnt[0] = 0;
            cnt[1]--;
        }
    }
    else { //1/2가 0개일 경우
        if (cnt[0]%4!=0) {
            res += cnt[0]/4;
            res++;
        }
        else {
            res += cnt[0]/4;
        }
        cnt[0] = 0;
    }

    cout<<res;
}