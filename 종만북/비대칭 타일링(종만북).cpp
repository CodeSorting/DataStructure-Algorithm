#include <iostream>
using namespace std;

int whole[101];
int part[101];
const int mod = 1000000007; // 전체 경우의 수에서 대칭인 부분을 빼준다.

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t,c;
  cin>>t;
  whole[1] = 1;
  whole[2] = 2;
  part[1] = 0;
  part[2] = 0;
  
  for(int i=3; i<=100 ; ++i){
    whole[i] = (whole[i-1] + whole[i-2])%mod;
    if(i%2 ==1) //홀수일 경우
      part[i] = (whole[i] - whole[i/2] + mod) %mod;
    else //짝수인 경우
      part[i] = (((whole[i] - whole[i/2] +mod) % mod ) - whole[(i/2) -1] + mod) % mod;   
  }
  
  while (t--){
    cin>>c;
    cout<<part[c]<<'\n';
  }
}