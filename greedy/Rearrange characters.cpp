Rearrange characters
https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1/
/*
Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same.
Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.

Example 1:
Input : str = "geeksforgeeks"
Output: 1
Explanation: All the repeated characters of the given string can be rearranged so that no  adjacent characters in the string is equal. Any correct rearrangement will show a output of 1.

Example 2:
Input : str = "bbbbb"
Output: 0
Explanation: Repeated characters in the string cannot be rearranged such that there should not be any adjacent repeated character.

Your task :
You don't have to read input or print anything. Your task is to complete the functionrearrangeString() which takes the string as input and returns the modified string. If the string cannot be modified return "-1".
Note:The generatedoutput is 1 if the string is successfully rearranged and is 0 if rearranging is not possible.
 
Expected Time Complexity : O(NlogN), N = length of String
Expected Auxiliary Space : O(number of english alphabets)
 */

#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;


class Solution
{
    public:
    string rearrangeString(string str)
    {
        
        unordered_map<char,int>mp;
        for(int i=0;i<str.size();i++){
            mp[str[i]]++;
        }
        
        priority_queue<pair<int,char>>heap;
        for(auto i : mp){
            heap.push({i.second,i.first});
        }
        
        str="";
        
        while(heap.size()>1){
            auto s1 = heap.top();
            heap.pop();
            auto s2 = heap.top();
            heap.pop();
            str += s1.second;
            str += s2.second;
            
            s1.first--;
            s2.first--;
            
            if(s1.first>0){
                heap.push(s1);                
            }
            if(s2.first>0){
                heap.push(s2);
            }
            
        }
        
        if(heap.size()){
            if(heap.top().first == 1)
                str += heap.top().second;
            else
                return "-1";
        }
        
        return str;
        
        
        
    }
    
};








// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}  // } Driver Code Ends
