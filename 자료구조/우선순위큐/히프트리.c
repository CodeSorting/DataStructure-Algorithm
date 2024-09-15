#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct {
    int key;
} element;
typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType* create() {
    return (HeapType *)malloc(sizeof(HeapType));
}

void init(HeapType *h) {
    h->heap_size = 0;
}

//현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
//삽입 함수 : 제일 마지막에 값을 넣고 비교하면서 값을 부모 노드 쪽으로 올린다.
void insert_max_heap(HeapType *h,element item) {
    int i;
    i = ++(h->heap_size);
    while ((i!=1) && (item.key > h->heap[i/2].key)) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

//삭제 함수 : 제일 작은 말단 값을 루트 노드로 놓고 자식노드와 값을 비교해나가며 위치를 수정한다.
element delete_max_heap(HeapType *h) {
    int parent, child;
    element item, temp;

    item = h->heap[1]; //루트 노드 값 저장
    temp = h->heap[(h->heap_size)--]; // 제일 작은 값을 저장하고(나중에 비교를 위해서임.) size-1함.
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        //현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
        if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key) {
            child++; //왼쪽 자식노드와 오른쪽 자식노드 중 큰 값을 택한다.
        }
        if (temp.key >= h->heap[child].key) break; //말단 값의 적당한 위치를 찾았다면 그만한다.
        //한 단계 아래(자식노드)로 값 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item; //루트 노드 반환(제일 큰값)
}

//히프 정렬 구현
void heap_sort(element a[], int n) {
    int i;
    HeapType *h;

    h = create();
    init(h);
    for (i=0;i<n;++i) {
        insert_max_heap(h, a[i]);
    }
    for (i=(n-1);i>=0;--i) {
        a[i] = delete_max_heap(h);
    }
    free(h);
}

int main() {
    element e1 = {10}, e2 = {20}, e3 = {30};
    element e4,e5,e6;
    HeapType *heap;
    
    heap = create();
    init(heap);

    insert_max_heap(heap, e1);
    insert_max_heap(heap, e2);
    insert_max_heap(heap, e3);

    e4 = delete_max_heap(heap);
    printf("< %d > ",e4.key);
    e5 = delete_max_heap(heap);
    printf("< %d > ",e5.key);
    e6 = delete_max_heap(heap);
    printf("< %d > ",e6.key);
    printf("\n");
    free(heap);

    element list[8] = {23,56,11,9,56,99,27,34};
    heap_sort(list,8);
    for (int i=0;i<8;++i) {
        printf("%d ",list[i].key);
    }
    printf("\n");
    return 0;
}