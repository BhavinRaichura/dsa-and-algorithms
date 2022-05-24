Check if all levels of two trees are anagrams or not 
the question has instructed to solve using stack or queue
https://practice.geeksforgeeks.org/problems/check-if-all-levels-of-two-trees-are-anagrams-or-not/1/

//----------------------------------------------------------using recursioon--method 1
class Solution{
    public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        if(root1 == NULL && root2==NULL) return 1;
        else if (root1 != NULL && root2==NULL) return 0;
        else if (root1 == NULL && root2!=NULL) return 0;
        
        if (root1->data != root2->data) return 0;
        
        bool t1 = areAnagrams(root1->left, root2->right);
        bool t2 =areAnagrams(root1->right, root2->left);
        
        if (t1==0 || t2==0) return 0;
        
        return 1;
    }
};
