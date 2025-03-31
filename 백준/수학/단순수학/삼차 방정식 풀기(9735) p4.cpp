#include <iostream>
#include <algorithm> 
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
typedef long long ll;

const double diff = 1e-4; //오차 범위위

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while (n--) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if (a<0) a=-a,b=-b,c=-c,d=-d;
        int x1 = 0; //삼차 방정식의 첫 해 찾기
        for (int i=-1000000;i<=1000000;++i) {
            if (a*i*i*i + b*i*i + c*i + d == 0) {
                x1 = i;
                break;
            }
        }
        b = b + a*x1;
        c = c + b*x1;
        int D = b*b - 4*a*c; //2차방정식 판별식
        auto print = [&](vector<double> v) {
            sort(v.begin(),v.end());
            vector<double> v2;
            for (int i=0;i<v.size();++i) {
               if (!v2.size() || fabs(v[i] - v2.back())> diff) v2.push_back(v[i]);
            }
            cout.precision(9);
            for (double x: v2) cout<<fixed<<x<<' ';
            cout<<'\n';
        };
        if (D<0) {
            print({(double)x1});
        }
        else if (D==0) {
            double x2 = (double) -b/(2*a);
            print({(double)x1,x2});
        }
        else {
            vector<double> v;
            v.push_back((double)x1);
            v.push_back(((double) -b - sqrt(D)) / (2*a));
            v.push_back(((double) -b + sqrt(D)) / (2*a));
            print(v);
        }
    }
}