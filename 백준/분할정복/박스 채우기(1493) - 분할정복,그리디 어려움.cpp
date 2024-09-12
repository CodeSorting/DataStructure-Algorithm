#include <iostream>
using namespace std;

int arr[20],ans=0;
bool flag;
void rec(int l, int w, int h) { //재귀함수 실행
  if (l==0 || w==0 || h==0) return;
  for (int i=19;i>=0;i--) {
    if (arr[i] == 0) continue; //개수 0개면 패스
    int cur = 1<<i; //2^i
    if (l >= cur && w >= cur && h >= cur) {
      arr[i]--;
      rec(l,w,h-cur); //한 변의 길이가 cur인 정육면체를 넣었을 때 남은 직육면체 3개로 나누어짐. (분할정복)
      rec(l-cur,w,cur);
      rec(cur,w-cur,cur);
      ans++;
      return;
    }
  }
  flag = true;
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int l,w,h,n;
  cin>>l>>w>>h;
  cin>>n;
  for (int i=0;i<n;++i) {
    int a,b;
    cin>>a>>b;
    arr[a] = b; //종류,개수
  }
  rec(l,w,h);

  if (flag) {
    cout<<-1<<'\n';
  }
  else {
    cout<<ans<<'\n';
  }
}