#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n,m,q;
int R[100]; //분류기가 반환한 문장 단어 번호로 변환되어 있음
double T[501][501]; //i단어 이후에 j단어가 나올 확률(로그값)
double M[501][501]; //i단어가 j단어로 분류될 확률(로그값)
int choice[102][502];
double cache[102][502]; //1로 초기화시킨다.

double recognize(int segment,int previousMatch) {

}

string corpus[501];
string reconstruct(int segment,int previousMatch) {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>m>>q;
}