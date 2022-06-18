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

// TC : O(n)
void preorder(TreeNode *root) {

    if (root == NULL) {
        return;
    }

    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

// TC : O(n)
void postorder(TreeNode *root) {

    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}

// TC : O(n)
void inorder(TreeNode *root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

// TC : O(n)
void level_order(TreeNode *root) {

    if (root == NULL) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *current = q.front();
        q.pop();

        cout<<current->data;

        if (current->left != NULL)
            q.push(current->left);

        if (current->right != NULL)
            q.push(current->right);
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout<<"Preorder: "<<endl;
    preorder(root);
    cout<<endl;

    cout<<"Postorder: "<<endl;
    postorder(root);
    cout<<endl;

    cout<<"Inorder: "<<endl;
    inorder(root);
    cout<<endl;

    return 0;
}