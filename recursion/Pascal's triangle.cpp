
/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Example 3:
Input: rowIndex = 1
Output: [1,1]
*/
  
class Solution {
    
public:
    vector<int> elements;
    
    int data(int i, int j){
        if (i==0 || j==0 || i==j)
            return 1;
        return data(i-1,j-1)+data(i-1,j);
    }
  
    
    vector<int> getRow(int rowIndex) {
        int i =rowIndex;
      
        for(int j=0;j<=i/2;j++)
            elements.push_back(data(i,j));
        
        vector<int>e2;
        e2 = elements;
        reverse(e2.begin(),e2.end());
        
        if (i%2==0)
            elements.pop_back();
      
        elements.insert(elements.end(),e2.begin(),e2.end());
        
        return elements;
        
    }
};
