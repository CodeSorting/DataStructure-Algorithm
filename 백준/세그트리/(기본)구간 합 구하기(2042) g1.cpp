#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int SIZE = 2097152;
/*
어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다. 만약에 1,2,3,4,5 라는 수가 있고,
3번째 수를 6으로 바꾸고 2번째부터 5번째까지 합을 구하라고 한다면 17을 출력하면 되는 것이다. 그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 3번째부터 5번째까지
합을 구하라고 한다면 12가 될 것이다.

첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000) 가 주어진다. M은 수의 변경이 일어나는 횟수이고,
K는 구간의 합을 구하는 횟수이다. 그리고 둘째 줄부터 N+1번째 줄까지 N개의 수가 주어진다.
그리고 N+2번째 줄부터 N+M+K+1번째 줄까지 세 개의 정수 a, b, c가 주어지는데, a가 1인 경우 b(1 ≤ b ≤ N)번째 수를 c로 바꾸고
a가 2인 경우에는 b(1 ≤ b ≤ N)번째 수부터 c(b ≤ c ≤ N)번째 수까지의 합을 구하여 출력하면 된다.
입력으로 주어지는 모든 수는 -263보다 크거나 같고, 263-1보다 작거나 같은 정수이다.

첫째 줄부터 K줄에 걸쳐 구한 구간의 합을 출력한다.
1 b c: b번째 수를 c로 변경
2 b c: b번째부터 c번째까지 합을 구함
*/
int n,m,k;
struct SegTree {
    int size,start;
    ll arr[SIZE];
    SegTree(int n) : size(n) {
        start = 1;
        while (start<size) start<<=1;
        memset(arr,0,sizeof(arr));
    }
    void construct() {
        for (int i=start-1;i>0;--i) {
            arr[i] = arr[(i<<1)] + arr[(i<<1)+1];
        }
    }
    void add(int a,ll b) { //a번째 값을 b로 변경
        a += start;
        b -= arr[a]; //변화량 계산
        while (a>0) {
            arr[a] += b; //현재 노드부터 부모들의 값을 변화시킨다.
            a /= 2;
        }
    }
    ll sum(int a,int b) { return sum(a,b,1,0,start); } //a~b구간 합을 반환
    /*
    a, b : 구하고자 하는 구간의 범위 ([a, b))
    node : 현재 탐색 중인 세그먼트 트리의 노드 번호
    na, nb : 현재 노드가 담당하는 범위 ([na, nb))
    */
    ll sum(int a,int b,int node,int na,int nb) {
        if (b<=na || nb<=a) return 0; //범위 밖
        if(a<=na && nb<=b) return arr[node]; //완전히 포함됨 : a  na  nb  b일 때
		int mid = (na+nb)/2; //부분적으로 포함됨 : 왼쪽 오른쪽 나눠서 구하기기
		return sum(a, b, node*2, na, mid) + sum(a, b, node*2+1, mid, nb);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    SegTree st(n);
    for (int i=0;i<n;++i) {
        cin>>st.arr[st.start+i];
    }
    st.construct();
    for (int i=0;i<m+k;++i) {
        int a;
        cin>>a;
        if (a==1) {
            int b;
            ll c;
            cin>>b>>c;
            st.add(b-1,c);
        }
        else {
            int b,c;
            cin>>b>>c;
            cout<<st.sum(b-1,c)<<'\n';
        }
    }
}