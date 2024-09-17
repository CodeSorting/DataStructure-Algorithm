#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define swap(x,y,t) ( (t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;
//피벗을 기준으로 작은 값들과 큰 값들을 분리한다.
int partition(int list[],int left,int right) {
    int pivot, temp;
    int low,high;

    low = left; 
    high = right + 1;
    pivot = list[left];
    do {
        do {
            low++;
        } while (list[low]<pivot); // 피벗보다 큰 값을 찾을 때까지 low 증가
        do {
            high--;
        } while (list[high]>pivot); // 피벗보다 작은 값을 찾을 때까지 high 감소
        if (low<high) swap(list[low],list[high],temp); 
    } while (low<high); //low가 high보다 작을때까지 계속한다.

    swap(list[left],list[right],temp);
    return high;
}

//퀵 정렬 : 분할 정복과 pivot을 이용한 정렬
void quick_sort(int list[],int left,int right) {
    int mid;
    if (left<right) {
        int q = partition(list,left,right);
        quick_sort(list,left,q-1);
        quick_sort(list,q+1,right);
    }
}

int main() {
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for (int i=0;i<n;++i) {
        list[i] = rand() % 100; //난수 발생 범위 : 0~99
    }

    quick_sort(list,0,n-1);
    for (int i=0;i<n;++i) {
        printf("%d ",list[i]);
    }
    printf("\n");
    return 0;
}