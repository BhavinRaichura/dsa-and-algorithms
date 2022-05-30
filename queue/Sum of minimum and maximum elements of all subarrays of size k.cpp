Sum of minimum and maximum elements of all subarrays of size k.
https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

/*

Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.
Examples: 
 
Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
        K = 4
Output : 18
Explanation : Subarrays of size 4 are : 
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4      
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4   
     Sum of all min & max = 6 + 4 + 4 + 4 
                          = 18               

*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int subarrayMinMaxSum(vector<int>arr,int n,int k){

    deque<int>maxfront;
    deque<int>minfront;

    for(int i=0;i<k;i++){
        if(!maxfront.empty() && maxfront.back()<arr[i]){
            while(!maxfront.empty() && maxfront.back()<arr[i]){
                maxfront.pop_back();
            }
            maxfront.push_back(arr[i]);
        }
        if(!minfront.empty() && minfront.back()>arr[i]){
            while(!minfront.empty() && minfront.back()>arr[i]){
                minfront.pop_back();
            }
            minfront.push_back(arr[i]);
        }
        if(minfront.empty()){
            minfront.push_back(arr[i]);
        }
        if(maxfront.empty()) {
            maxfront.push_back(arr[i]);
        }
    }

    int ans= maxfront.front() + minfront.front();

    for(int i=k+1;i<n;i++){

        if(!maxfront.empty() && maxfront.back()<arr[i]){
            while(!maxfront.empty() && maxfront.back()<arr[i]){
                maxfront.pop_back();
            }
            maxfront.push_back(arr[i]);
        }
        if(!minfront.empty() && minfront.back()>arr[i]){
            while(!minfront.empty() && minfront.back()>arr[i]){
                minfront.pop_back();
            }
            minfront.push_back(arr[i]);
        }
        if(minfront.empty()){
            minfront.push_back(arr[i]);
        }
        if(maxfront.empty()) {
            maxfront.push_back(arr[i]);
        }

        ans+= maxfront.front() + minfront.front();

        if(i+1<n && arr[i+1]==maxfront.front()){
            maxfront.pop_front();
        }
        if(i+1<n && arr[i+1]==minfront.front()){
            minfront.pop_front();
        }


    }

    return ans;
}

int main(){
    vector<int>arr;
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(-1);
    arr.push_back(7);
    arr.push_back(-3);
    arr.push_back(-1);
    arr.push_back(2);
    cout<<subarrayMinMaxSum(arr,arr.size(),4);
    return 0;
}
