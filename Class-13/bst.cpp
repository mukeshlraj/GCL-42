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

// TC : O(height)
// Aux Space : O(height)
bool search(TreeNode *root, int find) {

    if (root == NULL) {
        return false;
    }

    if (root->data == find) {
        return true;
    }
    if (find < root->data) {
        return search(root->left, find);
    }
    return search(root->right, find);
}

// TC : O(height)
// Aux Space : O(1)
bool search_iter(TreeNode *root, int find) {
    while (root != NULL) {
        if (root->data == find)
            return true;

        if (find < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

TreeNode *insert(TreeNode *root, int val) {
    if (root == NULL)
        return new TreeNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);

    else
        root->right = insert(root->right, val);

    return root;
}

int get_smallest(TreeNode *root) {
    while (root->left!=NULL)
        root = root->left;

    return root->data;
}

TreeNode *deleteNode(TreeNode *root, int val) {

    if (root == NULL)
        return NULL;

    if (val == root->data) {
         // If no child
         if(root->left == NULL && root->right == NULL)
             return NULL;

         // If single child
         if(root->left == NULL)
             return root->right;

         if(root->right == NULL)
             return root->left;

         // if two children
         int inorder_succ = get_smallest(root->right);
         root->data = inorder_succ;

         root->right = deleteNode(root->right, inorder_succ);
    } else if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else {
        root->right = deleteNode(root->right, val);
    }

    return root;
}