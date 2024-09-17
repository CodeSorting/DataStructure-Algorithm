#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define swap(x,y,t) ( (t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

//쉘정렬 : gap 만큼 떨어진 요소들을 삽입 정렬
//정렬의 범위는 first~last이다.
void inc_insertion_sort(int list[],int first,int last,int gap) {
    int i,j,key;
    for (i=first+gap;i<=last;i=i+gap) {
        key = list[i];
        for (j=i-gap;j>=first && key<list[j];j=j-gap) {
            list[j+gap] = list[j];
        }
        list[j+gap] = key;
    }
}

void shell_sort(int list[],int n) {
    int i,gap;
    for (gap=n/2;gap>0;gap=gap/2) {
        if (gap%2==0) gap++;
        for (i=0;i<gap;++i) { //gap 전만큼 계속 삽입연산 실행
            inc_insertion_sort(list,i,n-1,gap);
        }
    }
}

int main() {
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for (int i=0;i<n;++i) {
        list[i] = rand() % 100; //난수 발생 범위 : 0~99
    }

    shell_sort(list,n);
    for (int i=0;i<n;++i) {
        printf("%d ",list[i]);
    }
    printf("\n");
    return 0;
}