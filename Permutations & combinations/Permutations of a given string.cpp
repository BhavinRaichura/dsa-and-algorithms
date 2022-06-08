Permutations of a given string
https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1#
/*
Given a string S. The task is to print all permutations of a given string in lexicographically sorted order.

Example 1:
    Input: ABC
    Output: ABC ACB BAC BCA CAB CBA
    Explanation: Given string ABC has permutations in 6  forms as ABC, ACB, BAC, BCA, CAB and CBA .

Example 2:
      Input: ABSG
      Output: ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA
      Explanation: Given string ABSG has 24 permutations.

Your Task:  You don't need to read input or print anything. Your task is to complete the function find_permutaion() which takes the string S as input parameter and returns a vector of string in lexicographical order.

Expected Time Complexity: O(n! * n)
Expected Space Complexity: O(n)

*/

class Solution
{
    vector<string>ans;
    set<string> st;
    string str;
	public:
	    
	    void permutation(int pos, int n){
	        
	        if(pos == n-1 ){
	            st.insert(str);
	            return;
	        }
	        
	        if(pos >= n) return;
	        
	        for(int i=pos;i<n;i++){
	            swap(str[i],str[pos]);
	            permutation(pos+1,n);
	            swap(str[i],str[pos]);
	        }
	        
	        
	    }
	    
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    str =s;
		    permutation(0,s.size());
		    for(auto i:st){
		        ans.push_back(i);
		    }
		    return ans;
		    
		}
};
