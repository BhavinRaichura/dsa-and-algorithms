// leetcode
// https://leetcode.com/problems/valid-palindrome/

/*

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
    Input: s = "race a car"
    Output: false
    Explanation: "raceacar" is not a palindrome.

Example 3:
    Input: s = " "
    Output: true
    Explanation: s is an empty string "" after removing non-alphanumeric characters.
    Since an empty string reads the same forward and backward, it is a palindrome.

Constraints:
    1 <= s.length <= 2 * 105
    s consists only of printable ASCII characters.

*/

class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        char c;
        
        for (int i=0;i<s.size();i++){
            if (s[i]>=65 && s[i]<=90){
                c= s[i]-'A';
                c+='a';
                str+=c;
            }
            else if (s[i]>=97 && s[i]<=122){
                str+=s[i];
            }
            else if (s[i]>=48 && s[i]<=57){
                c= s[i]-'0';
                c+='0';
                str+=c;
            }
            
        }
        int r=str.size()-1;
        int i=0;
        cout<<str;
        while(i<r){
            if (str[i]!= str[r]){
                return false;
            }
            i++;
            r--;
        }
        return true;
    }
};
