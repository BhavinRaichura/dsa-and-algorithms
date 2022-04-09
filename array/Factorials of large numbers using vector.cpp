// Factorials of large numbers

// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1#
/*
Given an integer N, find its factorial.

Example 1:
Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120

Example 2:
Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

Your Task:
You don't need to read input or print anything. Complete the function factorial() that takes integer N as input parameter and returns a list of integers denoting the digits that make up the factorial of N.

Expected Time Complexity : O(N2)
Expected Auxilliary Space : O(1)
*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
    
public:
    vector<int> factorial(int n){
    // code here
    vector<int>digits;
    int val;

    for (int i =1;i<=n;i++){
        int j =0;
        int carry = 0;
        if (i==1){
            digits.push_back(1);
            continue;
        }
        while(j<digits.size()){
            val = digits[j]*i + carry;
            digits[j]= val%10;
            carry = val/10;
            j++;
        }

        while(carry!=0){
            digits.push_back(carry%10);
            carry=carry/10;
        }
    }
    reverse(digits.begin(),digits.end());
    return digits;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
