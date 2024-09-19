#include <stdio.h>
#include <stdlib.h>
#define KEY_SIZE 10 //탐색키의 최대 길이
#define TABLE_SIZE 13 //해싱 테이블의 크기=소수

typedef struct {
    char key[KEY_SIZE];
    //다른 필요한 필드들
} element;

element hash_table[TABLE_SIZE]; //헤시테이블 전역변수
#define empty(item) (strlen(item.key)==0)
#define equal(item1,item2) (!strcmp(item1.key,item2.key))
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

//이차조사법 : 선형조사법의 데이터가 밀집되있고 시간이 오래걸리기 때문에 데이터의 분산을 위해 제곱만큼 이동시킨다.
void hash_qp_add(element item, element ht[]) {
    int i, hash_value;
    hash_value = i = hash_function(item.key);
    int j = 1;

    while (!empty(ht[i])) {
        if (equal(item, ht[i])) {
            fprintf(stderr, "탐색키가 중복되었습니다.\n");
            exit(1);
        }
        i = (hash_value + j * j) % TABLE_SIZE; // j의 제곱만큼 이동
        j++; // j 증가
        if (j > TABLE_SIZE) { // 테이블이 가득 찼을 경우
            fprintf(stderr, "테이블이 가득찼습니다.\n");
            exit(1);
        }
    }
    ht[i] = item; // 항목 추가
}