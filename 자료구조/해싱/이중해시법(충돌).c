//이중해시법 : 오버플로우가 발생함에 따라 항목을 저장할 다음 위치를 결정할 때
//원래 해시 함수와 다른 별개의 해시 함수를 이용하는 방법이다.
#include <stdio.h>
#include <stdlib.h>
#define KEY_SIZE 10 //탐색키의 최대 길이
#define TABLE_SIZE 13 //해싱 테이블의 크기=소수

typedef struct {
    char key[KEY_SIZE];
    //다른 필요한 필드들
} element;

element hash_table[TABLE_SIZE]; //헤시테이블 전역변수

//테이블 초기화
void init_table(element ht[]) {
    int i;
    for (i=0;i<TABLE_SIZE;++i) { //첫번째 문자 NULL로 만들기
        ht[i].key[0] = NULL;
    }
}

//문자로 된 키를 숫자로 변환
int transform(char *key) {
    int number = 0;
    while (*key) {
        number = number + (int)(*key);
        key++;
    }
    return number;
}

//제산 함수를 사용한 해싱 함수
int hash_function(char *key) {
    //키를 자연수로 변환한 다음 테이블 크기로 나누어 나머지를 반환
    return transform(key) % TABLE_SIZE;
}

int h1(char *key) {
    return transform(key) % TABLE_SIZE; // 첫 번째 해시 함수
}

int h2(char *key) {
    return 1 + (transform(key) % (TABLE_SIZE - 1)); // 두 번째 해시 함수, 1 이상의 값
}
#define empty(item) (strlen(item.key)==0)
#define equal(item1,item2) (!strcmp(item1.key,item2.key))

void hash_double_add(element item, element ht[]) {
    int i = h1(item.key);
    int j = 0;

    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "탐색키가 중복되었습니다.\n");
            exit(1);
        }
        j++; // 충돌 횟수 증가
        i = (i + j * h2(item.key)) % TABLE_SIZE; // 두 번째 해시 함수 사용
        if (j >= TABLE_SIZE) {
            fprintf(stderr, "테이블이 가득찼습니다.\n");
            exit(1);
        }
    }
    ht[i] = item; // 항목 추가
}

void hash_double_search(element item, element ht[]) {
    int i = h1(item.key);
    int j = 0;

    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "탐색 %s: 위치 = %d\n", item.key, i);
            return;
        }
        j++; // 충돌 횟수 증가
        i = (i + j * h2(item.key)) % TABLE_SIZE; // 두 번째 해시 함수 사용
        if (j >= TABLE_SIZE) {
            fprintf(stderr, "찾는 값이 테이블에 없음\n");
            return;
        }
    }
    fprintf(stderr, "찾는 값이 테이블에 없음.\n");
}

//해싱 테이블의 내용 출력
void hash_double_print(element ht[]) {
    int i;
    printf("\n==========================\n");
    for (i=0;i<TABLE_SIZE;++i) printf("[%d] %s\n",i,ht[i].key);
    printf("==========================\n\n");
}

int main() {
    char *s[7] = {"do","for","if","case","else","return","function"};
    element e;

    for (int i=0;i<7;++i) {
        strcpy(e.key,s[i]); //s[i] 안의 문자열 e.key에 넣기
        hash_double_add(e,hash_table);
        hash_double_print(hash_table);
    }
    for (int i=0;i<7;++i) {
        strcpy(e.key,s[i]);
        hash_double_search(e,hash_table);
    }
    return 0;
}