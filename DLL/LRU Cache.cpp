//gfg
// LRU Cache
// https://practice.geeksforgeeks.org/problems/lru-cache/1/?page=1&category[]=doubly-linked-list&curated[]=1&sortBy=submissions#

/*
Got error in input
    4
    87
    SET 94 16 SET 93 87 SET 63 22 SET 60 91 SET 41 27 GET 73 GET 12 GET 68 SET 31 83 GET 24 SET 30 36 GET 23 GET 70 SET 57 94 SET 30 43 SET 20 22 GET 38 GET 25 SET 14 71 GET 92 GET 57 SET 71 63 GET 82 SET 85 26 SET 6 37 GET 30 SET 25 58 SET 46 83 GET 68 GET 65 SET 88 51 GET 77 GET 89 GET 4 SET 100 55 GET 61 GET 69 SET 27 13 GET 95 SET 71 96 GET 79 SET 98 2 GET 18 GET 53 GET 2 GET 87 SET 90 66 GET 20 GET 30 SET 98 18 SET 76 82 SET 68 28 GET 98 SET 66 87 GET 84 SET 29 25 SET 30 33 SET 71 20 GET 9 SET 50 41 GET 24 GET 46 GET 52 SET 80 56 GET 65 GET 42 GET 94 GET 35 GET 25 GET 88 GET 44 SET 66 28 SET 33 37 SET 29 38 SET 75 8 SET 96 59 SET 36 38 SET 29 19 SET 29 12 SET 5 77 SET 14 64 GET 7 GET 5 GET 29 GET 70 SET 97 18 GET 44
*/// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class Node{
public:
    int data[2];
    Node* next=NULL;
    Node*prev=NULL;
    Node (int key , int val){
        data[0]=key;
        data[1]=val;
    }

};


class LRUCache
{
private:

    Node* head = NULL;
    int capacity;
    Node* temp = NULL;
    int len=0;

public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity = cap;
        head = NULL;
        len =0;
        temp=head;
    }

    Node *findkey (int key){
        cout<<"\n -- find call ----  :   ";
        Node * fk = head;
        while(fk){
             cout<<"    "<<fk->data[0]<<" : "<<fk->data[1];
            if(fk->data[0]==key){
                cout<<"   return  "<<fk->data[0]<<" : "<<fk->data[1]<<endl;
                return fk;
            }
            fk = fk->next;
        }
        cout<<endl;
        return fk;
    }

    //Function to return value corresponding to the key.
    int get(int key)
    {
        
        Node * cur = findkey(key);
        if (cur==NULL)
            return -1;
        return cur->data[1];
    }

    //Function for storing key-value pair.
    void set(int key, int value)
    {
        Node * curr =findkey(key);
        if (!head){
            head = new Node(key,value);
            len = 1;
            temp = head;
        }
        else if(curr!=NULL){
            if (curr==head){
                head=head->next;
            }
            else if(curr->next==NULL){
                curr->prev->next=NULL;
                curr->next=NULL
            }
            else{
                curr->prev->next=curr->next;
                curr->next->prev=curr->prev;
                
            }
            
            temp->next = new Node(key, value);
            temp->next->prev= temp;
            temp=temp->next;
            
            
        }
        else if (len < capacity){
            temp->next = new Node(key, value);
            temp->next->prev= temp;
            len++;
            temp=temp->next;
        }
        else if(len==capacity){
            head=head->next;
            head->prev=NULL;
            temp->next=new Node(key,value);
            temp->next->prev=temp;
            temp=temp->next;
        }
    }
};

/*
class Node{
    public:
    
    int data;
    int next=NULL;
    Node(int val){
        data=val;
    }
};

class LRUCache
{
    private:
    
    Node dll;
    Node *head = dll;
    

    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here   
    }
};*/

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
