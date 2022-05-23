Power Set 
https://practice.geeksforgeeks.org/problems/power-set4302/1/
/*
Given a string S find all possible subsequences of the string in lexicographically-sorted order.

Example 1:
Input : str = "abc"
Output: a ab abc ac b bc c
Explanation : There are 7 subsequences that 
can be formed from abc.

Example 2:
Input: str = "aa"
Output: a a aa
Explanation : There are 3 subsequences that 
can be formed from aa.

Your Task:
You don't need to read ot print anything. Your task is to complete the function AllPossibleStrings() which takes S as input parameter and returns a list of all possible substrings(non-empty) that can be formed from S in lexicographically-sorted order.
 
Expected Time Complexity: O(2n) where n is the length of the string
Expected Space Complexity : O(n * 2n)
*/

//----------------------------------------------------------method :1 using back-tracking

class Solution{
	public:
  
	    void backtracking(string & s, vector<string>&ans, string & subs, int index  ){
	        if (index>0)
	            ans.push_back(subs);
	        for (int i =index; i<s.size();i++){
	            subs+= s[i];
	            
	            backtracking(s,ans,subs,i+1);
	            
	            subs.pop_back();
	        }
	        return;
	    }
  
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans;
		    string subs;
		    backtracking(s,ans,subs,0);
		    
		    sort(ans.begin(),ans.end());
		    
		    return ans;
		    
		}
  
};

//--------------------------------------------------------method:2 using recurssion and bit manipulation

void printPowerSet(string s){
    int n = s.size();
    unsigned int pow_set_size = pow(2,n);
    int cnt , i;
    for (cnt =0 ; cnt<pow_set_size;cnt++){
        for (i=0;i<n;i++){
            if (cnt & 1<<i)
                cout<< s[i];
        }
        cout<<endl;
    }
}
