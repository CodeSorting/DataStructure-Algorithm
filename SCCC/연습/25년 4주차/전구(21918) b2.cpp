#include <iostream>
using namespace std;

int n,m;
bool arr[4001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>arr[i];
    }
    int op,a,b;
    for (int i=1;i<=m;++i) {
        cin>>op;
        if (op==1) {
            cin>>a>>b;
            arr[a] = b;
        }
        else if (op==2) {
            cin>>a>>b;
            for (int j=a;j<=b;++j) {
                if (arr[j]) arr[j] = 0;
                else arr[j] = 1;
            }
        }
        else if (op==3) {
            cin>>a>>b;
            for (int j=a;j<=b;++j) {
                arr[j] = 0;
            }
        }
        else {
            cin>>a>>b;
            for (int j=a;j<=b;++j) {
                arr[j] = 1;
            }
        }
    }
    for (int i=1;i<=n;++i) {
        cout<<arr[i]<<' ';
    }
}