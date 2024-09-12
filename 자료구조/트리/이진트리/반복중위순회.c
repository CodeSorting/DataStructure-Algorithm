#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;
#define SIZE 100
int top = -1;
TreeNode *stack[SIZE]; //포인터 배열

void push(TreeNode *p) {
    if (top<SIZE-1) stack[++top] = p;
}

TreeNode *pop() {
    TreeNode *p = NULL;
    if (top>=0) p = stack[top--];
    return p;
}

//중위 순회
void inorder_iter(TreeNode *root) {
    while (1) {
        for (; root; root = root->left) { //왼쪽 서브트리를 스택에 넣으면 제일 밑의 왼쪽부터 값을 뺄 수 있다.
            push(root);
        }
        root = pop();
        if (!root) break; //NULL 값이면 멈춘다.
        printf("[%d]",root->data);
        root = root->right; //왼쪽을 다 빼면 오른쪽으로 간다.
    }
}
/*
      15
    4   20
  1    16 25
*/
TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 4,&n1,NULL };
TreeNode n3 = { 16,NULL,NULL };
TreeNode n4 = { 25,NULL,NULL };
TreeNode n5 = { 20,&n3,&n4 };
TreeNode n6 = { 15,&n2,&n5 };
TreeNode *root = &n6;


int main() {
    printf("중위 순회=");
    inorder_iter(root);
    printf("\n");
    return 0;
}