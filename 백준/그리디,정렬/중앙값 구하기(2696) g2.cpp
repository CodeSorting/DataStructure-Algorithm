#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin>>t;
  int m;

  while (t--){
    cin>>m;
    priority_queue<ll,vector<ll>,greater<ll>> minq; //최소힙
    priority_queue<ll> maxq; //최대힙
    vector<ll> ans;
    cout<<m/2+1<<'\n';
    ll tmp;
    /*
    9
    1 2 3 4 5 6 7 8 9
    5
    1 2 3 4 5
    */
    for (int i=1;i<=m;i++){ //maxq에 중앙값 유지하기
      cin>>tmp;
      if (i%2==0){ //짝수번째는 최소에 대입
        minq.push(tmp);
      }
      else{//홀수번째는 최대에 대입
        maxq.push(tmp);
        if (!maxq.empty() && !minq.empty()){
          if (maxq.top()>minq.top()){
            minq.push(maxq.top()); //max값을 min에 넣고 min값을 max에 넣는다.
            maxq.pop();
            maxq.push(minq.top());
            minq.pop();
          }
        }
      }
      if (i%2==1){ //홀수번째 때 중앙값 넣기
        ans.push_back(maxq.top());
      }
    }
    for (int i=0;i<ans.size();i++){
      cout<<ans[i]<<' ';
    }
    cout<<'\n';
  }
}
/*
#include <iostream>
#include <algorithm>
using namespace std; //계속 정렬하고 출력해도 답이 된다... 레전드풀이...

int A[99999];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    cout<<(n+1)/2<<'\n';
    for (int i=0;i<n;i++){
      cin>>A[i];
      if (i%2==0){//홀수번째 수면 정렬후 출력
        sort(A, A+i+1);
        cout<<A[i/2]<<" ";
      }
    }
    cout<<'\n';
  }
}
*/
