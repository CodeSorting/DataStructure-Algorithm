#include <bits/stdc++.h>
using namespace std;

int st,ed;
int parent[100001]; //부모노드로 기록
bool visited[100001]; //방문 여부
int getpos(int pos,int opt){
  if (opt==0) return pos-1;
  else if (opt==1) return pos+1;
  else return pos*2;
}
int back = 0,check;
vector<int> ans;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>st>>ed;
  if (st==ed){ //시발 이 예외처리 땜에 5번은 틀림.
    cout<<0<<'\n';
    cout<<st;
    return 0;
  }
  queue<pair<int,int>> q;
  q.push({st,0});
  parent[st] = -100;
  visited[st] = true;
  while (!q.empty()){
    int cur = q.front().first;
    int time = q.front().second;
    q.pop();
    if (cur==ed){
      back = cur;
      check = time;
      cout<<time<<'\n';
      break;
    }
    for (int i=0;i<3;i++){
      int next = getpos(cur,i);
      if (next<0 || next>100000) continue;
      if (visited[next]) continue;
      visited[next] = true;
      q.push({next,time+1});
      parent[next] = cur;
    }
  }
  for (int i=0;i<check;i++){
    ans.push_back(back);
    back = parent[back];
  }
  cout<<st<<' ';
  for (int i=ans.size()-1;i>=0;i--){
    cout<<ans[i]<<' ';
  }
}