/*
Left View of Binary Tree
https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.
Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:
Input:
   1
 /  \
3    2
Output: 1 3

Your Task: You just have to complete the function leftView() that returns an array containing the nodes that are in the left view. The newline is automatically appended by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
  */

// method 1 -------------------------------------------------------------using recursion

void leftviews(Node* node, vector<int>& ans, int level){
    if (node== NULL)return;
    if (level==ans.size()){
        ans.push_back(node->data);
    }
    leftviews(node->left,ans,level+1);
    leftviews(node->right,ans,level+1);
}

vector<int> leftView(Node *node)
{
   // Your code here
    vector <int> ans;
    leftviews(node, ans, 0);
      return ans;
}


// method 2 --------------------------------------------using BFS------300 test cases pass

vector<int> leftView(Node *node)
{
   // Your code here
   vector<int>ans;
    queue<Node*>q;
    q.push(node);
    q.push(NULL);
    ans.push_back(node->data);
    bool flag =0;
       
    while(!q.empty()){
        
        
        Node * temp = q.front();
        q.pop();
        
        if (temp!=NULL){
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
            if (flag ==1){
                ans.push_back(temp->data);
                flag=0;
            }
            
            
        }
        
        else if(!q.empty()){
            q.push(NULL);
        
        }
        if (temp == NULL){
            flag =1;
        }
        
        
    }
       

      return ans;
}
