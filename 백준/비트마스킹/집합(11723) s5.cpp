#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string input;
    int num;
    int m;
    int space = 0;
    cin>>m;
    while (m--){
        cin>>input;
        if (input=="add"){
            cin>>num;
            space |= (1<<num);
        }
        else if (input=="remove"){
            cin>>num;
            space &= ~(1<<num);
        }
        else if (input=="check"){
            cin>>num;
            if (space & (1<<num) ) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
        else if (input=="toggle"){
            cin>>num;
            if (space & (1<<num)) space &= ~(1<<num);
            else space |= (1<<num);
        }
        else if (input=="all"){
            space = (1<<21)-1;
        }
        else if (input=="empty"){
            space = 0;
        }
    }
    
}