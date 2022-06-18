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

int height(TreeNode *root) {

    if (root == NULL)
        return 0;

    int left_sub = height(root->left);
    int right_sub = height(root->right);

    int ht = 1 + max(left_sub, right_sub);

    return ht;
}

int diameter(TreeNode *root) {
    int result = 0;
    diameter_util(root, result);
    return result;
}

void diameter_util(TreeNode *root, int &result) {

    if (root == NULL)
        return;

    int lh = height(root->left);
    int rh = height(root->right);

    result = max(result, 1+lh+rh);

    diameter_util(root->left, result);
    diameter_util(root->right, result);
}