#include <stdio.h>
#include <stdlib.h>
#define INDEX_SIZE 256
typedef struct {
    int key;
    int index;
} itable;
itable index_list[INDEX_SIZE]; 
int list[INDEX_SIZE]; //단, 배열은 정렬되어있어야 한다.

//색인순차탐색은 index 테이블을 이용하여 탐색의 효율을 높여야한다. O(m+n/m)
int search_index(int key,int n) {
    int i,low,high;

    //키 값이 범위 내가 아니면 종료
    if (key<list[0] || key>list[n-1]) return -1;

    //인덱스 테이블을 조사하여 해당키의 구간 결정
    for (i=0;i<INDEX_SIZE;++i) {
        if (index_list[i].key <= key && index_list[i+1].key > key) break;
    }

    if (i==INDEX_SIZE) {
        low = index_list[i-1].index;
        high = n;
    }
    else {
        low = index_list[i].index;
        high = index_list[i+1].index;
    }

    //예상되는 범위만 순차탐색
    return seq_search(key,low,high);
}