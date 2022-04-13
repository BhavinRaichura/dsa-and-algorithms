// gfg
// Roman Number to Integer


/*

Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:
Input: s = V
Output: 5

Example 2:
Input: s = III 
Output: 3

Your Task:
Complete the function romanToDecimal() which takes a string as input parameter and returns the equivalent decimal number. 

Expected Time Complexity: O(|S|), |S| = length of string S.
Expected Auxiliary Space: O(1)

Constraints:
1<=roman no range<=3999

*/


class Solution {
  public:
    int romanToDecimal(string &s){
    map<char,int>vals;

    vals.insert({'I',1});
    vals.insert({'V',5});
    vals.insert({'X',10});
    vals.insert({'L',50});
    vals.insert({'C',100});
    vals.insert({'D',500});
    vals.insert({'M',1000});

    int ans =vals[s[0]];

    for(int i=1;i<s.size();i++)
    {
        if(vals[s[i]]<=vals[s[i-1]]){
            ans +=vals[s[i]];
        }
        else if(vals[s[i]]>vals[s[i-1]]){
            ans=ans+vals[s[i]]-2*vals[s[i-1]];
         
        }

    }
    return ans;
}
};

