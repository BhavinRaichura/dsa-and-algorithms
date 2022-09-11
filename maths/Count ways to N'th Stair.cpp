Count ways to N'th Stair(Order does not matter)
https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter5639/1?page=3&status[]=unsolved&category[]=Dynamic%20Programming&sortBy=submissions


/*
There are N stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).

Note: Order does not matter means for n = 4 {1 2 1},{2 1 1},{1 1 2} are considered same.
 
Example 1:
Input: N = 4
Output: 3
Explanation: Three ways to reach at 4th stair. They are {1, 1, 1, 1}, {1, 1, 2}, {2, 2}.

Example 2:

Input: N = 5
Output: 3
Explanation: Three ways to reach at 5th stair. They are {1, 1, 1, 1, 1}, {1, 1, 2, 1} and {1, 2, 2}.

Your Task: You don't need to read or print anyhting. Your task is to complete the function nthStair() which takes N as input parameter and returns the total number of ways to reach at Nth stair.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
  */
  
  
  
class Solution{
	public:
		int nthStair(int n){
		    //  Code here
		    
		    if(n<3)    return n;
		    
		    int ans = (n/2)+1;
		    
		    return ans;
		}
};
