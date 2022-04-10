// leetcode
// problem No.: 46. Permutations
// https://leetcode.com/problems/permutations/

/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]
 

Constraints:
    1 <= nums.length <= 6
    -10 <= nums[i] <= 10
    All the integers of nums are unique.

*/


vector<vector<int>> permute(vector<int>& nums) {
    vector< vector <int > >permutations;
    vector < int > arr(nums.begin(),nums.end());
    sort(arr.begin(),arr.end());
    permutations.push_back(arr);
    while(next_permutation(arr.begin(),arr.end()))
        permutations.push_back(arr);
    return permutations;
}


// we can get permutation one by one here are two methods presented in STL to find permutations
// std::next_permutation 
// std::prev_permutation

// https://www.geeksforgeeks.org/stdnext_permutation-prev_permutation-c/

int main(){
    vector <int >arr;
    int n=5;
    int val;
    for (int i=0; i<n;i++) {
        cin >> val;
        arr.push_back(val);
    }
    cout<<"\n--------------------------------------\n";
    for (int i = 0; i<n;i++)
        cout<<arr[i]<<"  ";
    cout<<"\n---------------after permuttion-----------------------\n";
    vector <vector <int >>a =permute(arr);

    cout<<"\nsize of permutation "<<a.size();
    for (int i = 0; i<a.size();i++) {
        cout<<endl;
        for (int j = 0; j < n; j++) {
            cout<<a[i][j]<<"  ";
        }

    }
}
