// leetcode
// 234. palindrome-linked-list

// https://leetcode.com/problems/palindrome-linked-list/

/*
Given the head of a singly linked list, return true if it is a palindrome.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false

Constraints:
    The number of nodes in the list is in the range [1, 105].
    0 <= Node.val <= 9

Follow up: Could you do it in O(n) time and O(1) space?
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



// Approach 1 using extra space ----- Linkedlist.length
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *temp;
        temp = head;
        vector<int> v;
        
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int l=0,r=v.size()-1;
        while(l<r){
            if (v[l]!=v[r])
                return false;
            l++; r--;
        }
        return true;
    }
};


  
