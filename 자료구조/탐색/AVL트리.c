#include <stdio.h>
#include <stdlib.h>

int max(int a,int b) {
    if (a>b) return a;
    else return b;
}

//AVL 트리 노드 정의 (완전 이진 균형 트리)
typedef struct AVLNode {
    int key;
    struct AVLNode *left, *right;
} AVLNode;

//노드를 동적으로 생성
AVLNode* create_node(int key) {
    AVLNode* node = (AVLNode *)malloc(sizeof(AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

//    3(parent)         2
//  2(child)       -> 1   3
//1 
AVLNode* rotate_right(AVLNode *parent) {
    AVLNode *child = parent->left; // child ->2
    parent->left = child->right; //parent
    child->right = parent; //child->right(parent)
    return child;
}
//1(parent)       2
//  2(child) -> 1   3
//    3
AVLNode* rotate_left(AVLNode *parent) {
    AVLNode *child = parent->right;
    parent->right = child->left;
    child->left = parent;
    return child;
}

//트리 높이 반환
int get_height(AVLNode *node) {
    int height = 0;
    if (node != NULL) {
        height = 1 + max(get_height(node->left),get_height(node->right));
    }
    return height;
}

//노드의 균형인수를 반환
int get_balance(AVLNode *node) {
    if (node==NULL) return 0;
    return get_height(node->left) - get_height(node->right);
}

AVLNode* insert(AVLNode *node, int key) {
    //아예 없으면 새로 만들기
    if (node==NULL) return (create_node(key));

    //점점 아래로 적정한 위치를 찾는다.
    if (key < node->key) { //작으면 왼쪽으로
        node->left = insert(node->left,key);
    }
    else if (key > node->key) { //크면 오른쪽으로
        node->right = insert(node->right,key);
    }
    else return node; //동일한 키는 허용하지 않음.

    int balance = get_balance(node);

    //LL 타입 처리
    if (balance > 1 && key < node->left->key) return rotate_right(node);
    //RR 타입 처리
    if (balance < -1 && key > node->right->key) return rotate_left(node);
    //LR 타입 처리
    if (balance > 1 && key > node->left->key) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }
    //RL 타입 처리
    if (balance < -1 && key < node->right->key) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}

//전위 순회
void preorder(AVLNode *root) {
    if (root != NULL) {
        printf("[%d] ", root->key); //루트
        preorder(root->left); //왼쪽
        preorder(root->right); //오른쪽
    }
}

int main() {
    AVLNode *root = NULL;

    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,40);
    root = insert(root,50);
    root = insert(root,29);
    root = insert(root,39);
    root = insert(root,60);
    printf("전위 순회 결과 \n");
    preorder(root);
    return 0;
}
