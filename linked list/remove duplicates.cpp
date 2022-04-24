// gfg

// Remove duplicate element from sorted Linked List 
// https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1#


void removeDuplicates(struct Node* head)
{
    struct Node *temp;
    temp = head;
    struct Node *nextNode;
    while(temp->next!=NULL){
        if(temp->data==temp->next->data){
            nextNode = temp->next->next;
            temp->next=nextNode;
        }
        else{
            temp = temp->next;
        }
    }
    
}


// Remove duplicates from an unsorted linked list 
// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     unordered_set<int>sets;
     Node *temp,*prev;
     temp = head->next;
     prev= head;
     sets.insert(prev->data);
     
     while(temp!=NULL){
         if(sets.find(temp->data)== sets.end()){
            sets.insert(temp->data);
            temp = temp->next;
            prev = prev->next;
         }
         else{
             temp=temp->next;
             prev->next=temp;
             
         }
         
     }
     
     return head;
    }
};
