#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define swap(x,y,t) ( (t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

//버블정렬 : i=n-1~0까지 그 안에 j=0~i-1까지 해당 값이 그 다음값보다 크면 바꾸기
void bubble_sort(int list[],int n) {
    int i,j,temp;
    for (i=n-1;i>0;--i) { //한번 비교하면 가장 큰값이 맨 오른쪽으로 오게 되어서 n-1부터 시작하고 1까지만 진행해도 자동으로 제일 작은 값이 인덱스 0으로 간다.
        for (j=0;j<i;++j) {
            if (list[j]>list[j+1]) swap(list[j],list[j+1],temp);
        }
    }
}

int main() {
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for (int i=0;i<n;++i) {
        list[i] = rand() % 100; //난수 발생 범위 : 0~99
        printf("%d ",list[i]);
    }
    printf("\n");
    bubble_sort(list,n);
    for (int i=0;i<n;++i) {
        printf("%d ",list[i]);
    }
    printf("\n");
    return 0;
}