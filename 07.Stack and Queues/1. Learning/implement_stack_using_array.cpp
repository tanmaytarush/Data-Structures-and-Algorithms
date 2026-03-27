/*
Question:
Write a program to implement a Stack using Array. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack.

Approach:
- We use a class `MyStack` to represent the stack.
- The stack is implemented using an array `arr` and a top variable to keep track of the top element.
- The class provides two member functions: `push(int)` to push an element onto the stack and `pop()` to pop an element from the stack.
- The `push(int)` function increments the top and adds the element to the array at the current top index.
- The `pop()` function checks if the stack is empty (top = -1), in which case it returns -1. Otherwise, it retrieves the element at the top index, decrements the top, and returns the element.

Code:
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Stack
{
public:
    int size = 1000;
    int arr[1000];
    int top = -1;

    void push(int x)
    {
        if(top == size - 1)
        {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop()
    {
        if(top == -1)
        {
            cout << "Empty stack\n";
            return -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if(top == -1)
        {
            cout << "No elements\n";
            return -1;
        }
        return arr[top];
    }

    int getSize()
    {
        return top + 1;
    }
};

int main()
{
    Stack st;

    st.push(12);
    st.push(13);
    st.push(5);
    st.push(7);

    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.peek() << endl;
    cout << st.getSize() << endl;

    return 0;
}
/*
Complexity Analysis:
- The time complexity of both `push()` and `pop()` operations is O(1) since they involve constant-time operations like incrementing/decrementing the top and accessing/modifying the array elements.
- The space complexity is O(1) since the array has a fixed size and does not depend on the number of elements pushed into the stack.
*/

