#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int element;
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

int main() {
    StackType s;
    init_stack(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    printf("%d\n",pop(&s));
    printf("%d\n",peek(&s));
    printf("%d\n",pop(&s));
    printf("%d\n",pop(&s));
    free(s.data);
    return 0;
}