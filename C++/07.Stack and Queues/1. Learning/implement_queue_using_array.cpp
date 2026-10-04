/*
Question:
Implement a Queue using an Array. Queries in the Queue are of the following type:
(i) 1 x   (a query of this type means pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop an element from the queue and print the popped element)

Approach:
- We use a class `MyQueue` to represent the queue.
- The queue is implemented using an array `arr`, a front variable to keep track of the front element, and a rear variable to keep track of the next available position to insert an element.
- The class provides two member functions: `push(int)` to push an element into the queue and `pop()` to pop an element from the front of the queue.
- The `push(int)` function inserts the element at the rear index and increments the rear.
- The `pop()` function checks if the queue is empty (rear == front), in which case it returns -1. Otherwise, it retrieves the element at the front index, increments the front, and returns the element.

Code:
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Queue
{
    public:
    int n = 1000;
    int start = -1;
    int end = -1;
    int arr[1000];

    void push(int x)
    {
        if((end + 1) % n == start)
        {
            cout<<"Stack overflow \n";
            return;
        }

        if(start == -1)
        {
            start = end = 0;
            arr[end] = x;  
            return;          
        }
        
        end = (end + 1) % n;
        arr[end] = x;
    }

    void pop()
    {
        if(start == end)
        {
            cout<<arr[start];
            start = end = -1;
        }

        int val = arr[start];
        start = (start + 1) % n;
        cout<<val<<endl;
    }

    void top()
    {
        if(start == -1)
        {
            cout<<"Queue empty \n";
            return;
        }
        cout<<arr[start]<<endl;
    }

    int size()
    {
        if(start == -1) return 0;
        if(end >= start) return end-start+1;
        return n-start+end+1;
    }
};

int main()
{
    Queue q;

    q.push(26);
    q.push(13);
    q.push(6);
    q.pop();
    q.top();
    cout<<q.size();

    return 0;
}

/*
Complexity Analysis:
- The time complexity of both `push()` and `pop()` operations is O(1) since they involve constant-time operations like accessing/modifying array elements and incrementing/decrementing front/rear indices.
- The space complexity is O(N) where N is the maximum number of elements that can be stored in the queue (in this case, 100005) since we use an array to store the queue elements.
*/

