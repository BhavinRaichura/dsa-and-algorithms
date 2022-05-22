/*
gfg
Stack using two queues 
https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1
*/
/*
Implement a Stack using two queues q1 and q2.

Example 1:
Input:
push(2)
pop()
pop()
push(3)
Output: 2 -1

Your Task:
Since this is a function problem, you don't need to take inputs. You are required to complete 
the two methods push() which takes an integer 'x' as input denoting the element to be pushed into the stack and pop() 
which returns the integer poped out from the stack(-1 if the stack is empty).

Expected Time Complexity: " --------- O(1) for push()-------  "  and " --------O(N) for pop()----- "  (or vice-versa).

Expected Auxiliary Space: O(1) for both push() and pop().

Constraints:
1 <= Number of queries <= 100
1 <= values of the stack <= 100

*/
///////////////////////////////////////////// --- 2 methods
//////////////////////////////////////////// 1st) - push o(n) and pop o(1)
//////////////////////////////////////////// 2nd) - push o(1) and pop o(n)

// ----------------------------------------------------method 1--------------------------- push o(n) and pop o(1)


void QueueStack :: push(int x)
{
        
        if (q1.empty()){
            q1.push(x);
        }
        else{
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(x);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
        
        
}
int QueueStack :: pop()
{
        x= q1.front();
        q1.pop();
        return x;       
}


// ----------------------------------------------------method 2---------------------------push o(1) and pop o(n)
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
        
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        int x;
        int n = q1.size();
        if (n==0) return -1;
        if(n==1){
            x=q1.front();
            q1.pop();
            return x;
        }
        
        
        for (int i =0;i<n-1;i++){
            q2.push(q1.front());
            q1.pop();
        }
        x= q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return x;
}
