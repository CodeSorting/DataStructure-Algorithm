#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m;
//두 길이의 최솟값을 구하기 위해서는
//1. 양 끝점 사이의 거리
//2. 다른 선분에 내린 수선의 길이(벡터의 내적으로 확인했을 때 예각일 때)
double yonsei[2001][4];

double dist(double x1,double y1,double x2,double y2){ //두 점 사이의 거리
  return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

double inner(double x1,double y1,double x2,double y2){ //벡터 내적
  return (x1*x2)+(y1*y2);
}

bool check(double x1, double y1, double x2, double y2, double x3, double y3){ //두 직선이 예각,직각인거 체크
  double left = inner(x2-x1,y2-y1,x3-x1,y3-y1); 
  double right = inner(x1-x2,y1-y2,x3-x2,y3-y2);
  if (left>=0 && right>=0) return true; //내적 값이 양수거나 0이어야 사이의 각도가 예각이거나 직각이다.
  return false;
}

double height(double x1, double y1, double x2, double y2, double x3, double y3){ //삼각형 수선 길이
  double area = abs((x1*y2) + (x2*y3) + (x3*y1) - (x2*y1) - (x3*y2) - (x1*y3));
  return area/dist(x1,y1,x2,y2);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m; //신촌, 안암과 연결된 도로 개수
  for (int i=0;i<n;++i){ //신촌
    for (int j=0;j<4;++j){
      cin>>yonsei[i][j];
    }
  }

  double x1,y1,x2,y2,ans=-1;
  for (int i=0;i<m;++i){ //안암
    cin>>x1>>y1>>x2>>y2;
    for (int j=0;j<n;++j){
      double x3=yonsei[j][0],y3=yonsei[j][1],x4=yonsei[j][2],y4=yonsei[j][3];
      //1. 양 끝점 사이의 거리
      double temp = dist(x1,y1,x3,y3); 
      temp = min(temp,dist(x1,y1,x4,y4));
      temp = min(temp,dist(x2,y2,x3,y3));
      temp = min(temp,dist(x2,y2,x4,y4));
      //2. 다른 선분에 내린 수선의 길이(두 선분 사이의 각이 예각인지 체크)
      if (check(x1,y1,x2,y2,x3,y3)) temp = min(temp,height(x1,y1,x2,y2,x3,y3));
      if (check(x1,y1,x2,y2,x4,y4)) temp = min(temp,height(x1,y1,x2,y2,x4,y4));
      if (check(x3,y3,x4,y4,x1,y1)) temp = min(temp,height(x3,y3,x4,y4,x1,y1));
      if (check(x3,y3,x4,y4,x2,y2)) temp = min(temp,height(x3,y3,x4,y4,x2,y2));

      if (ans==-1) ans = temp;
      else ans = min(ans,temp);
    }
  }
  cout<<fixed;
  cout.precision(16);
  cout<<ans;
}