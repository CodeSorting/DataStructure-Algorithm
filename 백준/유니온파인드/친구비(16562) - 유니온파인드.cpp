#include <iostream>
#include <vector>
using namespace std;

int n,m,k;
bool flag = false;
int cost[10001],parent[10001];
bool visited[10001];
void Union(int a,int b);
int find(int a);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m>>k;
  for (int i=1;i<=n;++i){
    parent[i] = i;
    cin>>cost[i];
  }
  for (int i=0;i<m;++i){
    int a,b;
    cin>>a>>b;
    Union(a,b);
  }
  int res=0;
  for (int i=1;i<=n;++i){
    int cur = find(i);
    if (!visited[cur]){
      res += cost[cur];
      visited[cur] = true;
    }
  }
  if (res>k) cout<<"Oh no";
  else cout<<res;
}

int find(int a){
  if (parent[a] == a) return a;
  else return parent[a] = find(parent[a]);
}

void Union(int a,int b){
  a = find(a);
  b = find(b);
  if (a!=b){
    if (cost[a]>=cost[b]) parent[a] = b; //최솟값을 구하기 위해서이다.
    else parent[b] = a;
  }
}