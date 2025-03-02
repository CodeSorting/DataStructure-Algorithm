#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
//계속 답이 안나와서 봤다. 내 착각은 백조가 한번에 한칸씩만 갈 수 있다고 생각했어서
//함수를 잘못 짰다. 문제예제를 잘 봐야할듯.

int r,c,timer;
bool visited[1501][1501];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char lake[1501][1501];

struct Swan{
  int r,c;
};
vector <Swan> swan;
queue <pii> swanQ, waterQ;

void meltIce(){ //물들을 큐에 넣고 인접해있는 부분을 물로 바꾼다.
    int wSize = waterQ.size(); 
    while(wSize--){ //!waterQ.empty()가 아닌게 중요하다.
        int x = waterQ.front().first;
        int y = waterQ.front().second;
        waterQ.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= r || 0 > ny || ny >=c) continue;
            if(lake[nx][ny] != 'X') continue; //x가 아닌 오리면 안되기 때문이다.
            waterQ.push({nx,ny}); //넣고 다음 함수 호출 때 다시 들어간다.
            lake[nx][ny] = '.'; //물로 변환
        }
    }
}

bool canMeet(){
    queue <pii> s;
    while(!swanQ.empty()){ //백조의 출발
        int x = swanQ.front().first;
        int y = swanQ.front().second;
        swanQ.pop();
        if(x == swan[1].r && y == swan[1].c) return true; //또 다른 백조에게 닿았으면 끝
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= r || 0 > ny || ny >= c) continue;
            if(visited[nx][ny]) continue;
            visited[nx][ny] = true;
            if(lake[nx][ny] == 'X'){
              s.push({nx,ny}); //다음날에 다닐수 있다.
            }
            else swanQ.push({nx,ny});
        }
    }
    swanQ = s; //갈 수 있는데 까지만 가고 저장시키고 나간다.
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>r>>c;
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j) {
            cin>>lake[i][j];
            if(lake[i][j] == 'L'){ //백조라면
              waterQ.push({i,j});
              swan.push_back({i,j});
            }
            if(lake[i][j] == '.'){ //물이라면
              waterQ.push({i,j});
            }
        }
    }
    swanQ.push({swan[0].r,swan[0].c}); //L을 넣고 canmeet로 탐색한다.
    while(1){
        if(canMeet()) break;
        timer++;
        meltIce(); //얼음 녹이기
    }
    cout<<timer;
}