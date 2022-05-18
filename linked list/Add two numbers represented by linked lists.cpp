/*

gfg
Add two numbers represented by linked lists 
https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.
The sum list is a linked list representation of the addition of two input numbers from the last.

Example 1:
Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).

Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M)) for the resultant list.
  */

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node*newhead =NULL;
    int n=0,m=0;
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        stack<int>st1;
        stack<int>st2;
        
        Node* temp;
        
        temp = first;
        while(temp){
            st1.push(temp->data);
            temp = temp->next;
        }
        
        temp = second;
        while(temp){
            st2.push(temp->data);
            temp = temp->next;
        }
        
        int s= 0;
        Node * ans;
        ans=NULL;
        int carry =0;
        
        while(!st1.empty() || !st2.empty() || carry){
            s=0;
            if (!st1.empty()){
                s+=st1.top();
                st1.pop();
            }
            if (!st2.empty()){
                s+= st2.top();
                st2.pop();
            }
            s+= carry;
            temp = new Node(s%10);
            temp ->next = ans;
            ans= temp;
            carry= s/10;
        }
        
        return ans;
    }
};
