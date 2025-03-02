#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAX = 500001; //(node<<1),(node<<1)+1

int n,m;
ll arr[MAX],tree[MAX*4],lazy[MAX*4]; //1 indexing

ll construct(int st,int ed,int node) {
    if (st==ed) return tree[node] = arr[st];
    int mid = (st+ed)/2;
    return tree[node] = construct(st,mid,(node<<1)) ^ construct(mid+1,ed,(node<<1)+1);
}

void update_lazy(int st,int ed,int node) {
    if (lazy[node]) { //lazy가 남아있다면
        if (st!=ed) {
            lazy[(node<<1)] ^= lazy[node]; //자식에게는 나중에 넘김
            lazy[(node<<1)+1] ^= lazy[node];
        }
        else tree[node] ^= lazy[node];
        lazy[node] = 0; //lazy는 없앰.
    }
}

ll sum(int st,int ed,int l,int r,int node) {
    update_lazy(st,ed,node); //lazy확인은 해야함.
    if (r<st || l>ed) return 0;
    if (l<=st && ed<=r) return tree[node]; //완전 범위 안
    int mid = (st+ed)/2;
    return sum(st,mid,l,r,(node<<1)) ^ sum(mid+1,ed,l,r,(node<<1)+1); 
}

void update(int st,int ed,int l,int r,ll up,int node) {
    update_lazy(st,ed,node);
    if (r<st || l>ed) return;
    if (l<=st && ed<=r) { //완전 범위 안
        if (st!=ed) {
            lazy[node] ^= up;
            update_lazy(st,ed,node);
            return;
        }
    }
    int mid = (st+ed)/2;
    update(st,mid,l,r,up,(node<<1));
    update(mid+1,ed,l,r,up,(node<<1)+1);
    tree[node] = tree[(node<<1)] ^ tree[(node<<1)+1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>arr[i]; //1부터
    construct(1,n,1); //1~n번 노드까지 1번부터 구성
    int a,b,c;
    ll d;
    cin>>m;
    for(int i=0;i<m;++i){
        cin>>a;
        cin>>b>>c;
        if (b>c) swap(b,c);
        if(a == 1){
            cin>>d;
            update(1,n,b+1,c+1,d,1); //1~n번 노드까지 b~c범위에서 d값 xor, 1번부터 탐색
        }
        else{
            cout<<sum(1,n,b+1,c+1,1)<<'\n'; //1~n번 노드까지 b~c범위에서 1번부터 탐색해서 xor 구해옴.
        }
    }
}