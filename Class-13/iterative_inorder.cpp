#include<iostream>
#include<stack>
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

void push_left(TreeNode *current, stack<TreeNode*> &s) {
    while (current != NULL) {
        s.push(current);
        current = current->left;
    }
}

void iterative_inorder(TreeNode *root) {
    stack<TreeNode*> s;

    // initiate the inorder traversal on the root node
    push_left(root, s);

    while (!s.empty()) {
        TreeNode *current = s.top();
        s.pop();

        cout<<current->data<< " ";

        // initiate the inorder traversal of right subtree
        push_left(current->right, s)
    }
}