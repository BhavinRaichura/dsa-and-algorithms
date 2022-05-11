// gfg
// Choose and Swap
// https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1#

/*

You are given a string s of lower case english alphabets. You can choose any two characters in the string and replace all the occurences of the first character with the second character and replace all the occurences of the second character with the first character. Your aim is to find the lexicographically smallest string that can be obtained by doing this operation at most once.

Example 1:
Input:
A = "ccad"
Output: "aacd"
Explanation:
In ccad, we choose a and c and after 
doing the replacement operation once we get, 
aacd and this is the lexicographically
smallest string possible. 

 

Example 2:
Input:
A = "abba"
Output: "abba"
Explanation:
In abba, we can get baab after doing the 
replacement operation once for a and b 
but that is not lexicographically smaller 
than abba. So, the answer is abba. 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function chooseandswap() which takes the string A as input parameters and returns the lexicographically smallest string that is possible after doing the operation at most once.

Expected Time Complexity: O(|A|) length of the string A
Expected Auxiliary Space: O(1)

*/
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        char first;
        char second;
        string q= a;
        sort(q.begin(),q.end());
        int l=0,m=0;

        while(a[l]<=q[m]){

            while(a[l]==q[m]){
                
                m++;
            }

            l++;
            
        }

        if(m>=a.size()){
            return a;
        }
        first =q[m];
        second = a[l];

        for (int i =0; i<a.size();i++){
            if(a[i]==first)
                a[i]=second;
            else if(a[i]==second)
                a[i]=first;
        }
        return a;
    }

};

// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends

