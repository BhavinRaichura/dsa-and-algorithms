Diameter of a tree
/*
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 

Example 1:
Input:
       1
     /  \
    2    3
Output: 3

Example 2:
Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4

Your Task:
You need to complete the function diameter() that takes root as parameter and returns the diameter.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
*/
class Solution {
    private:
        int maxNodes = INT_MIN;
    public:
    // Function to return the diameter of a Binary Tree.
    int findMaxDistance(Node*root){
        if(root==NULL) return 0;
        
        int max_left = findMaxDistance(root->left);
        int max_right = findMaxDistance(root->right);
        
        maxNodes = max(maxNodes, max_left+max_right+1 );
        
        return max(max_left,max_right)+1;
    }
    
    int diameter(struct Node* root) {
        // code here
        
        int ans = findMaxDistance(root );
        
        return max(ans,maxNodes);
    }

};
