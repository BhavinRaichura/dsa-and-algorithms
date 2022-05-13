// gfg
// Intersection Point in Y Shapped Linked Lists 
// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

/*

Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

 

Example 1:
Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
Explanation:
Y ShapedLinked List

Example 2:
Input: 
Linked List 1 = 4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation: 

Your Task:
You don't need to read input or print anything. The task is to complete the function intersetPoint() which takes the pointer to the head of linklist1(head1) and linklist2(head2) as input parameters and returns data value of a node where two linked lists intersect. If linked list do not merge at any point, then it should return -1.
Challenge : Try to solve the problem without using any extra space.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)
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
