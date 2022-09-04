/*
Given two strings. The task is to find the length of the longest common substring.

Example 1:
    Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
    Output: 4
    Explanation: The longest common substring is "CDGH" which has length 4.
    


Example 2:
    Input: S1 = "ABC", S2 "ACB", n = 3, m = 3
    Output: 1
    Explanation: The longest common substrings are "A", "B", "C" all having length 1.
    

Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m)
  */
  
  
class Solution{
    public:
  
  
  /*
  
  approach: 
      A B C D G H
    A 1 _ _ _ _ _
    C _ _ 1 _ _ _
    D _ _ _ 2 _ _
    G _ _ _ _ 3 _
    H _ _ _ _ _ 4
    R _ _ _ _ _ _
    
        */
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int maxi =0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                maxi = max(dp[i][j],maxi);
            }
        }
        
        return maxi;
        
    }
};
