#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n<2) return false;
    for (int i=2;i*i<=n;++i) {
        if (n%i==0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n;
    cin>>m>>n;
    int sum = 0,first = -1;
    bool flag = true;
    for (int i=m;i<=n;++i) {
        if (isPrime(i) && flag) {
            first = i;
            sum += i;
            flag = false;
        }
        else if (isPrime(i)) sum += i;
    }
    if (first==-1) cout<<-1;
    else {
        cout<<sum<<'\n'<<first;
    }
}