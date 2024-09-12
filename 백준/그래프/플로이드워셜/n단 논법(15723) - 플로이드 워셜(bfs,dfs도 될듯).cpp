#include <iostream>
#include <string>
using namespace std;

int n,m;
bool map[27][27];
string tmp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin.ignore();
    for (int i=0;i<n;++i){ 
        getline(cin,tmp);
        map[tmp[0]-'a'][tmp[tmp.size()-1]-'a'] = true;
    }
    for (int k=0;k<26;++k){
        for (int i=0;i<26;++i){
            for (int j=0;j<26;++j){
                if (map[i][k] && map[k][j]){
                    map[i][j] = true;
                }
            }
        }
    }
    cin>>m;
    cin.ignore();
    for (int i=0;i<m;++i){
        getline(cin,tmp);
        if (map[tmp[0]-'a'][tmp[tmp.size()-1]-'a']) cout<<"T"<<'\n';
        else cout<<"F"<<'\n';
    }
}