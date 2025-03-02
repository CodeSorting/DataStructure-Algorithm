#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin>>n>>m; //n=5 m=3
    vector<long> S(n,0); //a:1 2 3 1 2 s:1 3 6 7 9
    vector<long> C(m,0); // s%3 : 1 0 0 1 0 0이 3개이다.
    long answer = 0;
    cin>>S[0];
    
    for (int i=1;i<n;i++){
        int temp=0;
        cin>>temp;
        S[i] = S[i-1]+temp; // s:1 3 6 7 9 구하기
    }
    
    for (int i=0;i<n;i++){
        int remainder = S[i]%m;
        if (remainder==0){
            answer+=1; // 나머지가 0이면 a[0]~a[i]까지 더한 수가 3으로 나누어지니 답에 추가한다.
        }
        C[remainder]++; // 나머지가 같은 인덱스의 개수 세기
    }
    for (int i=0;i<m;i++){
        if (C[i]>1){
            answer = answer + (C[i]*(C[i]-1)/2);
        } // 나머지가 같은 인덱스 중 2개를 뽑는 경우의 수를 더하기 3C2,2C2 더함.
    }
    cout<<answer<<"\n";// answer=7이다.
    
}