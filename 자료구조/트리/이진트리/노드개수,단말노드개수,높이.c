#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

int get_node_count(TreeNode *node) {
    int cnt = 0;
    if (node != NULL) {
        cnt = 1 + get_node_count(node->left) + get_node_count(node->right);
    }
    return cnt;
}

int get_leaf_node(TreeNode *node) {
    int cnt = 0;
    if (node != NULL) {
        if (node->left == NULL && node->right == NULL) {
            return 1;
        }
        else {
            cnt = get_leaf_node(node->left) + get_leaf_node(node->right);
        }
    }
    return cnt;
}

int get_height(TreeNode *node) {
    int height = 0;
    if (node != NULL) {
        height = 1 + max(get_height(node->left),get_height(node->right));
    }
    return height;
}
