Implement Trie ll
https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?leftPanelTab=0

/*

Problem Statement : Ninja has to implement a data structure ”TRIE” from scratch. Ninja has to complete some functions.
  1) Trie(): Ninja has to initialize the object of this “TRIE” data structure.
  2) insert(“WORD”): Ninja has to insert the string “WORD”  into this “TRIE” data structure.
  3) countWordsEqualTo(“WORD”): Ninja has to return how many times this “WORD” is present in this “TRIE”.
  4) countWordsStartingWith(“PREFIX”): Ninjas have to return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.
  5) erase(“WORD”): Ninja has to delete one occurrence of the string “WORD” from the “TRIE”.

Note:
1. If erase(“WORD”) function is called then it is guaranteed that the “WORD” is present in the “TRIE”.
2. If you are going to use variables with dynamic memory allocation then you need to release the memory associated with them at the end of your solution.

Can you help Ninja implement the "TRIE" data structure?

Input Format:
The first line contains a single integer “T” representing the number of test cases. 
The first line of each test case will contain a single integer “N” which denotes how many times the functions(as discussed above) will be called.
The next “N” lines contain the two space-separated strings, the first one is the name of the function and the second one is a “WORD”.

Output Format:
For each test case, complete all the functions as we discussed above.
The output for every test case will be printed in a separate line.

Note: You do not need to print anything; it has already been taken care of. Just implement the given function.

Constraints:
1 <= “T” <= 50
1 <= “N” <= 10000
 “WORD” = {a to z}
1 <= | “WORD” | <= 1000
Where “T” is the number of test cases, “N” denotes how many times the functions(as discussed above) we call, “WORD” denotes the string on which we have to perform all the operations as we discussed above, and | “WORD” | denotes the length of the string “WORD”.

Sample Input 1:
    1
    5
    insert coding
    insert ninja
    countWordsEqualTo coding
    countWordsStartingWith nin
    erase coding
  Sample Output 1:
      1
      1   


*/

class Node{
    Node *links[26];
    int cntEndWith =0;
    int cntPrefix = 0;

public:
    bool containsKey(char ch){
        return (links[ch-'a']!= NULL);
    }
    void put(char ch, Node*node){
        links[ch-'a']= node;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndWith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }
    int getEnd(){
        return cntEndWith;
    }
    int getPrefix(){
        return cntPrefix;
    }
};

class Trie{
    
    Node *root;
    
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node);
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node= root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node= node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node*node= root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node *node= root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))
                return;
            node = node->get(word[i]);
            node->reducePrefix();
        }
        node->deleteEnd();
    }
};
