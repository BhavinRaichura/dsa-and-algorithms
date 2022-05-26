// ---------------------------------------- total 3 methods

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node * next=NULL;
    Node(int x){
        data= x;
    }
};

void insert(Node **head, int val){
    Node * temp = new Node(val);
    temp ->next = *head;
    *head = temp;
}

void print(Node*head){
    Node *temp = head;
    while(temp!= NULL){
        cout<<temp->data<<"   ";
        temp = temp->next;
    }
}

//------------------------------------------------------method 1 without return Node using iteration

void reverseListIteratively(Node **head){
    if(head==NULL || (*head)->next==NULL)return;
    Node * temp = (*head);
    (*head)=NULL;
    while(temp!=NULL){
        insert(&*head,temp->data);
        temp= temp->next;
    }
}


//------------------------------------------------------method 2 returning Node using iteration
Node * reverseListIteratively2(Node*head){
    if(head==NULL || head->next==NULL ) return head;
    Node *curr = head;
    Node*prev = NULL,*n =NULL;
    while(curr!=NULL){
         n = curr->next;
         curr->next =prev;
         prev =curr;
         curr= n;
    }
    return prev;

}
int main(){

    Node * head = NULL;
    insert(&head,6);
    insert(&head,5);
    insert(&head,4);
    insert(&head,3);
    insert(&head,2);
    insert(&head,1);

    //reverseListRecursively(&head);
    print(head);
    cout<<"\n---------------------------\n";

    Node * head2 = reverseListIteratively2(head);
    print(head2);

    return 0;
}
