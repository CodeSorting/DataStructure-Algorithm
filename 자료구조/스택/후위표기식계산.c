#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int eval(char exp[]) {
    int op1,op2,value,i=0;
    int len = strlen(exp);
    char ch;
    StackType s;
    init_stack(&s);

    for (i=0;i<len;++i) {
        ch = exp[i];
        if (ch=='+' || ch=='-' || ch=='*' || ch=='/') { //연산자
            op2 = pop(&s);
            op1 = pop(&s);
            switch(ch) {
                case '+': push(&s,op1+op2); break;
                case '-': push(&s,op1-op2); break;
                case '*': push(&s,op1*op2); break;
                case '/': push(&s,op1/op2); break;
            }
        }
        else { //피연산자
            value = ch - '0';
            push(&s,value);
        }
    }
    return pop(&s);
}
int main() {
    int res;
    printf("후위표기식은 82/3-32*+\n");
    res = eval("82/3-32*+");
    printf("결과값은%d\n",res);
    return 0;
}