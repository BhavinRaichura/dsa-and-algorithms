/*
Delete nodes having greater value on right 
https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

Given a singly linked list, remove all the nodes which have a greater value on their right side.

Example 1:
Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are the elements which have greater elements on the following nodes. So, after deleting them, the linked list would like be 15, 11, 6, 3.

Example 2:
Input:
LinkedList = 10->20->30->40->50->60
Output: 60

Your Task:
The task is to complete the function compute() which should modify the list as required and return the head of the modified linked list. The printing is done by the driver code,

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
  */

class Solution
{
    public:
    Node *compute(Node *head)
    {
        if(head==NULL || head->next==NULL) return head;
        Node* x = compute(head->next);
        head->data>=x->data ? head->next = x : head= x;
        return head;
        
    }
    
};
   
