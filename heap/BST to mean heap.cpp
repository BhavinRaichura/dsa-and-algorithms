/*
Given a binary search tree which is also a complete binary tree. The problem is to convert the given BST into a Min Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Min Heap. 
Examples: 
Input :          4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  

Output :        1
              /   \
             2     5
           /  \   /  \
          3   4  6    7 

The given BST has been transformed into a Min Heap.
All the nodes in the Min Heap satisfies the given condition, that is, values in the left subtree of a node should be less than the values in the right subtree of the node. 
*/

algo
// Create an array arr[] of size n, where n is the number of nodes in the given BST.
// Perform the inorder traversal of the BST and copy the node values in the arr[] in sorted order.
// Now perform the preorder traversal of the tree.
// While traversing the root during the preorder traversal, one by one copy the values from the array arr[] to the nodes.
  
  
class Node{
public:
    int data;
    Node*left;
    Node*right;

    Node(int val){
        data= val;
    }
};

class Solution{
private:
    vector<int>arr;
    int i=0;

public:
    void export_data_inorder(Node *root){
        if (root==NULL) return;
        export_data_inorder(root->left);
        arr.push_back(root->data);
        cout<<root->data<<"   ";
        export_data_inorder(root->right);
    }
    void import_preorder(Node**root){
        if(*root==NULL) return;
        if(i>=arr.size()) return;

        (*root)->data = arr[i];
        i++;
        import_preorder(&(*root)->left);
        import_preorder(&(*root)->right);

    }
    /*
    void printInorder(Node *root){
        if (root==NULL) return;
        printInorder(root->left);
        cout<<root->data<<"   ";
        printInorder(root->right);
    }
    */

    void bst_to_minheap(Node*root){
        export_data_inorder(root);
        import_preorder(&root);
        //cout<<endl<<"--------------------------\n";
        //printInorder(root);
    }

};




int main(){
    Node*root = new Node(30);
    root->left = new Node(19);
    root->right = new Node(40);
    root->left->left = new Node(10);
    root->left->right = new Node(22);
    root->right->left = new Node(35);
    root->right->right = new Node(45);

    Solution sol;
    sol.bst_to_minheap(root);


    return 0;



}
