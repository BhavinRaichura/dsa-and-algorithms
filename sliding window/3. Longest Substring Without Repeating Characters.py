### leetcode - 3. Longest Substring Without Repeating Characters

#Given a string s, find the length of the longest substring without repeating characters.

 

## Example 1:
# Input: s = "abcabcbb"
# Output: 3
# Explanation: The answer is "abc", with the length of 3.

## Example 2:
# Input: s = "bbbbb"
# Output: 1
# Explanation: The answer is "b", with the length of 1.


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxlen =0 
        charset =set()
        left=0
        
        for i in range(len(s)):
            while s[i] in charset:
                charset.remove(s[left])
                left+=1
            charset.add(s[i])
            maxlen = max(maxlen,i-left+1)
            
        return maxlen
        
