Longest Palindrome in sub-string
https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1?page=2&status[]=unsolved&curated[]=1&sortBy=submissions
/*
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index).

Example 1:
    Input: S = "aaaabbaa"
    Output: aabbaa
    Explanation: The longest Palindromic substring is "aabbaa".

Example 2:
    Input:  S = "abc"
    Output: a
    Explanation: "a", "b" and "c" are the longest palindromes with same length. The result is the one with the least starting index.

Your Task: You don't need to read input or print anything. Your task is to complete the function longestPalin() which takes the string S as input and returns the longest palindromic substring of S.

Expected Time Complexity: O(|S|2).
Expected Auxiliary Space: O(1).
*/
class Solution {
  public:
  
    string longestPalin (string s1) {
        // code herereturn
        
        string s2= s1, ans;
        
        pair<int,int>common{0,0};
        int cnt =1, maxi =0;

        reverse(s2.begin(),s2.end());
        
        int n = s1.size();
        
        if(s1==s2)return s1;
        
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0 and s2[i]==s1[j]){
                    dp[i][j]=1;
                }
                else if(s2[i]==s1[j]){
                    
                    dp[i][j] = dp[i-1][j-1] + 1;
                    
                }
                
                if(cnt<=dp[i][j] and s1[j]==s1[j-dp[i][j]+1]){
                    cnt = dp[i][j];
                    common.first = i;
                    common.second = j;
                }
            }
        }
        
        for(int i =common.second ,j =0 ;i>common.second-cnt,j<cnt;i--,j++){
            
                ans+=s1[i];
        }
 
        return ans;
    }
};
