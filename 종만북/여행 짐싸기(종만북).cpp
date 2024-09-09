#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n,w,capacity,volume[101],need[101],cache[1001][101];
string name[100];
//캐리어에 남는 용량이 capacity일 때 item 이후의 물건들을
//담아 얻을 수 있는 최대 절박도의 합을 반환한다.
int pack(int capacity,int item) {
    if (item==n) return 0; //기저사례 : 더담을 물건이 없을 때
    int &ret = cache[capacity][item];
    if (ret!=-1) return ret;
    //물건을 안담을 경우
    ret = pack(capacity,item+1);
    //이 물건을 담을 경우
    if (capacity >= volume[item]) {
        ret = max(ret, pack(capacity-volume[item],item + 1) + need[item]);
    }
    return ret;
}

void reconstruct(int capacity,int item,vector<string>& picked) {
    if (item == n) return;
    if (pack(capacity,item) == pack(capacity,item+1)) {
        reconstruct(capacity,item + 1,picked);
    }
    else {
        picked.push_back(name[item]);
        reconstruct(capacity - volume[item],item + 1,picked);
    }
}

vector<string> list;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c;
    cin>>c;
    while (c--) {
        cin>>n>>w; //물건 개수, 배낭 수용공간
        memset(cache,-1,sizeof(cache));
        list.clear();
        for (int i=0;i<n;++i) {
            cin>>name[i]>>volume[i]>>need[i];
        }
        int max_need = pack(w,0);
        reconstruct(w,0,list);
        cout<<max_need<<' '<<list.size()<<'\n';
        for (int i=0;i<list.size();++i) {
            cout<<list[i]<<'\n';
        }
    }
}