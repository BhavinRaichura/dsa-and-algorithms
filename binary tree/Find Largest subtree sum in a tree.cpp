// Find Largest subtree sum in a tree
// post order traversal

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
