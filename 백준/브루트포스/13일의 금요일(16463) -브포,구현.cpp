#include <iostream>
#include <algorithm>
using namespace std;

int n,year=2019,cnt=0;
long long day = 13;
int normal[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int yun[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string yo[7] = {"월","화","수","목","금","토","일"};
/*
재운이를 도와 2019년부터 N년까지 누적되는 13일의 금요일의 수를 계산하여 알려주자. (2019<=n<=100000) 2019년 1월 1일은 화요일
*/
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  while (year<=n){
    if ((year%4==0 && year%100!=0) || (year%400==0)){ //윤년
      for (int i=0;i<12;++i){
        if (yo[day%7]=="금"){
          cnt++;
        }
        day += yun[i];
      }
    }
    else{
      for (int i=0;i<12;++i){
        if (yo[day%7]=="금"){
          cnt++;
        }
        day += normal[i];
      }
    }
    year++;
  }
  cout<<cnt;
}