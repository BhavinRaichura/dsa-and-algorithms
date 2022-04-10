//GFG
// Palindrome String

/*
Given a string S, check if it is palindrome or not.

Example 1:
Input: S = "abba"
Output: 1
Explanation: S is a palindrome

Your Task:
You don't need to read input or print anything. Complete the function isPlaindrome()which accepts string S and returns an integervalue 1 or 0.

Expected Time Complexity: O(Length of S)
Expected Auxiliary Space: O(1)

Constraints:
1 <= Length of S<= 105
*/


class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes 
    // Your code goes here
    int l=0;
    int r=S.size()-1;
    while(l<r){
       
        if (S[l]!=S[r])
            return 0;
        l++;
        r--;
    }
    return 1;
}
	

};

