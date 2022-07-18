// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1?page=1&curated[]=6&sortBy=submissions
//zigzag tree traversa
// using deque data structure

# Deque: it is type of queue data structure where we can perform queue operations from both side.
# from front:  push_back(),  pop_front(), front();
# from back: push_front(), pop_back(),  back();


/*
Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

Example 1:
    Input:
            3
          /   \
         2     1
         
    Output: 3 1 2

Example 2:
    Input:
               7
            /     \
           9       7
         /  \     /   
        8    8   6     
       /  \
      10   9 
      
    Output: 7 7 9 8 8 6 9 10 

Your Task: You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the Zig-Zag Level-Order Traversal of the Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/

/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	deque<Node*>dq;
    	
    	Node*temp = new Node();
    	temp->data = INT_MAX;
    	
    	dq.push_back(root);
    	dq.push_back(temp);
    	
    	vector<int>arr;
    	bool pos=1;
    	
    	
    	while(dq.size()>1){
    	    
    	    if(pos){
    	        
    	        temp = dq.front();
    	        
    	        if(temp->data == INT_MAX){
    	            pos=0;
    	            continue;
    	        }
    	        
    	        dq.pop_front();
    	        
    	        arr.push_back(temp->data);
    	        
    	        if(temp->left){
    	            dq.push_back(temp->left);
    	        }
    	        if(temp->right){
    	            dq.push_back(temp->right);
    	        }
    	        
    	    }
    	    else{
            
    	        temp = dq.back();
    	        
    	        if(temp->data == INT_MAX){
    	            pos=1;
    	            continue;
    	        }
    	        
    	        dq.pop_back();
    	        
    	        arr.push_back(temp->data);
            
    	        if(temp->right){
    	            dq.push_front(temp->right);
    	        }
    	        if(temp->left){
    	            dq.push_front(temp->left);
    	        }
    	        
    	        
    	        
    	    }
    	}
    	return arr;
    	
    }
};
