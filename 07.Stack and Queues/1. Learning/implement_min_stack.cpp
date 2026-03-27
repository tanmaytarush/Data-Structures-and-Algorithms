/*
QUESTION:
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class.
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example:
Input:
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
Output:
[null,null,null,null,-3,null,0,-2]
Explanation:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

APPROACH:
- We can use an auxiliary stack to keep track of the difference of an element from the minimum element at each step.
- When pushing an element, we push the difference of an element from the minimum element at that time.
- When popping an element, we check stack top if it's -ve it means that this element is the minimum so we update the mini as we popping the current minimum.
- To get the top element, we add the current minimum to the top element of the main stack.
- To get the minimum element, we simply return the current minimum.

CODE:
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

class StackBF
{
    public:
    stack<pair<int, int>> st;
    
    void push(int x)
    {
        if(st.empty()) 
        {
            st.push({x, x});
            return;
        }

        int mini = min({x, st.top().second});
        st.push({x, mini});
    }

    void pop()
    {
        if(st.empty()) return;
        int element = st.top().first;
        st.pop();
        cout<<element<<endl;
    }

    void top()
    {
        if(st.empty()) return;
        int element = st.top().first;
        cout<<element<<endl;
    }

    void getMin()
    {
        cout<<st.top().second<<endl;
    }
};

class StackOpt
{
    public:
    stack<int> st;
    int mini = INT_MAX;

    void push(int val)
    {
        long long v = val;
        if(st.empty())
        {
            st.push(v);
            mini = v;
        }

        else
        {
            if(val < mini)
            {
                st.push(2*v - mini);
                mini = v;
            }
            else
            {
                st.push(v);
            }
        }
    }

    void pop()
    {
        int newVal = st.top();
        if(st.empty()) return;
        else
        {
            if(st.top() < mini)
            {
                mini = (2*mini - newVal);
                st.pop();
            }
            else
            {
                st.pop();
            }
        }
    }

    void top()
    {
        int newVal = st.top();
        if(st.empty()) return;
        else
        {
            if(newVal < mini)
            {
                cout<<mini<<endl;
            }
            else
            {
                cout<<newVal<<endl;
            }
        }
    }

    void getMin()
    {
        cout<<mini<<endl;
    }
};

int main()
{
    StackBF sbf;
    sbf.push(4);
    sbf.push(23);
    sbf.push(12);
    sbf.push(8);
    sbf.pop();
    sbf.pop();
    sbf.top();
    sbf.push(10);
    sbf.getMin();

    StackOpt spt;
    spt.push(4);
    spt.push(23);
    spt.push(12);
    spt.push(8);
    spt.pop();
    spt.pop();
    spt.top();
    spt.push(10);
    spt.getMin();

    return 0;
}

/*
COMPLEXITY ANALYSIS:
- All the operations (push, pop, top, getMin) have O(1) time complexity as we are performing constant-time operations on the stack.
- The space complexity is O(n) as we use an auxiliary stack to store the minimum elements.
*/
