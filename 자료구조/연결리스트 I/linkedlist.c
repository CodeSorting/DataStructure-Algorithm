#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link; //listnode 타입의 객체를 가리키는 포인터
} ListNode;

void error(char *message) {
    fprintf(stderr,"%s\n",message);
    exit(1);
}

ListNode* insert_first(ListNode *head, int value) {
    //새로운 p 포인터가 할당받은 listnode를 가리키고 listnode(값,포인터)를 head로 변경하고 반환한다.
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value; //p->(value,link)
    p->link = head; //p -> 할당받음(value,link) -> head -> 값들->값들
    head = p; //head,p->할당받음->값들->값들 (head가 첫 노드가 된다.)
    return head;
}

ListNode* insert(ListNode *head, ListNode *pre, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value; //p->할당받음(value,link),  pre2->pre->노드1->노드2...
    p->link = pre->link; //p->할당->노드1->노드2
    pre->link = p; // pre2->pre->(p->할당)->노드1->노드2
    return head;
}

ListNode* delete_first(ListNode *head) {
    ListNode *removed;
    if (head==NULL) return NULL; //비어있을 때
    removed = head; //head,removed -> 첫칸 -> 둘째칸
    head = removed->link; //removed -> 첫칸,head -> 둘째칸(removed 뒤의 첫칸의 link를 가져갔으므로)
    free(removed); //removed 제거
    return head; //head 뒤부터 조회하므로 첫칸은 없어진다.
}

ListNode* delete(ListNode *head,ListNode *pre) {
    ListNode *removed;
    removed = pre->link; //pre->아무칸1->아무칸2일 때 removed->아무칸2
    pre->link = removed->link; //pre,removed->아무칸2
    free(removed); //removed 제거
    return head;
}

element get_entry(ListNode *head,int index) {
    ListNode *p;
    p = head;
    for (int i=0;i<index;++i) {
        p = p->link;
    }
    return p->data;
}

void print_list(ListNode *head) {
    for (ListNode *p = head; p!=NULL; p = p->link) {
        printf("%d->", p->data);
    }
    printf("NULL\n");
}

//노드 값 탐색 알고리즘
ListNode *search_list(ListNode *head, element x) {
  ListNode *p = head;
  while (p != NULL) {
    if (p->data == x) return p;
    p = p->link;
  }
  return NULL;
}

//리스트 합치기 알고리즘
ListNode* concat_list(ListNode *head1, ListNode *head2) {
    if (head1==NULL) return head2;
    else if (head2==NULL) return head1;
    else {
        ListNode *p;
        p = head1;
        while (p->link!=NULL) {
            p = p->link;
        }
        p->link = head2; //head1의 끝 다음을 head2로 놓는다.(p가 포인터이니 head1의 마지막 노드의 포인터도 또한 head2를 가리킨다.)
        return head1;
    }
}

//리스트 역순 알고리즘
ListNode* reverse(ListNode *head) {
    ListNode *p,*q,*r;
    p = head;
    q = NULL;
    while (p!=NULL) {
        r = q; //r은 이미 역순으로 변경된 리스트
        q = p; //p는 역순으로 만들 리스트
        p = p->link; //q는 현재 역순으로 만들 노드
        q->link = r;
    }
    return q;
}

int main() {
    ListNode *head = NULL;
    for (int i=0;i<5;++i) {
        head = insert_first(head,i);
        print_list(head);
    }
    if (search_list(head,2)) {
        printf("찾았음.\n");
    }
    for (int i=0;i<5;++i) {
        head = delete_first(head);
        print_list(head);
    }
    //두 개 리스트 합치기
    ListNode *head2 = NULL;
    for (int i=0;i<5;++i) {
        head2 = insert_first(head2,i+1);
        print_list(head2);
    }
    ListNode *head3 = NULL;
    for (int i=0;i<5;++i) {
        head3 = insert_first(head3,i+6);
        print_list(head3);
    }
    ListNode *total = concat_list(head2,head3);
    print_list(total);
    printf("%d\n",get_entry(total,3));
    ListNode *total2 = reverse(total);
    print_list(total2);
    return 0;
}