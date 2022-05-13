// gfg
// Buy Maximum Stocks if i stocks can be bought on i-th day 
// https://practice.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1/

/*

In a stock market, there is a product with its infinite stocks. The stock prices are given for N days, where price[i] denotes the price of the stock on the ith day.
There is a rule that a customer can buy at most i stock on the ith day.
If the customer has an amount of k amount of money initially. The task is to find out the maximum number of stocks a customer can buy. 

Example 1:
Input:
price[] = { 10, 7, 19 }
k = 45
Output: 4
Explanation: A customer purchases 1 stock on day 1, 
2 stocks on day 2 and 1 stock on day 3 for 
10, 7 * 2 = 14 and 19 respectively. Hence, 
total amount is 10 + 14 + 19 = 43 and number 
of stocks purchased is 4.

Example 2:
Input: 
price[] = { 7, 10, 4 }
k = 100
Output: 6

Your Task:  
You don't need to read input or print anything. Your task is to complete the function buyMaximumProducts() which takes an array price and an integer k and returns an integer as output.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(1)

*/
// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int, int>>arr;
        for (int i=0;i<n;i++){
            arr.push_back({price[i],i+1});
        }
        sort(arr.begin(),arr.end());
        int count =0;
        for (int i=0;i<n;i++){
            while(k>=arr[i].first && arr[i].second>0){
                count++;
                k-=arr[i].first;
                arr[i].second --;
            }
            if (k<arr[i].first)
                break;
        }
        return count;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends
