// GFG

// First and last occurrences of x

// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1#
/*
Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.
Example 1:
    Input: n=9, x=5
    arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
    Output:  2 5
    Explanation: First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 
      
Example 2:
    Input: n=9, x=7
    arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
    Output:  6 6 

Your Task: Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function find() that takes array arr, integer n and integer x as parameters and returns the required answer.
Note: If the number x is not found in the array just return both index as -1.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1).

  
*/

vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> v;
    long long mid,low,high,flag=0;
    low=0,high=n-1;
   
    while(low<=high)
    {
         mid = low+(high-low)/2;
         if(arr[mid]==x)
         {
             low=high=mid;
             flag=1;
             break;
         }
         else if(arr[mid]>x)
         {
             high=mid-1;
         }
         else
         {
             low=mid+1;
         }
    }
        if(flag==1){
            while(low>=0 && arr[int(low)]==x){
                low--;
            }
            while(high<n && arr[int(high)]==x){
                high++;
            }
            v.push_back(++low);
            v.push_back(--high);
            return v;
        }
        else
        {
            v.push_back(-1);
            v.push_back(-1);
        }
        
}

