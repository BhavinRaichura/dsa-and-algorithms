// Find Largest subtree sum in a tree
// post order traversal
/*
Given a binary tree, task is to find subtree with maximum sum in tree.
Examples: 
Input :       1
            /   \
           2      3
          / \    / \
         4   5  6   7
Output : 28
As all the tree elements are positive, the largest subtree sum is equal to sum of all tree elements.

Input :       1
            /    \
          -2      3
          / \    /  \
         4   5  -6   2
Output : 7
Subtree with largest sum is :  -2
                             /  \ 
                            4    5
Also, entire tree sum is also 7.
*/
class Solution {
    int maxi = INT_MIN;
public:

    int potOrderNode*root){
      // post order traversal
        if (root == NULL)
            return 0;

        int leftMax = largestSum(root->left);
        int rightMax = largestSum(root->right);
        int sum = leftMax + rightMax + root->data;

        maxi = max(maxi,sum);
        return sum;
    }
    
    int largestSum(Node*root){
        largestSum(root);
        return maxi;
    }

};
