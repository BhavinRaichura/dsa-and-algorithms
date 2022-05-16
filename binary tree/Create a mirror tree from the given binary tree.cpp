/*
Create a mirror tree from the given binary tree
https://www.geeksforgeeks.org/create-a-mirror-tree-from-the-given-binary-tree/

Given a binary tree, the task is to create a new binary tree which is a mirror image of the given binary tree.

Examples: 
Input:
        5
       / \
      3   6
     / \
    2   4
Output:
Inorder of original tree: 2 3 4 5 6 
Inorder of mirror tree: 6 5 4 3 2
Mirror tree will be:
  5
 / \
6   3
   / \
  4   2

Input:
        2
       / \
      1   8
     /     \
    12      9
Output:
Inorder of original tree: 12 1 2 8 9 
Inorder of mirror tree: 9 8 2 1 12
*/

//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


void create_mirror(Node** root, Node* node){
    if (node==NULL) return;
    *root=new Node(node->data);
    create_mirror(&(*root)->right,node->left);
    create_mirror(&(*root)->left,node->right);
}

void prefix(Node * root){
    if (root==NULL) return;
    cout<<root->data<<"    ";
    prefix(root->left);
    prefix(root->right);
}


// { Driver Code Starts.
int main()
{
    // given binary tree
    Node* root = new Node(1);
    root->left= new Node(2);
    root->right = new Node(3);
    root->left->left= new Node(5);
    root->left->right = new Node(6);
    root->right->left= new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(10);
    root->right->right->left->right = new Node(11);
    
    cout<<"\nroot\n";
    prefix(root);
    
    Node * newroot = new Node(0);
    create_mirror(&newroot,root);
    
    cout<<"\nnew root\n";
    prefix(newroot);

    return 0;
}  // } Driver Co

