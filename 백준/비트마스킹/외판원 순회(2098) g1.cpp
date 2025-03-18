#include <iostream>
#include <cmath>
using namespace std;

int INF = (1000000<<4) + 1;
int n;
int W[16][16];
int D[16][(1<<16)];
int tsp(int c,int v){ //모든 경우의 수에 대한 완전 탐색, 재귀 구현
    if (v == (1 << n)-1){ //모든 노드를 방문 했을 때
        return W[c][0] == 0 ? INF : W[c][0]; //시작 도시로 돌아갈 수 있냐 없냐로 따짐.
    }
    //이미 방문한 노드일 때
    if (D[c][v]!=0){
        return D[c][v];
    }
    int min_val = INF;
    for (int i=0;i<n;i++){
        //방문한 적이 없고 갈 수 있는 도시일 때
        if ((v & (1 << i)) == 0 && W[c][i] != 0){
            min_val = min(min_val,tsp(i, (v | (1 << i))) + W[c][i]);
        } //(v | (1 << i))는 방문 도시 저장 연산식이다.
    }
    D[c][v] = min_val;
    return D[c][v];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>W[i][j]; //비용 저장 배열
        }
    }
    cout<<tsp(0,1)<<"\n";
}