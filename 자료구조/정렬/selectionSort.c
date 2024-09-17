#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define swap(x,y,t) ( (t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

//선택 정렬 : 최솟값 얻고 제일 첫 원소에, 최솟값 얻고 두번째 원소에, 최솟값 얻고 세번째 원소에....끝 - 1번 원소까지 반복
void selection_sort(int list[],int n) {
    int i,j,least,temp;
    for (i=0;i<n-1;++i) {
        least = i;
        for (j=i+1;j<n;++j) {
            if (list[j] < list[least]) least = j; //최솟값 탐색
        }
        // if (i != least) 를 하면 자기자신을 swap하지 않는다.
        swap(list[i],list[least],temp);
    }
}

int main() {
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for (int i=0;i<n;++i) {
        list[i] = rand() % 100; //난수 발생 범위 : 0~99
    }

    selection_sort(list,n);
    for (int i=0;i<n;++i) {
        printf("%d ",list[i]);
    }
    printf("\n");
    return 0;
}