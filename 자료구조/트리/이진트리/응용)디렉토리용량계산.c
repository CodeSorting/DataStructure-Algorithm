#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

//재귀로 모든 노드의 용량 합을 구한다.
int calc_dir_size(TreeNode *root) {
    int left_size, right_size;
    if (root == NULL) return 0;
    left_size = calc_dir_size(root->left);
    right_size = calc_dir_size(root->right);
    return (root->data + left_size + right_size);
}

int main() {
    TreeNode *n4 = { 500, NULL, NULL };
    TreeNode *n5 = { 200, NULL, NULL };
    TreeNode *n3 = { 100, &n4, &n5 };
    TreeNode *n2 = { 50, NULL, NULL };
    TreeNode *n1 = { 0, &n2, &n3 };
}