#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool visited[51];
string s;
vector<int> v; //정답 배열
int len,Max; //string의 길이, 1~N중의 N을 알아볼 수 있다.
void dfs(int index){
  if (index==len){
    for (int i=0;i<v.size();i++){
      cout<<v[i]<<' ';
    }
    exit(0);
  }

  string p = "";
  int ptoi = 0;
  for (int i=index;i<=index+1;i++){
    p += s[i];
    ptoi = stoi(p);

    if (ptoi>Max) continue;
    if (visited[ptoi]) continue;

    v.push_back(ptoi);
    visited[ptoi] = true;
    dfs(i+1);
    //안 될 경우 가지치기를 위해 초기화를 해야한다.
    v.pop_back();
    visited[ptoi] = false;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>s;
  len = s.size();
  if (len<10){ //길이가 10보다 작으면 1~9 배열임 (두자릿수 x)
    Max = len;
  }
  else{
    Max = (len-9)/2 + 9;
  }
  dfs(0);
}