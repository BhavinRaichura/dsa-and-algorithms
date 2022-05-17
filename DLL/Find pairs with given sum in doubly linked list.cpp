/*
Find pairs with given sum in doubly linked list

https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/

Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value x, without using any extra space? 

Example:  
Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
        x = 7
Output: (6, 1), (5,2)

The expected time complexity is O(n) and auxiliary space is O(1).
*/
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node * prev = NULL;
    Node * next = NULL;
    Node(int val) {
        data = val;
    }
};

void find_pairs(Node* head, vector <pair<int, int>> &arr, int x){
    Node * high = head;
    while(high->next!= NULL)
        high = high->next;
    Node * low = head;

    while(low->data<=high->data){
        if ( x == low->data + high->data){
            arr.push_back({low->data,high->data});
            high = high->prev;
        }
        else if ( x > low->data + high->data){
            low = low ->next;
        }
        else if ( (low->data + high->data ) > x  )
            high= high->prev;
    }
}

int main(){
    Node* head = new Node(1);
    Node* temp = head;

    temp ->next = new Node(2);
    temp ->next->prev = temp;
    temp = temp ->next;

    temp ->next = new Node(4);
    temp ->next->prev = temp;
    temp = temp ->next;

    temp ->next = new Node(5);
    temp ->next->prev = temp;
    temp = temp ->next;

    temp ->next = new Node(6);
    temp ->next->prev = temp;
    temp = temp ->next;

    temp ->next = new Node(8);
    temp ->next->prev = temp;
    temp = temp ->next;

    temp ->next = new Node(9);
    temp ->next->prev = temp;
    temp = temp ->next;

    vector<pair<int, int>>arr;
    int x = 7;
  
    find_pairs(head, arr, x);

    for (int i = 0; i<arr.size();i++){
        cout<<arr[i].first<<"  "<<arr[i].second<<endl;
    }
    return 0;


}

