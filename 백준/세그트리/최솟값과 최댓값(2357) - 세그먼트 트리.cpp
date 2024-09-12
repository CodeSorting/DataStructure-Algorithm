#include <iostream> //2357이다.
#include <cstring>
#include <algorithm>
using namespace std;

int minST[262144], maxST[262144];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N, M, start = 2;
  cin>>N>>M;
  for(int i=0; i<262144; i++)
    minST[i] = 0x7FFFFFFF; //INT_MAX다.
  while(start <= N) start *= 2; //세그먼트트리의 시작점.

  for(int i=0; i<N; i++){
    int val, cur = start+i;
    cin>>val;
    while(cur){
      minST[cur] = min(minST[cur], val);
      maxST[cur] = max(maxST[cur], val);
      cur /= 2; //최솟값,최댓값 구간에 따라 계속 갱신
    }
  }
  for(int i=0; i<M; i++){
    int a,b;
    cin>>a>>b;
    a += start-1;
    b += start-1; //구간까지 a,b맞춰주기
    if(a == b){
      cout<<minST[a]<<' '<<maxST[a]<<'\n'; //같으면 그대로 출력
      continue;
    }
    int minR = 0x7FFFFFFF, maxR = 0; //min = INT_MAX, max = 0
    while(a != b){
      if(a%2){ //홀수
        minR = min(minR, minST[a]);
        maxR = max(maxR, maxST[a]);
        a = a/2+1;
      }
      else a /= 2;//짝수

      if(b%2 == 0){ //짝수
        minR = min(minR, minST[b]);
        maxR = max(maxR, maxST[b]);
        b = b/2-1;
      }
      else b /= 2;//홀수
      if(a >= b){
        if(a == b){
          minR = min(minR, minST[b]);
          maxR = max(maxR, maxST[b]);
        }
        break;
      }
    }
    cout<<minR<<' '<<maxR<<'\n';
  }
}