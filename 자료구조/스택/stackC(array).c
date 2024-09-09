#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

//스택 초기화
void init_stack(StackType *s) {
    s->top = -1;
}

//공백 상태 검출 함수
int is_empty(StackType *s) {
    return (s->top==-1);
}

//가득 찼는지 확인
int is_full(StackType *s) {
    return (s->top==(MAX_STACK_SIZE-1));
}

//삽입함수
void push(StackType *s,element value) {
    if (is_full(s)) {
        fprintf(stderr,"스택이 가득찼습니다.\n");
        return;
    }
    else s->data[++(s->top)] = value;
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
}