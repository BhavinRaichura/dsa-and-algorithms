// gfg
// Split a Circular Linked List into two halves
// https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1#

/*
Given a Cirular Linked List of size N, split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.

Example 1:
Input:
Circular LinkedList: 1->5->7
Output: 1 5
        7
        
Example 2:
Input:
Circular LinkedList: 2->6->1->5
Output: 2 6
        1 5

Your Task: Your task is to complete the given function splitList(), which takes 3 input parameters: The address of the head of the linked list, addresses of the head of the first and second halved resultant lists and Set the head1_ref and head2_ref to the first resultant list and second resultant list respectively.

Expected Time Complexity: O(N)
Expected Auxilliary Space: O(1)
*/


/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node*temp=head->next;
    int n=1;
    while(temp!=head){
        n++;
        temp=temp->next;
    }
    int mid= n%2==0 ? n/2 :(n/2)+1;
    Node* h1 = head;
    Node*h2 = head;
    Node*prev;
    temp=head;
    for (int i=0;i<n;i++){
        if (i==mid-1){
            prev = temp;
            temp =temp->next;
            prev->next=head;
            h2 = temp;
        }
        if (temp->next==head){
            temp->next=h2;
        }
        temp=temp->next;
        
    }
    *head1_ref=h1;
    *head2_ref=h2;
    
}
