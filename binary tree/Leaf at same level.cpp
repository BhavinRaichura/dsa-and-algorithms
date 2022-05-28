Leaf at same level 
https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1
/*
Given a Binary Tree, check if all leaves are at same level or not.

Example 1:
Input: 
            1
          /   \
         2     3

Output: 1
Explanation: Leaves 2 and 3 are at same level.

Example 2:
Input:
            10
          /    \
        20      30
       /  \        
     10    15

Output: 0
Explanation: Leaves 10, 15 and 30 are not at same level.

Your Task: 
You dont need to read input or print anything. Complete the function check() which takes root node as input parameter and returns true/false depending on whether all the leaf nodes are at the same level or not.
 
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
*/

// ------------------------------------------------------- method 1 

// traverse for each node with it level if any node doesn't having any child then store their level into mp and continue for other;
// chech wether map has only one element or more

class Solution{
    map<int,int>mp;
  public:
    /*You are required to complete this method*/
    
    void traverse(Node*root,int level){
        
        if(root==NULL) return;
        
        if(root->left==NULL && root->right==NULL){
            mp[level]=1;
        }
        
        traverse(root->left,level+1);
        traverse(root->right,level+1);
        
    }
    
    bool check(Node *root)
    {
        traverse(root,1);
        
        if(mp.size()==1)
            return true;
        return false;
        
    }
};

// ------------------------------------------------method 2 -- brought force approach

// using level order traversal, flag and check if each node in the level has similor kind of child property ( Node has child or not ) or not

class Solution{
  public:
    
    bool check(Node *root)
    {

        bool flag =false;
        int cnt=0;

        queue<Node*>q;
        
        Node*temp;
        
        q.push(root);
        q.push(NULL);
        
        
        while(!q.empty()){
            
            if(q.front() ==NULL){
                q.pop();
                cnt=0;
                flag =false;
                continue;
            }
            
            temp = q.front();
            q.pop();
            cnt++;
            
            if(temp->left ==NULL && temp->right ==NULL){
                if(flag == false){
                    continue;
                }
                return false;
            }
            else if(flag == false && cnt>1 ) return false;
            
            if(temp->left!=NULL){
                q.push(temp->left);
                
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
            flag = 1;
            
            if(q.front()==NULL) q.push(NULL);

            
        }
        return true;
        
    }
};
