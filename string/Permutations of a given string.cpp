// Permutations of a given string
// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1#

/*
Given a string S. The task is to print all permutations of a given string in lexicographically sorted order.

Example 1:
    Input: ABC
    Output:
    ABC ACB BAC BCA CAB CBA
    Explanation:
        Given string ABC has permutations in 6 
        forms as ABC, ACB, BAC, BCA, CAB and CBA .

Your Task:  You don't need to read input or print anything. Your task is to complete the function find_permutaion() which takes the string S as input parameter and returns a vector of string in lexicographical order.

Expected Time Complexity: O(n! * n)
Expected Space Complexity: O(n)
*/


// method : using next_permutation

class Solution
{
	public:
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    vector <string> permute;
		    sort(s.begin(),s.end());
		    permute.push_back(s);
		    while(next_permutation(s.begin(),s.end())){
		        permute.push_back(s);
		    }
		    return permute;
		}
};
