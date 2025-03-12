#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

int t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while (t--) {
        string animal,buffer; 
        getline(cin,buffer); 
        getline(cin,animal); // 동물 소리 1줄 입력
        unordered_map<string,bool> sound;
        while (true) {
            string a,b,c;
            cin>>a>>b>>c;
            if (a=="what") {
                cin>>b>>c;
                break;
            }
            sound[c] = true;
        }
        string res = "";
        for (int i=0;i<animal.size();++i) {
            if (animal[i]==' ') { // 한단어 모두 감.
                if (sound[res]==0) { // 소리가 없다면 출력
                    cout<<res<<' ';
                }
                res = "";
            }
            else {
                res += animal[i];
            }
        }
        if (!sound[res]) cout<<res<<' ';
        cout<<'\n';
    }
}