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