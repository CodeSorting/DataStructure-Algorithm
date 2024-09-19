#include <stdio.h>
#include <stdlib.h>

//키도 int, 해시 테이블도 int일 때

//제산함수 : 나머지 연산자 mod를 이용하여 키를 해시 테이블의 크기로 나눈다.
//h(k) = k mod M (M=소수여야 골고루 분포된다.)
int M = 7;
int hash_function(int key) {
    int hash_index = key % M;
    if (hash_index < 0) hash_index += M;
    return hash_index;
}

//폴딩함수 : 주로 키가 해시테이블의 크기보다 더 큰 정수일 때 사용한다.
//예를 들어 키는 32비트이고 해시 테이블의 인덱스는 16비트일 경우 32비트 키를 16비트 2개로 나누어서
//비트 별로 XOR 연산이나 합연산을 한다. hash_index = (short)(key ^ (key>>16))
//이동폴딩 : 수를 여러 비트로 나누어서 더한다.
//경계폴딩 : 수를 여러 비트로 나누고 한번은 더하고 한번은 거꾸로 돌려서 더한다.
//중간제곱함수 : 키를 제곱한 다음, 중간의 몇 비트를 취해서 해시 주소를 생성한다.
//비트추출방법 : M = 2^k일 경우 이진수로 키를 간주하여 임의의 k개의 비트를 해시 주소로 사영하는 것이다.
//숫자분석방법 : 학번이 200212345라고 할 때 앞의 4자리는 년도이니 패스하고 골고루 분포되있는 뒷자리만 쓰는것이다.

/*탐색키가 문자열일 경우
1. a~z까지 1~26을 할당하기 -> 아스키코드를 주로 씀.
2. 첫번째 문자의 아스키코드값 사용하기 -> cup,car 구분 불가능
3. 아스키코드의 값을 모두 더한 값을 쓰기 -> cup,puc 구분 불가능
4. 아스키코드 값에 위치에 기초한 값을 곱하는 것
문자열 u가 있고 상수 g를 놓았을 때 
u0g^n-1 + u1g^n-2 + ... + un-1
=> (((u0g + u1)g + u2)g + ...)g + un-1
*/
//4번 구현
int g = 5;

int hash_function2(char *key) {
    int hash_index = 0;
    while (*key) {
        hash_index = g * hash_index + *key++;
    }
    return hash_index;
}
