#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

void print_list(ListNode *head) {
    ListNode *p;

    if (head==NULL) return;
    p = head->link;
    do {
        printf("%d->",p->data);
        p = p->link;
    } while (p != head->link); //원형이 아닐경우 그냥 NULL만날 때 까지만 쓴다.
}

ListNode* insert_first(ListNode *head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data; //node->(data,link)
    if (head==NULL) { //head->아무것도 없음.
        head = node; //head,node->(data,link)
        node->link = head; //head,node->(data,link)->head 즉 원형이다.
        /*
        초기 상태: head -> NULL
        노드 생성 후: node -> [data: 10, link: ?]
        노드 추가 후: head -> [data: 10, link: head]
                               ↑                 |
                               └─────────────────┘
        */
    }
    else { //head->값1->값2->...
        node->link = head->link;//node->(data,link)->값1->값2
        head->link = node; //head,node->(data,link)->값1->값2
    }
    return head; //변경된 헤드 포인터를 반환한다.
}

ListNode* insert_last(ListNode *head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode)); //node->(값,포인터)
    node->data = data; //node->(data,포인터)
    if (head==NULL) { //head->아무것도 없음.
        head = node; //head,node->(data,포인터)
        node->link = head; //head,node->(data,link)->head
        /*
        초기 상태: head -> NULL
        노드 생성 후: node -> [data: 10, link: ?]
        노드 추가 후: head -> [data: 10, link: head]
                               ↑                 |
                               └─────────────────┘
        */
    }
    else { //head->값1->값2->...
        node->link = head->link;//node->(data,link)->값1->값2
        head->link = node; //head->node->(data,link)->값1->값2
        head = node; //head,node->(data,link)->값1->값2
    }
    return head; //변경된 헤드 포인터를 반환한다.
}

ListNode* search(ListNode* head, element data) {
	if (head->data == data)
		return head;
	else {
		for (ListNode* p = head->link; p != head; p = p->link)
			if (p->data == data)
				return p;
	}
	return NULL;
}

int get_size(ListNode* head) {
	if (head == NULL)
		return 0;

	int c = 0;
	ListNode* p = head;

	do {
		p = p->link;
		c++;
	} while (p != head);
	return c;
}

int main() {
    ListNode *head = NULL;

    //list = 10->20->30->40
    head = insert_last(head,20);
    head = insert_last(head,30);
    head = insert_last(head,40);
    head = insert_first(head,10);
    print_list(head);
    printf("\n%d\n",get_size(head)); //4
    ListNode *a = search(head,30);
    printf("%d\n",a->link->data); //30의 다음 데이터라서 40이다.
    return 0;
}