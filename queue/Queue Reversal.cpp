Queue Reversal
https://practice.geeksforgeeks.org/problems/queue-reversal/1
/*
Given a Queue Q containing N elements. The task is to reverse the Queue. Your task is to complete the function rev(), that reverses the N elements of the queue.

Example 1:
Input:
6
4 3 1 10 2 6
Output: 6 2 10 1 3 4
Explanation: After reversing the given elements of the queue , the resultant queue will be 6 2 10 1 3 4.

Example 2:
Input:
4
4 3 2 1 
Output: 1 2 3 4
Explanation: After reversing the given elements of the queue , the resultant queue will be 1 2 3 4.

Your Task: You only need to complete the function rev that takes a queue as parameter and returns the reversed queue. The printing is done automatically by the driver code.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)
  */
  
void reverse (queue<int>& q){
    if(q.empty()){
      return;  
    } 
    int k = q.front();
    q.pop();
    reverse(q);
    q.push(k);
}
queue<int> rev(queue<int> q)
{
    
    //code here
    reverse(q);
    return q;

}
