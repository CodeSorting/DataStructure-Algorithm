#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode *llink;
    struct DListNode *rlink;
} DListNode;

void init(DListNode *phead) { //phead=head -> A(llink,rlink) (llink,rlink 둘다 A를 가리킴)
    phead->llink = phead; 
    phead->rlink = phead;
}

void print_dlist(DListNode *phead) {
    DListNode *p;
    for (p=phead->rlink;p!=phead;p = p->rlink) { //phead에서 오른쪽으로 끝까지 센다.
        printf("<-| |%d| |->",p->data);
    }
    printf("\n");
}

//새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert(DListNode *before,element data) {
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
    newnode->data = data; 
    newnode->llink = before; 
    newnode->rlink = before->rlink; 
    before->rlink->llink = newnode; 
    before->rlink = newnode; 
} //before,head -> A(data,llink,rlink) <-->(element data) <--> B(data,llink,rlink)
  //                                         ^
  //                                         |
  //                                      newnode

//노드 removed를 삭제한다.
void ddelete(DListNode *head, DListNode *removed) {
    if (removed==head) return;
    removed->llink->rlink = removed->rlink; // removed
    removed->rlink->llink = removed->llink;
    free(removed);
}

int main() {
    DListNode *head = (DListNode *)malloc(sizeof(DListNode)); 
    init(head);
    printf("추가단계\n");
    for (int i=0;i<5;++i) {
        dinsert(head,i);
        print_dlist(head);
    }
    printf("삭제단계\n");
    for (int i=0;i<5;++i) {
        print_dlist(head);
        ddelete(head,head->rlink);
    }
    free(head);
    return 0;
}

//<-llink(특별노드까지 감.)4->rlink   <-llink 3 -> rlink  <-llink 2 -> rlink  <-llink 1 -> rlink <-llink 0 -> rlink <-llink 특별노드-> rlink(4까지 감.)
//                                                                                                                           ^
//                                                                                                                           |    
//                                                                                                                          head                      