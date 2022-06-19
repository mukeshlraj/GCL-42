#include<iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

bool check_bst_util (TreeNode *root, int low, int high) {
    if (root == NULL) {
        return true;
    }

    if (root->data < low or root->data > high)
        return false;

    return check_bst_util(root->left, low, root->data - 1) and check_bst_util(root->right, root->data + 1, high);
}

bool check_bst(TreeNode *root) {
    return check_bst_util(root, -10000, 10000);
}