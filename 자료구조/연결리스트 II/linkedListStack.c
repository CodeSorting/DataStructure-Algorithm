#include <stdio.h>
#include <malloc.h>

typedef int element;
typedef struct StackNode {
	element data;
	struct StackNode *link;
} StackNode;

typedef struct {
	StackNode *top;
} LinkedStackType;

/*
초기상태
value(NULL),NULL <-top(main의 s)

9 link <- top(main의 s) <- s(함수실행시) //이 상태라고 가정하자.
  |
7 link
  |
3 NULL
*/
void init(LinkedStackType *s) {
	s->top = NULL;
}

int is_empty(LinkedStackType *s) {
	return (s->top == NULL);
}

int is_full(LinkedStackType *s) {
	return 0; //linkedlist로 구현해서 상관 x
}

void push(LinkedStackType *s, element item) { 
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode)); //temp->data,link
	temp->data = item; //temp->item,link
	temp->link = s->top; //temp->item,link->9 link -> 7 link -> 3 NULL
	s->top = temp; // s->top(main의 s),temp->item,link->9 link -> 7 link -> 3 NULL
}

void print_stack(LinkedStackType *s) {
	for (StackNode *p = s->top; p != NULL; p = p->link) //p,top->9 link ....
		printf("%d->", p->data);
	printf("NULL \n");
}

element pop(LinkedStackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
        //                                      temp
        //                                        |
        //                                       \/
		StackNode *temp = s->top; //s->s(top)->9 link....
		int data = temp->data; //s->s(top)->9 link
		s->top = s->top->link; //s->s(top)->7 link... //temp -> 9 link
		free(temp); //s->s(top)->7 link... //temp가 가리키고 있는 곳을 사라지게 하니 9 link는 사라진다.
		return data;
	}
}

element peek(LinkedStackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		return s->top->data; //s->(메인함수 s의)top->9(data) link ...
	}
}

int main() {
	LinkedStackType s;
	init(&s);
	push(&s, 1); print_stack(&s);
	push(&s, 2); print_stack(&s);
	push(&s, 3); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	return 0;
}