#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIST_SIZE 100
typedef int element;
typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
} ArrayListType;

void error(char *message) {
    fprintf(stderr, "%s\n",message);
    exit(1);
}

void init(ArrayListType *L) {
    L->size = 0;
}

int is_empty(ArrayListType *L) {
    return L->size==0;
}

int is_full(ArrayListType *L) {
    return L->size==MAX_LIST_SIZE;
}

element get_entry(ArrayListType *L,int pos) {
    if (pos<0 || pos >= L->size) error("위치 오류");
    return L->array[pos];
}

void print_list(ArrayListType *L) {
    int i;
    for (i=0;i<L->size;++i) {
        printf("%d->", L->array[i]);
    }
    printf("\n");
}

void insert(ArrayListType *L, int pos, element item) {
    if (!is_full(L) && pos>=0 && pos<=L->size) {
        for (int i=(L->size-1);i>=pos;--i) {
            L->array[i+1] = L->array[i];
        }
        L->array[pos] = item;
        L->size++;
    }
}

void insert_last(ArrayListType *L, element item) {
	if (L->size >= MAX_LIST_SIZE) {
		error("스택 오버 플로우");
	}
	L->array[L->size++] = item;
}

element delete(ArrayListType *L, int pos) {
    element item;
    if (pos<0 || pos>= L->size) error("위치오류");
    item = L->array[pos];
    for (int i=pos;i<(L->size-1);++i) {
        L->array[i] = L->array[i+1];
    }
    L->size--;
    return item;
}

element delete_last(ArrayListType *L) {
    element item;
    if (is_empty(L)) error("공백이다.");
    item = L->array[L->size-1];
    L->size--;
    return item;
}

int get_length(ArrayListType *L) {
    return L->size;
}

void replace(ArrayListType *L, int pos,int item) {
    if (pos<0 || pos>L->size-1) error("인덱스 오류");
    L->array[pos] = item;
}

void clear(ArrayListType *L) {
    L->size = 0;
    for (int i=0;i<MAX_LIST_SIZE;++i) {
        L->array[i] = -1;
    }
}

int main() {
    ArrayListType list;
    init(&list);
    insert(&list,0,10); print_list(&list);
    insert(&list,0,20); print_list(&list);
    insert(&list,0,30); print_list(&list);
    insert_last(&list,40); print_list(&list);
    delete(&list,0); print_list(&list);
    delete_last(&list); print_list(&list);
    replace(&list,1,55); print_list(&list);
    printf("%d\n",get_length(&list));
}