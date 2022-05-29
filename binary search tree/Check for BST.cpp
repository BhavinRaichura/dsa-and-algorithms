Check for BST

Properties: 
1. The left subtree of a node contains only nodes with keys less than the node’s key.
2. The right subtree of a node contains only nodes with keys greater than the node’s key.
3. Both the left and right subtrees must also be binary search trees
4. No two nodes data is same.
5. Inorder traversal of BST is give output in assending order


// ---------------------------------------------------------- method 1
// using 5th property

class Solution
{
    
    public:
    //Function to check whether a Binary Tree is BST or not.
    void  check(Node*root, vector<int>&arr){
        if(root ==NULL) return ;
        check(root->left,arr);
        arr.push_back(root->data);
        check(root->right,arr);
    }
    bool isBST(Node* root) 
    {
        // Your code here
        if(root == NULL) return 1;
        
        vector<int>ans;
        
        check(root,ans);
        
        for(int i=1;i<ans.size();i++){
            if(ans[i-1]>ans[i])
                return 0;
        }
        return 1;
        
        
    }
};


// -------------------------------------------------------------- method 2
// using 1st 2nd and 3rd property

int isBST(struct node* node)
{
  if (node == NULL)
    return 1;
     
  /* false if left is > than node */
  if (node->left != NULL && node->left->data > node->data)
    return 0;
     
  /* false if right is < than node */
  if (node->right != NULL && node->right->data < node->data)
    return 0;
   
  /* false if, recursively, the left or right is not a BST */
  if (!isBST(node->left) || !isBST(node->right))
    return 0;
     
  /* passing all that, it's a BST */
  return 1;
}
