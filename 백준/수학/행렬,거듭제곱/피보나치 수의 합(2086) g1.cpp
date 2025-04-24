#include <iostream>
#include <map>
using namespace std;
typedef unsigned long long ull;
#define MOD 1000000000
map<ull,ull> m;
ull fibo(ull x){
    if (m[x]) return m[x]; //메모이제이션
    ull result;
    if (x%2==0) result = (fibo(x/2)*(fibo(x/2 + 1) + fibo(x/2 - 1))) % MOD;
    else result = ((fibo((x+1)/2) * fibo((x+1)/2))%MOD)+((fibo((x-1)/2)*fibo((x-1)/2))%MOD)%MOD;
    return m[x] = result % MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ull a,b;
    cin>>a>>b;
    m[0] = 0; m[1] = 1; m[2] = 1;
    cout<<(fibo(b + 2) + MOD - fibo(a + 1)) % MOD;
}