#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;

int map[65][65],A[65][65],B[65][65];
bool visited[65][65][4];
int h,w,r,c,d; //맵의 크기, 아리스의 좌표,방향
int dx[] = {0,1,0,-1}; //북동남서
int dy[] = {-1,0,1,0};
int ans=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>h>>w>>r>>c>>d;
    for (int i=0;i<h;++i){
        string s;
        cin>>s;
        for (int j=0;j<w;++j){
            A[i][j] = s[j]-'0';
        }
    }
    for (int i=0;i<h;++i){
        string s;
        cin>>s;
        for (int j=0;j<w;++j){
            B[i][j] = s[j]-'0';
        }
    }
    queue<pair<P,pair<int,P>>> q; //y,x좌표,방향,총 이동횟수,마지막 청소 후 먼지 없는 곳 방문한 횟수
    q.push({{r,c},{d,{0,0}}});

    while (!q.empty()){
        int y = q.front().first.first; 
        int x = q.front().first.second;
        int now = q.front().second.first;
        int t = q.front().second.second.first;
        int cnt = q.front().second.second.second;
        q.pop();

        if (map[y][x]==0){ //A규칙
            map[y][x]=1; //먼지 제거
            memset(visited,0,sizeof(visited));
            int next = ((now + A[y][x]) % 4); //다음 방향
            int ny = y + dy[next];
            int nx = x + dx[next];
            if ((ny < 0) || (ny >= h) || (nx < 0) || (nx >= w)){
                ans = (t + 1); //좌표 넘어가면 그만하기,
                break;
            }
            q.push({{ny,nx},{next,{t+1,0}}});
        }
        else{//B규칙
            if (!visited[y][x][now]){
                visited[y][x][now] = true;
                int next = ((now + B[y][x]) % 4); //다음 방향
                int ny = y + dy[next];
                int nx = x + dx[next];
                if ((ny < 0) || (ny >= h) || (nx < 0) || (nx >= w)){
                    ans = t-cnt; //좌표 넘어가면 그만하기
                    break;
                }
                q.push({{ny,nx},{next,{t+1,cnt+1}}});
            }
            else{ //먼지 제거 불가능(방문)했다면 그만하기
                ans = t-cnt;
            }
        }
    }
    cout<<ans;
    return 0;
}