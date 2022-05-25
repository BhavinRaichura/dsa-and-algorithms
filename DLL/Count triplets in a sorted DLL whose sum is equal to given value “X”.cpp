// Count triplets in a sorted DLL whose sum is equal to given value “X”.


#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node * prev=NULL;
    Node * next=NULL;
    Node(int x){
        data= x;
    }
};

Node* insertNode(Node * head, int val){
    Node * temp = new Node(val);
    if (head==NULL) {
        head= temp;
        return head;
    }
    temp ->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

void printNode(Node* head){
    Node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
}

int findTripleets(Node* head, int val){
    Node* i=head;
    Node* j;
    Node * k=head;
    Node* last= head;

    int count =0,n=1;
    vector<vector<int>>arr;

    while(last->next!=NULL){
        last=last->next;
        n++;
    }

    for ( int p = 0; p<=n-3; p++){
        if(i->next == k) break;
        j=i->next;
        while(j->data<k->data){
            int sumof = i->data + j->data + k->data;

            if(sumof == val){
                arr.push_back({i->data, j->data, k->data});
                count++;
                break;
            }
            else if(sumof>val) k=k->prev;
            else if(sumof<val) j=j->next;
        }
        k= last;
        i=i->next;
    }

    return count;


}

int main()
{

    Node* head = NULL;

    head = insertNode(head,9);
    head = insertNode(head,8);
    head = insertNode(head,6);
    head = insertNode(head,5);
    head = insertNode(head,4);
    head = insertNode(head,2);
    head = insertNode(head,1);
  
    cout<<findTripleets(head,17);


    return 0;
}
