/*
Question:
Implement a Stack using one queue.

Approach:
- We use the class `QueueStack` to represent the stack.
- The stack is implemented using one queue `q`.
- The `push(int)` function inserts an element into `q`.
- The `pop()` function transfers `n-1` elements from front of `q` to it's back and returns the last element from `q` as the popped element.

Code:
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;

class Stack
{
    public:
    queue<int> q;

    void push(int x)
    {
        int n = q.size();
        q.push(x);
        for(int i=0; i<n; ++i)
        {
            q.push(q.front());
            q.pop();
        }
        cout<<q.front()<<endl;
    }

    void pop()
    {
        int n = q.size();
        int val = q.front();
        q.pop();
        cout<<val<<endl;
    }

    void top()
    {
        cout<<q.front()<<endl;
    }

    void size()
    {
        cout<<q.size()<<endl;
    }
};

int main()
{
    Stack st;

    st.push(23);
    st.push(21);
    st.push(35);
    st.push(13);
    st.pop();
    st.top();
    st.pop();
    st.size();

    return 0;
}

/*
Complexity Analysis:
- The `push()` operation has a time complexity of O(1) since we only need to enqueue an element into `q`.
- The `pop()` operation has a time complexity of O(N) in the worst case, where N is the number of elements in `q`.
- The space complexity is O(N), where N is the total number of elements stored in the queue.
*/

