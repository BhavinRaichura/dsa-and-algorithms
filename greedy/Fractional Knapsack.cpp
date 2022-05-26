Fractional Knapsack 
https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

//-----------------------------------------------------------------------------------------------------------------------------------------------

-> we need to use a function to sort array according to the ratio of value and weight.
-> because the return type is "double" we needs to calculate everything by converting them to "double" other-wise we dont get right answer.
-> the value get effected with double so it is "--V.Imp.--" to first convert it into double then calculate.

//-----------------------------------------------------------------------------------------------------------------------------------------------

/*
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 
  
Example 1:
Input:
    N = 3, W = 50
    values[] = {60,100,120}
    weight[] = {10,20,30}
Output: 240.00
Explanation:Total maximum value of item we can have is 240.00 from the given capacity of sack. 

Expected Time Complexity : O(NlogN)
Expected Auxilliary Space: O(1)
*/

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n,[](Item i1, Item i2){
          
          // the value get effected with double so it is "--V.Imp.--" to first convert it into double then calculate
            double left =(double)(i1.value)/i1.weight;
            double right =(double)(i2.value)/i2.weight;
            return left>right;
        });
        
        double maxItem=0;
        
        for (int i=0;i<n;i++){
            if(w==0) break;
            if(w>=arr[i].weight){
                w-=arr[i].weight;
                maxItem+= arr[i].value;
            }
            else if(w<arr[i].weight){
                
                maxItem= maxItem + ((arr[i].value)*(double)(w)/(arr[i].weight));
                w=0;
                break;
            }
        }
        return maxItem;
    }
};
