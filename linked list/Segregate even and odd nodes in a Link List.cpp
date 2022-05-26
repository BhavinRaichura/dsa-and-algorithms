// Segregate even and odd nodes in a Link List 
// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1
/*
Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.
NOTE: Don't create a new linked list, instead rearrange the provided one.

Example 1:
Input: 
N = 7
Link List:
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL
Output: 8 2 4 6 17 15 9
Explaination: 8,2,4,6 are the even numbers so they appear first and 17,15,9 are odd numbers that appear later.

Explaination: There is no even number. 
So ne need for modification.

Your Task:
You do not need to read input or print anything. Your task is to complete the function divide() which takes N and head of Link List as input parameters and returns the head of modified link list. Don't create a new linked list, instead rearrange the provided one.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(head==NULL|| head->next==NULL)return head;
        Node *pre =head,*even =new Node(0),*temp = head;
        Node *evenNex = even;
        
        while(pre->next!=NULL){
            temp = pre->next;
            
            if(temp->data%2==0){
                pre->next = temp->next;
                evenNex->next = temp ;
                temp->next = NULL;
                evenNex = evenNex->next;
                temp = pre;
                
            }
            pre = temp;
            
        }
    
        even=even->next;
        
        if(even==NULL) return head;
        
        if(head->data%2==0){
            evenNex= head;
            head= head->next;
            evenNex->next = even;
            even = evenNex;
        }
        temp = even;
        
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = head;
        
        return even;
    }
};


