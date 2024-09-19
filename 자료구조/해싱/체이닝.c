/*
충돌 : 서로 다른 키가 같은 해시주소를 가지는 현상
빈 버킷이 없다면 오버플로우가 발생한다.

해결책
1. 개방 주소법(open addressing): 충돌이 일어난 항목을 해시 테이블의 다른 위치에 저장한다.
2. 체이닝(chaining): 해시테이블의 하나의 위치가 여러 개의 항목을 저장할 수 있도록 해시테이블의 구조를 변경한다.

*/
#include <stdio.h>
#include <stdlib.h>
#define KEY_SIZE 10 //탐색키의 최대 길이
#define TABLE_SIZE 7 //해싱 테이블의 크기=소수
typedef struct {
    int key;
    //다른 필요한 필드들
} element;

struct list {
    element item; //값
    struct list *link; //포인터
};
struct list *hash_table[TABLE_SIZE]; //해시테이블 리스트

int hash_function(int key) {
    return key % TABLE_SIZE;
}

//체인법을 이용하여 테이블에 키를 삽입
void hash_chain_add(element item,struct list *ht[]) {
    int hash_value = hash_function(item.key);
    struct list *ptr;
    struct list *node_before = NULL, *node = ht[hash_value]; //node -> ht[hash_value]
    //node_before이 없다면 for문을 순회가 끝나면 node가 null을 가리키고 있기 때문에 전 노드가 필요하다.
    for (; node; node_before = node, node = node->link) { //이미 저장되어있으면 돌아가기
        if (node->item.key == item.key) {
            fprintf(stderr,"이미 탐색키가 저장되어 있음\n");
            return;
        }
    }
    ptr = (struct list *)malloc(sizeof(struct list)); //ptr ->list(item,link(null))
    ptr->item = item;
    ptr->link = NULL;
    if (node_before) node_before->link = ptr; //node_before에 무언가 있었다면
    else ht[hash_value] = ptr; //ht[hash_value]가 NULL이었을 때
}

//체인법을 이용하여 테이블에 저장된 키를 탐색
void hash_chain_search(element item,struct list *ht[]) {
    struct list *node;
    int hash_value = hash_function(item.key);
    for (node = ht[hash_value]; node; node=node->link) {
        if (node->item.key == item.key) {
            fprintf(stderr,"탐색 %d 성공 \n",item.key);
            return;
        }
    }
    printf("키를 찾지 못했음\n");
}

//해싱 테이블의 내용 출력
void hash_chain_print(struct list *ht[]) {
    struct list *node;
    int i;
    printf("\n==========================\n");
    for (i=0;i<TABLE_SIZE;++i){
        printf("[%d]->",i);
        for (node=ht[i];node;node=node->link) {
            printf("%d->",node->item.key);
        }
        printf("\n");
    } 
    printf("==========================\n\n");
}
#define SIZE 5

int main() {
    int data[SIZE] = {8,1,9,16,13};
    element e;
    for (int i=0;i<SIZE;++i) {
        e.key = data[i];
        hash_chain_add(e,hash_table);
        hash_chain_print(hash_table);
    }
    for (int i=0;i<SIZE;++i) {
        e.key = data[i];
        hash_chain_search(e,hash_table);
    }
    return 0;
}