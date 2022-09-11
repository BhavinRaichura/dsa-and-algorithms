Longest Palindromic Subsequence
https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1?page=2&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions
/*
Given a String, find the longest palindromic subsequence.

Example 1:
Input: S = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the longest subsequence which is also a palindrome.

Example 2:
Input: S = "abcd"
Output: 1
Explanation: "a", "b", "c" and "d" are palindromic and all have a length 1.
  
Your Task: You don't need to read input or print anything. Your task is to complete the function longestPalinSubseq() which takes the string S as input and returns an integer denoting the length of the longest palindromic subsequence of S.

Expected Time Complexity: O(|S|*|S|).
Expected Auxiliary Space: O(|S|*|S|).
  
  */

class Solution{
  public:
  
    int lcs(string s1, int i1, string s2, int i2,vector<vector<int>>&dp){
        
        if(i1<0 || i2<0) return 0;
        
        if(dp[i1][i2]>0)    return dp[i1][i2];
        
        if(i1==0 and i2==0){
            if(s1[i1]==s2[i2])
                return 1;
            return 0;
        }
        else if(i1==0){
            if(s1[i1]==s2[i2])
                return 1;
            return lcs(s1,i1,s2,i2-1,dp);
        }
        else if(i2==0){
            if(s1[i1]==s2[i2])
                return 1;
            return lcs(s1,i1-1,s2,i2,dp);
        }
    
        if(s1[i1] == s2[i2]){
            
            return dp[i1][i2] = 1 + lcs(s1,i1-1,s2,i2-1,dp);
        }
        
        return dp[i1][i2] = max(lcs(s1,i1-1,s2,i2,dp),lcs(s1,i1,s2,i2-1,dp));
        
    }
    
    int longestPalinSubseq(string A) {
        //code here
        int n =A.size();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        string s2 = A;
        reverse(s2.begin(),s2.end());
        
        
        return dp[n][n] = lcs(A,n-1,s2,n-1,dp);
        
    }
};
