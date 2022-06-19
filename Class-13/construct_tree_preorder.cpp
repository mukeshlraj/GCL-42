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

// TC : O(n^2)
// Aux Space : O(n)
// Convert the searching part to O(1) by storinfg inorder array in hashmap, then TC will become O(n)

TreeNode *construct_bt_util(vector<int> &inorder, vector<int> &preorder, int in_start, int in_end, int &pre_index) {

    if (in_start > in_end) {
        return NULL;
    }

    TreeNode *root = new TreeNode(preorder[pre_index]);
    pre_index++;

    // Search for the current value in inorder
    int index = in_start;
    for(int i=in_start+1; i<=in_end; i++) {
        if (inorder[i] == root->data) {
            index = i;
            break;
        }
    }

    root->left = construct_bt_util(inorder, preorder, in_start, index-1, pre_index);
    root->right = construct_bt_util(inorder, preorder, index+1, in_end, pre_index);

    return root;
}

TreeNode *construct_bt(vector<int> inorder, vector<int> preorder) {
    int pre_index = 0;
    return construct_bt_util(inorder, preorder, 0, inorder.size() - 1, pre_index);
}