#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define swap(x,y,t) ( (t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;
//https://gmlwjd9405.github.io/2018/05/06/algorithm-insertion-sort.html 여기 시각화 잘됨.
//삽입정렬 : index1부터 끝까지 차례대로 해당 값과 그 전 인덱스의 값들을 비교하면서 적정한 위치에 넣는다.
void insertion_sort(int list[],int n) {
    int i,j,key;
    for (i=1;i<n;++i) { //인덱스 1부터인 이유는 i=0이면 j=-1이 되어버리고 어차피 i=1로 해도 그 전 값과 비교를 하기 때문이다.
        key = list[i];
        for (j=i-1;j>=0 && list[j]>key;--j) {
            list[j+1] = list[j]; //해당 자리에 있던 것을 오른쪽으로 한칸 치우고
        }
        list[j+1] = key; //그 자리에 원래 값을 넣는다.
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
    insertion_sort(list,n);
    for (int i=0;i<n;++i) {
        printf("%d ",list[i]);
    }
    printf("\n");
    return 0;
}