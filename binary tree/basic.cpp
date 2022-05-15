#include <iostream>
using namespace std;

// maximum number of nodes in a level l(0,n) is = 2^n
// maximum number of nodes cn exist in tree of height h(1,h) = 2^h-1
//

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
         data= val;
         left = NULL;
         right = NULL;
     }
};

// travelsing in binary tree

void preOrderTravels(Node *root);
void inOrderTravels(Node *root);
void postOrderTravels(Node *root);

int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root ->right = new Node(3);
    root->left->left = new Node(5);
    root->right->left = new Node(6);
    root->left->right = new Node(7);
    cout<<"\npreOrderTravels\n";
    preOrderTravels(root);
    cout<<"\ninOrderTravels\n";
    inOrderTravels(root);
    cout<<"\npostOrderTravels\n";
    postOrderTravels(root);
    return 0;
}

void preOrderTravels(Node *root){

    if (root == NULL)
        return;
    cout<<root->data<<"    ";
    preOrderTravels(root->left);
    preOrderTravels(root->right);


}
void inOrderTravels(Node *root){

    if (root == NULL)
        return;
    inOrderTravels(root->left);
    cout<<root->data<<"    ";
    inOrderTravels(root->right);


}

void postOrderTravels(Node *root){

    if (root == NULL)
        return;
    postOrderTravels(root->left);
    postOrderTravels(root->right);
    cout<<root->data<<"    ";

}

