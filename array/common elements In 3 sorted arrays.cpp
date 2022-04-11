// GFG
// Common elements 
//find common elements In 3 sorted arrays
// https://practice.geeksforgeeks.org/problems/common-elements1132/1#

/*
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?

Example 1:
    Input:
        n1 = 6; A = {1, 5, 10, 20, 40, 80}
        n2 = 5; B = {6, 7, 20, 80, 100}
        n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
    Output: 20 80
    Explanation: 20 and 80 are the only
    common elements in A, B and C.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function commonElements() which take the 3 arrays A[], B[], C[] and their respective sizes n1, n2 and n3 as inputs and returns an array containing the common element present in all the 3 arrays in sorted order. 
If there are no such elements return an empty array. In this case the output will be printed as -1.

Expected Time Complexity: O(n1 + n2 + n3)
Expected Auxiliary Space: O(n1 + n2 + n3)

Constraints:
1 <= n1, n2, n3 <= 10^5
The array elements can be both positive or negative integers. 
*/

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
       {
            //for returning vector of elements

           vector <int> common; 
           unordered_map<int,int>table;  
           
            // for each distinct element of A[] we mapped it with 1
            
           for (int i=0;i<n1;i++){
               table[A[i]]=1;
           }

           // for each element in B[] check if that element is already present in table (A[]) or not.
          //  if present then we mapped that element with 2
          
           for (int i=0;i<n2;i++){
               if(table[B[i]]==1){
                   table[B[i]]=2;
               }
           }

        //  now for each element in C[] check if that element is already present in table (A[]) with value of 2 or not.
         //  if present then we remove that element from table so that next time that element will not come and we get unique number
        // and add that element into common vector  
        
           for (int i=0;i<n3;i++){
               if (table[C[i]]==2){
                   table.erase(C[i]);
                   common.push_back(C[i]);
                   
               }
           }
           return common;
       }
