/*
Height of Binary Tree 
https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

Given a binary tree, find its height.

Example 1:
Input:
     1
    /  \
   2    3
Output: 2

Example 2:
Input:
  2
   \
    1
   /
 3
Output: 3   

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/
//-------------------------------------------------------------------------------------------

// method 1 ---------------------- using recurssion

class Solution{
    public:
    int height(Node * root){
            if(root==NULL)
                return 0;
            return max(levels(root->left), levels(root->right))+1;
    }
}

// method 2 ---------------------- BFS ----(level order travelsing method)

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
       //code here
        queue<Node*>q;
        q.push(node);
        q.push(NULL);
        int h=1;
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            if (temp!= NULL){
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            else if(!q.empty()){
                q.push(NULL);
                h++;
            }
        }
        return h;
    }
};
