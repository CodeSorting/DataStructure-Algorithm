#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int n,m,parent[100001];
ll dist[100001]; // dist[a] = a는 a부모보다 value만큼 무거움.

int find(int a) {
    if (parent[a]==-1) return a; //부모 없음.
    int parnode = find(parent[a]); //부모 먼저 찾고 업데이트함.
    dist[a] = dist[a] + dist[parent[a]]; //a~p[a]까지 거리 + p[a]~root까지 거리
    return parent[a] = parnode;
}
//b가 a보다 value만큼 무거움.
void Union(int a,int b,int value) {
    int roota = find(a);
    int rootb = find(b);
    if (roota==rootb) return;

    dist[rootb] = dist[a]-dist[b]+value; //roota<-a<-b<-rootb
    parent[rootb] = roota; //roota를 rootb의 부모로 만듬.
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        memset(parent,-1,sizeof(parent));
        memset(dist,0,sizeof(dist));
        cin>>n>>m;
        if (n==0 && m==0) break;
        char query;
        int a,b,value;
        for (int i=0;i<m;++i) {
            cin>>query;
            if (query=='!') {
                cin>>a>>b>>value;
                Union(a,b,value);
            }
            else {
                cin>>a>>b;
                if (find(a)!=find(b)) {
                    cout<<"UNKNOWN\n";
                }
                else {
                    cout<<dist[b]-dist[a]<<'\n';
                }
            }
        }
    }
}