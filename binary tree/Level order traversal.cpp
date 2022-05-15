// Level order traversal
// https://practice.geeksforgeeks.org/problems/level-order-traversal/1

/*
Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.

Example 1:
Input :
        1
      /   \
     3     2

Output: 3 2 1
Explanation:
Traversing level 1 : 3 2
Traversing level 0 : 1

Example 2:
Input :
       10
      /  \
     20   30
    / \ 
   40  60

Output: 40 60 20 30 10
Explanation:
Traversing level 2 : 40 60
Traversing level 1 : 20 30
Traversing level 0 : 10


Your Task: 
You dont need to read input or print anything. Complete the function reverseLevelOrder() which takes the root of the tree as input parameter and returns a list containing the reverse level order traversal of the given tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/


class Solution
{
    private:
       
        
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
    vector<int>ans;
    queue<Node*>q;
       q.push(node);
       q.push(NULL);
       
    while(!q.empty()){
       
        Node * node = q.front();
        q.pop();
        
        if(node!=NULL){
            ans.push_back(node->data);
            
            if (node->left){
                q.push(node->left);
            }
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty()){
            q.push(NULL);
        }
       
          
      }
      return ans;
    }
    
};
