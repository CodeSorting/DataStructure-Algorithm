#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define swap(x,y,t) ( (t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;
int sorted[MAX_SIZE]; //추가 공간이 필요
/*
i는 정렬된 왼쪽 리스트에 대한 인덱스
j는 정렬된 오른쪽 리스트에 대한 인덱스
k는 정렬될 리스트에 대한 인덱스
*/
void merge(int list[],int left,int mid,int right) {
    int i,j,k,l;
    i=left,j=mid+1,k=left;

    //분할 정렬된 list의 합병
    while (i<=mid && j<=right) {
        if (list[i] <= list[j]) //작은 걸 sorted에 넣기
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if (i>mid) { //i>mid여서 위의 식이 깨졌으면 j<=right라는 소리고 j를 sorted에 넣어준다.(분할해서 이미 나머지는 정렬되었으니 그냥 넣어도 된다.)
        for (l=j;l<=right;++l) {
            sorted[k++] = list[l];
        }
    }
    else { // i<=mid일 때
        for (l=i;l<=mid;++l) {
            sorted[k++] = list[l];
        }
    }
    //배열 sorted[]의 리스트를 배열 list[]에 복사
    for (l=left;l<=right;++l) {
        list[l] = sorted[l];
    }
}

//병합 정렬 : 분할 정복을 이용한 정렬
void merge_sort(int list[],int left,int right) {
    int mid;
    if (left<right) {
        mid = (left + right) / 2;
        merge_sort(list,left,mid);
        merge_sort(list,mid+1,right);
        merge(list,left,mid,right);
    }
}

int main() {
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for (int i=0;i<n;++i) {
        list[i] = rand() % 100; //난수 발생 범위 : 0~99
    }

    merge_sort(list,0,n-1);
    for (int i=0;i<n;++i) {
        printf("%d ",list[i]);
    }
    printf("\n");
    return 0;
}