#include <iostream> // 투포인터 문제
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int count=1;
    int start_index=1;
    int end_index=1;
    int sum=1;
    
    while (end_index!=n){
        if (sum==n){
            count++;
            end_index++;
            sum = sum+ end_index;
        }
        else if(sum>n){
            sum = sum-start_index;
            start_index++;
        }
        else{ 
            end_index++;
            sum=sum+end_index;
        } // sum<n일 경우
    }
    cout<<count<<"\n";
    
}