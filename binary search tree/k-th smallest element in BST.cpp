k-th smallest element in BST 

/*

Given a BST and an integer K. Find the Kth Smallest element in the BST. 

Example 1:
Input:
      2
    /   \
   1     3
K = 2
Output: 2

Example 2:
Input:
        2
      /  \
     1    3
K = 5
Output: -1

Your Task:
You don't need to read input or print anything. Your task is to complete the function KthSmallestElement() which takes the root of the BST and integer K as inputs and return the Kth smallest element in the BST, if no such element exists return -1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

*/


class Solution {
    
  public:
    // Return the Kth smallest element in the given BST
    void kthElement(Node* root,int k, int &cnt,int &ans){
        if (root == NULL || cnt>= k ) return ;
        
        kthElement(root->left,k,cnt,ans);
        
        cnt++;
        
        if(k== cnt ) {
            ans = root->data;
            return;
        }

        kthElement(root->right,k,cnt,ans);
        
    }
    
    int KthSmallestElement(Node* root, int k) {
        // code here
        int ans = -1;
        int cnt =0;
    
        kthElement(root,k,cnt,ans);
        
        return ans;
    }


};
