/*
Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap.
Example 1:
Input :
                 4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  
Output : 1 2 3 4 5 6 7 
Exaplanation :
               7
             /   \
            3     6
          /   \  /   \
         1    2 4     5
The given BST has been transformed into a Max Heap and it's postorder traversal is
1 2 3 4 5 6 7.
Your task : You don't need to read input or print anything. Your task is to complete the function convertToMaxHeapUtil() which takes the root of the tree as input and converts the BST to max heap.
Note : The driver code prints the postorder traversal of the converted BST.
 
Expected Time Complexity : O(n)
Expected Auxiliary Space : O(n)
*/




class Solution{
    vector<int>arr;
    int i=0;
  public:
    void inOrder(Node*root){
        if(root==NULL) return;
        inOrder(root->left);
        arr.push_back(root->data);
        inOrder(root->right);
    }
    void postOrder(Node*root){
        if(root==NULL)return;
        postOrder(root->left);
        postOrder(root->right);
        root->data=arr[i];
        i++;
    }
    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
        inOrder(root);
        postOrder(root);
        
    }    
};
