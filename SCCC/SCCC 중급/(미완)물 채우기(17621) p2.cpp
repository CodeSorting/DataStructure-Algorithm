#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int a,b;
    vector<pair<int,int>> block;
    block.resize(n+1);
    for (int i=1;i<=m;++i) {
        cin>>block[i].first>>block[i].second;
        
    }
}