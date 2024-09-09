#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
typedef char element;
typedef struct {
    element *data; //동적할당스택을 위한 포인터
    int top;
    int capacity; //동적할당의 수용공간, 부족할 때마다 2배씩 늘릴 예정이다.
} StackType;

//스택 초기화
void init_stack(StackType *s) {
    s->top = -1;
    s->capacity = 1;
    s->data = (element *)malloc(s->capacity * sizeof(element)); //수용능력 * element
}

//공백 상태 검출 함수
int is_empty(StackType *s) {
    return (s->top==-1);
}

//가득 찼는지 확인
int is_full(StackType *s) {
    return (s->top==(s->capacity-1));
}

//삽입함수
void push(StackType *s,element value) {
    if (is_full(s)) {
        s->capacity *=2;
        s->data = (element *)realloc(s->data,s->capacity * sizeof(element));
    }
    s->data[++(s->top)] = value;
}

//삭제함수
element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr,"스택이 비어있습니다.\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

//맨 위의 원소 반환
element peek(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr,"스택이 비어있습니다.\n");
        exit(1);
    }
    else return s->data[s->top];
}

int check_matching(const char *in) {
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in); //n=문자열의 길이
    init_stack(&s); //스택 초기화

    for (i=0;i<n;++i) {
        ch = in[i];
        switch (ch) {
            case '(': case '[': case '{':
                push(&s,ch);
                break;
            case ')': case ']': case '}':
                if (is_empty(&s)) return 0;
                else {
                    open_ch = pop(&s);
                    if ( (open_ch == '(' && ch != ')' ) || (open_ch == '[' && ch != ']' ) || (open_ch == '{' && ch != '}' )) return 0;
                    break;
                }
        }
    }
    if (!is_empty(&s)) return 0; //스택이 남아있으면 오류
    return 1;
}
int main() {
    char *p = "{ A[(i+1)]=0; }";
    if (check_matching(p)) printf("%s 괄호검사 성공!\n",p); // 포인터 p가 char 배열의 첫주소를 가리키니 *p가 아닌 p로 한꺼번에 출력한다.
    else printf("%s 괄호검사 실패!\n",p); 
}