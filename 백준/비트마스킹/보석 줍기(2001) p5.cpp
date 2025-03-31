#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 1e9;
int n,m,k;
int bosuk[101]; //[해당 섬]에 해당값 번째 보석이 있음.
vector<pair<int,int>> adj[101]; //a->b번째 섬, 최대 c개 보석 가능
bool visited[101][1<<15]; //[섬][보석 획득]
int res = 0;
//비트 필드 보석 개수 세기
int count(int cnt) { 
    int ret = 0;
    while (cnt!=0) {
        if ((cnt & 1)) {
            ++ret;
        }
        cnt>>=1;
    }
    return ret;
}

void bfs() {
    queue<pair<int,int>> q;
    q.push({1,0}); //시작지점,보석을 어디어디에서 획득했는지.
    visited[1][0] = true;
    if (bosuk[1]!=0) { //시작지점 보석 있으면 넣기
        visited[1][(1<<bosuk[1])] = true;
        q.push({1,(1<<bosuk[1])});
    }
    while (!q.empty()) {
        int curisland = q.front().first; //현재 섬
        int curfield = q.front().second; //현재 보석 획득한 필드
        int cnt = count(curfield);
        q.pop();
        if (curisland==1) {
            res = max(res,cnt);
        }

        for (pair<int,int> p : adj[curisland]) {
            int nextisland = p.first; //다음 섬
            int maxbosuk = p.second; //최대 가능 보석 개수
            int nextbosuk = bosuk[nextisland]; //다음 섬의 몇번째 보석
            if (cnt>maxbosuk) continue; //길의 최대 보석 개수를 넘으면 안된다.
            
            //보석 안 줍기
            if (!visited[nextisland][curfield]) {
                visited[nextisland][curfield] = true;
                q.push({nextisland,curfield});
            }

            //보석이 있으면 줍기
            if (nextbosuk!=0) {
                if (curfield & (1<<nextbosuk)) continue; //보석을 이미 선택했다면 필요 없음.
                int nextfield = curfield | (1<<nextbosuk); //다음 보석 추가
                if (!visited[nextisland][nextfield]) { //방문 안했다면 방문하기
                    visited[nextisland][nextfield] = true;
                    q.push({nextisland,nextfield});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    int num;
    for (int i=1;i<=k;++i) {
        cin>>num;
        bosuk[num] = i; //num번째 섬에 i번 보석이 있음.
    }
    for (int i=0;i<m;++i) {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    bfs();
    cout<<res;
}