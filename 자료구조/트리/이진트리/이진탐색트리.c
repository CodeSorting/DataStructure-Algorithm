#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef int element;
typedef struct TreeNode {
    element key;
    struct TreeNode *left, *right;
} TreeNode;

//노드 탐색(값 비교)
TreeNode* search(TreeNode *node,int key) {
    if (node==NULL) return NULL;
    if (key==node->key) return node;
    else if (key<node->key) { //찾으려는 값이 현재 노드보다 작을 경우
        return search(node->left,key);
    }
    else {
        return search(node->right,key);
    }
}

//새 노드 만들기
TreeNode* new_node(int item) {
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

//값을 비교하면서 넣을 노드의 위치 찾기
TreeNode* insert_node(TreeNode *node,int key) {
    if (node==NULL) return new_node(key);

    if (key < node->key) {
        node->left = insert_node(node->left,key);
    }
    else if (key > node->key) {
        node->right = insert_node(node->right,key);
    }
    return node;
}

//맨 왼쪽이 최솟값
TreeNode* min_value_node(TreeNode *node) {
    TreeNode *current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

//이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고
//새로운 루트 노드를 반환한다.
TreeNode *delete_node(TreeNode *root, int key) {
    if (root == NULL) return root;
    //먼저 해당 노드의 값을 찾는다.
    if (key < root->key){
        root->left = delete_node(root->left,key);
    }
    else if (key > root->key){
        root->right = delete_node(root->right,key);
    }
    else { //키 값에 해당하는 노들를 찾았다면 삭제하자.
        //삭제하려는 노드가 단말노드이거나 하나의 서브트리만 가지고 있을 경우
        if (root->left == NULL) { //왼쪽 서브트리 없음
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) { //오른쪽 서브트리 없음
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        //둘 다 있을 때
        TreeNode *temp = min_value_node(root->right); //왼쪽 서브트리에서 제일 큰 값 or 오른쪽 서브트리에서 제일 작은 값을 위로 세워야한다.
        root->key = temp->key;
        root->right = delete_node(root->right,temp->key);
    }
    return root;
}

void inorder(TreeNode *root) {
    if (root) {
        inorder(root->left);
        printf("[%d] ",root->key);
        inorder(root->right);
    }
}

int main() {
    TreeNode *root = NULL;
    TreeNode *tmp = NULL;

    root = insert_node(root,30);
    root = insert_node(root,20);
    root = insert_node(root,10);
    root = insert_node(root,40);
    root = insert_node(root,50);
    root = insert_node(root,60);
    root = delete_node(root,50);
    printf("이진 탐색 트리 중위 순회 결과 \n");
    inorder(root);
    if (search(root,20) != NULL){
        printf("이진 탐색 트리에서 20을 발견함 \n");
    }
    else {
        printf("이진 탐색 트리에서 20을 발견못함 \n");
    }
    return 0;
}