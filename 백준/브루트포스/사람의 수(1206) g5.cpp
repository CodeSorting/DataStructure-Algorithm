#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<double> avg(n);

    for (int i=0;i<n;++i) { //잘못된 점 : 입력 받을 때 그냥 받지 말고 소수 3자리만 받았어야 했다.
        cin>>avg[i];
        avg[i] = avg[i] - floor(avg[i]);
        avg[i] = round(avg[i] * 1000.0) / 1000.0;
    }

    bool flag;
    vector<double> cases(1001);
    for (int num=1;num<=1000;++num) { //사람 수마다 가능한지 확인
        for(int score=1;score<=num;++score){
            cases[score] = floor(((double)score / num) * 1000) / 1000.0; //평균 = score/num
        }
        flag = true;
        for(int j=0;j<n;++j){
            if(find(cases.begin(), cases.end(), avg[j]) == cases.end()){ //case의 모든 값 중에 평균이 해당하지 않을 경우
               flag = false;
               break;
            }
        }
        if(flag){
            cout<<num<<"\n";
            return 0;
        }
    }
}