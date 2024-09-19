/*
충돌 : 서로 다른 키가 같은 해시주소를 가지는 현상
빈 버킷이 없다면 오버플로우가 발생한다.

해결책
1. 개방 주소법(open addressing): 충돌이 일어난 항목을 해시 테이블의 다른 위치에 저장한다.
2. 체이닝(chaining): 해시테이블의 하나의 위치가 여러 개의 항목을 저장할 수 있도록 해시테이블의 구조를 변경한다.

개방 주소법 : 충돌이 발생하면 비어있는 버킷을 찾는 방법
비어있는 공간을 찾는 것을 조사(probing)이라고 한다.
1. 선형 조사법 : ht[k]가 비었다면 ht[k+1]을, ht[k+2]를... 조사한다. 조사 시작부분으로 돌아오면 다 찾다고 판단.
*/

//선형 조사법
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

#define empty(item) (strlen(item.key)==0)
#define equal(item1,item2) (!strcmp(item1.key,item2.key))
//선형 조사법을 이용하여 테이블에 키를 삽입하고, 테이블이 가득 찬 경우에는 종료
void hash_lp_add(element item,element ht[]) {
    int i,hash_value;
    hash_value = i = hash_function(item.key);
    while (!empty(ht[i])) {
        if (equal(item,ht[i])) {
            fprintf(stderr,"탐색키가 중복되었습니다.\n");
            exit(1);
        }
        i = (i+1) % TABLE_SIZE; //+1을 해서 값을 넣는다.
        if (i==hash_value) { //그런데 1바퀴 돌고 돌아왔다면 꽉 찬것이다.
            fprintf(stderr,"테이블이 가득찼습니다.\n");
            exit(1);
        }
    }
    ht[i] = item;
}

//선형 조사법을 이용하여 테이블에 저장된 키를 탐색
void hash_lp_search(element item,element ht[]) {
    int i,hash_value;
    hash_value = i = hash_function(item.key);
    while (!empty(ht[i])) {
        if (equal(item,ht[i])) {
            fprintf(stderr,"탐색 %s: 위치 = %d\n",item.key,i);
            return;
        }
        i = (i+1) % TABLE_SIZE;
        if (i==hash_value) {
            fprintf(stderr,"찾는 값이 테이블에 없음\n");
            return;
        }
    }
    fprintf(stderr,"찾는 값이 테이블에 없음.\n");
}

//해싱 테이블의 내용 출력
void hash_lp_print(element ht[]) {
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
        hash_lp_add(e,hash_table);
        hash_lp_print(hash_table);
    }
    for (int i=0;i<7;++i) {
        strcpy(e.key,s[i]);
        hash_lp_search(e,hash_table);
    }
    return 0;
}