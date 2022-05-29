Kth largest element from last in BST 
/*
Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.
  
Example 1:
    Input:
          4
        /   \
       2     9
    k = 2 
Output: 4


Example 2:
    Input:
           9
            \ 
              10
    K = 1
Output: 10

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.

Expected Time Complexity: O(H + K).
Expected Auxiliary Space: O(H)
  
  */
  
//---------------------------------------------------------------methdo 1
// Inorder traversal in reverse order and store all elements in arr if arr.size() == Give size the return it ans = arr[k-1]

class Solution
{
    int cnt =0;
    int ans=0;
    public:
    void check(Node *root,int k){
        if(root ==NULL) return;
        
        check(root->right,k);
        
        if(cnt==k) return;
        
        ans= root->data;
        cnt++;
     
        check(root->left,k);
        
    }
    int kthLargest(Node *root, int k)
    {
        //Your code here
        check(root,k);
        
        return ans;
        
    }
};

// ------------------------------------------ method 2 similor but space is o(n)

class Solution
{
    vector<int>arr;
    public:
    void check(Node *root,int k){
        if(root ==NULL) return;
        
        if(arr.size()==k) return;
        
        check(root->right,k);
        
        arr.push_back(root->data);
        check(root->left,k);
        
    }
    int kthLargest(Node *root, int k)
    {
        //Your code here
        check(root,k);
        
        return arr[k-1];
        
    }
};

