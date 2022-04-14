// Row with max 1s 
// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#
// implementation :  https://www.geeksforgeeks.org/find-the-row-with-maximum-number-1s/


/*
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:
    Input: 
    N = 4 , M = 4
    Arr[][] = {{0, 1, 1, 1},
               {0, 0, 1, 1},
               {1, 1, 1, 1},
               {0, 0, 0, 0}}
    Output: 2
    Explanation: Row 2 contains 4 1's (0-based indexing).

Your Task:  
You don't need to read input or print anything. Your task is to complete the function rowWithMax1s() which takes the array of booleans arr[][], n and m as input parameters and returns the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N, M ≤ 103
0 ≤ Arr[i][j] ≤ 1 
*/


// implementation :  https://www.geeksforgeeks.org/find-the-row-with-maximum-number-1s/
//--------------------------------can implementation using binary search with (n log m)-------------------------------------------------------


//-----------------------------------------------------------------------n*m complexity---------------------
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int countOne;
	    int maxi=-1;
	    int index=-1;
	    for(int i =0;i<n;i++){
	        countOne=std::count(arr[i].begin(), arr[i].end(),1);
	        if(countOne>maxi){
	            maxi=countOne;
	            index=i;
	        }
	    }
	    if(maxi==0){
	        return -1;
	    }
	    return index;
	}

};

// ----------------------------------------------------------implimentation--------------------------------------------------------------------

/*
Following method works in O(m+n) time complexity in worst case. 
Step1: Get the index of first (or leftmost) 1 in the first row.
Step2: Do following for every row after the first row 
…IF the element on left of previous leftmost 1 is 0, ignore this row. 
…ELSE Move left until a 0 is found. Update the leftmost index to this index and max_row_index to be the current row.
The time complexity is O(m+n) because we can possibly go as far left as we came ahead in the first step.

Following is the implementation of this method.
*/

#define R 4
#define C 4
// The main function that returns index of row with maximum
// number of 1s.
int rowWithMax1s(bool mat[R][C])
{
    // Initialize first row as row with max 1s
    int j,max_row_index = 0;
    j = C - 1;
 
    for (int i = 0; i < R; i++) {
        // Move left until a 0 is found
      bool flag=false; //to check whether a row has more 1's than previous
        while (j >= 0 && mat[i][j] == 1) {
            j = j - 1; // Update the index of leftmost 1
                       // seen so far
          flag=true ;//present row has more 1's than previous
          }
      // if the present row has more 1's than previous
      if(flag){
            max_row_index = i; // Update max_row_index
        }
    }
      if(max_row_index==0&&mat[0][C-1]==0)
            return -1;
    return max_row_index;
}








//------------------------------main fn()------------
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
