K-th Largest Sum Contiguous Subarray 
/*
You are given an array Arr of size N. You have to find the K-th largest sum of contiguous subarray within the array elements.

Example 1:
Input:
    N = 3
    K = 2
    Arr = {3,2,1}
Output: 5
Explanation: The different subarray sums we can get from the array are = {6,5,3,2,1}. Where 5 is the 2nd largest.

Example 2:
Input:
    N = 4
    K = 3
    Arr = {2,6,4,1}
Output: 11
Explanation: The different subarray sums we can get from the array are = {13,12,11,10,8,6,5,4,2,1}. Where 11 is the 3rd largest.
 
Your Task: You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the array Arr[] and its size N as inputs and returns the Kth largest subarray sum.

Expected Time Complexity: O(N2 * log K)
Expected Auxiliary Space: O(K)
*/

//------------------------------------------------------method 1 (broot force approach)

// store all contiguous subarray sum's value in an max-heap and return the k'th element 
// it required space: 2^k

class Solution{
public:
    int kthLargest(vector<int> &arr,int n,int k){
        priority_queue<int>heap;
        int sum =0;
        for(int i=0;i<n;i++){
            sum =0;
            for(int j=i;j<n;j++){
                sum +=  arr[j];
                heap.push(sum);
            }
        }
        for(int i=0;i<k-1;i++){
            heap.pop();
        }
        return heap.top();
    }
};

//----------------------------------------------------mathod -2 (efficient solution)

// we create a min heap and store only k element
// when min-heap size == k then we check if min-heap's top element is greater then to sum or not 
//  if not then we pop top value of heap and store new value 

// space : o(k)

class Solution{
public:
    int kthLargest(vector<int> &arr,int n,int k){
        priority_queue<int,vector<int>,greater<int>>minHeap;
        int sum =0;
        for(int i=0;i<n;i++){
            sum =0;
            for(int j=i;j<n;j++){
                sum +=  arr[j];
                if(minHeap.size()<k){
                    minHeap.push(sum);
                }
                else if(minHeap.top()<sum){
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
        
        return minHeap.top();
    }
};
