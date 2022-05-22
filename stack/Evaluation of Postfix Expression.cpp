// gfg
// Evaluation of Postfix Expression
/*

Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

Example 1:
Input: S = "231*+9-"
Output: -4
Explanation: After solving the given expression,  we have -4 as result.

Example 2:
Input: S = "123+*8-"
Output: -3
Explanation: After solving the given postfix expression, we have -3 as result.

Your Task:
You do not need to read input or print anything. Complete the function evaluatePostfixExpression() that takes the string S denoting the expression as input parameter and returns the evaluated value.

Expected Time Complexity: O(|S|)
Expected Auixilliary Space: O(|S|)

*/

/*
    cout<<'+'-'0'<<"    +: ";
    cout<<'-'-'0'<<"    -: ";
    cout<<'/'-'0'<<"    /: ";
    cout<<'*'-'0'<<"    *: ";
    cout<<'^'-'0'<<"    ^: ";
     
*/
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        // Your code here
        int x=0;
        stack<int>st;
        int a = 0;
        int n = s.size();
        
        for (int i=0; i<n;i++){
            x = s[i] -'0';
            if (x==-5){
                a = st.top();
                st.pop();
                a=st.top()+a;
                st.pop();
                st.push(a);
            }
            else if (x==-3){
                a = st.top();
                st.pop();
                a=st.top()-a;
                st.pop();
                st.push(a);
            }
            else if(x==-1){
                a = st.top();
                st.pop();
                a=st.top()/a;
                st.pop();
                st.push(a);
            }
            else if(x==-6){
                a = st.top();
                st.pop();
                a=st.top()*a;
                st.pop();
                st.push(a);
            }
            else{
                st.push(x);
            }
        }
        return st.top();
    }
};
