// gfg
// Intersection Point in Y Shapped Linked Lists 
// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

/*



*/

// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.


int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    
    Node*temp;
    
    // delete all the node one by one 
    // so there will be no nodes in this linked list
    while(head1){
        temp = head1;
        head1=head1->next;
        temp->next=NULL;
    }
    
    // so all the nodes are delete from 1st linked list
    // and only the intersection point node is remains with 2nd linked list 
    temp = head2;
    
    // travels till last node that is the intersection point in this
    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp->data;
}
