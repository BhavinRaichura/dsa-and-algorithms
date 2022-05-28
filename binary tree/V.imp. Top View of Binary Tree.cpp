Top View of Binary Tree 
https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
/*
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:
Input:
      1
   /    \
  2      3
Output: 2 1 3

Example 2:
Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100

Your Task:
Since this is a function problem. You don't have to take input. Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).
*/
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public: 
    
    vector<int> topView(Node *root)
    {
        // storage of ans
        vector<int>ans;
        // for BFS or level order traversal
        queue<pair<int,Node*>>q;
        // for stroring < horizontal_distacne : Node's data >
        map<int,int>mp;
        
        pair<int, Node*>curr;
        int hd =0;
        
        
        q.push({hd,root});
        
        while (!q.empty()){
            
            // for level order traversal BFS
            curr = q.front();
            hd= curr.first;
            q.pop();
            
            // if horizontal distance is already present or not
            // if hd is not present then 1st value of all hd is set with node's data
            if(mp.find(hd)==mp.end() ){
                mp[curr.first]=curr.second->data;
            }
            
            // check if left child is present or not
            if(curr.second->left!=NULL){
                q.push({hd-1,curr.second->left});
            }
            
            // check the excistance of right child
            if(curr.second->right!=NULL){
                q.push({hd+1,curr.second->right});
            }
            
        }
        
        for(auto i : mp){
            ans.push_back(i.second);
        }
        
        return ans;
        
        
    }

};
