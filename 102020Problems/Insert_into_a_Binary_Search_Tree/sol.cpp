#include <iostream>

struct BSTNode
{
    int val;
    BSTNode * left;
    BSTNode * right;
};

BSTNode* newNode(int data) {
    BSTNode* node = new (BSTNode);
    node->val = data;
    node->left = node->right = NULL;
    return (node);
}

BSTNode* insertLevelOrder(int arr[], BSTNode* root, int i, int n) {
    if (i < n) {
        BSTNode* temp = newNode(arr[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(arr,root->left,2*i+1, n);
        // insert right child
        root->right = insertLevelOrder(arr,root->right,2*i+2, n);
    }
    return root;
}

void inOrder(BSTNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        std::cout << root->val << " ";
        inOrder(root->right);
    }
}

int main () {
    int arr[] = { 1,2,3,4,5,6,6,6,6 };
    int n = sizeof(arr)/sizeof(arr[0]);
    BSTNode* root;
    root = insertLevelOrder(arr,root,0,n);
    inOrder(root);
    std::cout << std::endl;
}