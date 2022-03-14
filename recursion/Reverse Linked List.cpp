// Reverse Linked List

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:  
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Constraints:

    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000


*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *temp;
        ListNode *prev;
        temp= head;
        if (head==NULL || head->next ==NULL)
            return head;
        
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        prev=temp;
        temp= temp->next;
        prev->next=NULL;
      //recursion call
        temp->next=reverseList(head);
        
        return temp;
    }
    
};
