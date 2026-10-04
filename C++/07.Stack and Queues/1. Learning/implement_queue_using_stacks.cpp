/*
Question:
Implement a Queue using two stacks s1 and s2.

Approach:
- We use the class `Queue` to represent the queue.
- The queue is implemented using two stacks `input` and `output`.
- The `enqueue(int)` function inserts an element into `input` stack.
- The `dequeue()` function transfers elements from `input` stack to `output` stack if `output` is empty, and returns the top element from `output` stack as the dequeued element.
- To transfer elements from `input` to `output`, we pop each element from the top of `input` and push it into `output`.
- After transferring elements, we pop the top element from `output` as the dequeued element.

Code:
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Queue
{
    public:
    stack<int> s1, s2;

    void push(int x)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop()
    {
        s1.pop();
    }

    void top()
    {
        s1.top();
    }

    void size()
    {
        s1.size();
    }
};

class QueueOptimized
{
    public:
    stack<int> s1, s2;

    void push(int x)
    {
        s1.push(x);
        cout<<s1.top()<<endl;
    }

    void pop()
    {
        while(!s2.empty())
        {
            s2.pop();
        }

        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        cout<<s2.top()<<endl;
        s2.pop();
    }

    void top()
    {
        while(!s2.empty())
        {
            s2.pop();
        }

        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        cout<<s2.top()<<endl;
    }

    void size()
    {
        cout<<s1.size()<<endl;
    }
};

int main()
{
    Queue q;

    q.push(13);
    q.push(32);
    q.push(31);
    q.push(34);
    q.pop();
    q.pop();
    q.top();
    q.push(12);
    q.top();

    QueueOptimized q2;

    q2.push(13);
    q2.push(32);
    q2.push(31);
    q2.push(34);
    q2.pop();
    q2.pop();
    q2.top();
    q2.push(12);
    q2.top();

    return 0;
}

/*
Complexity Analysis:
- The `enqueue()` operation has a time complexity of O(1) since we only need to push an element into the `input` stack.
- The `dequeue()` operation has a time complexity of O(1) by amortized analysis.
- The space complexity is O(N), where N is the total number of elements stored in the two stacks.
*/

