/*
Question:
You have a linked list and you have to implement the functionalities push and pop of stack using this given linked list. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack.

Approach:
- We use the class `MyStack` to represent the stack implemented using a linked list.
- The stack is implemented using a singly linked list where each node represents an element in the stack.
- The `push(int)` function inserts an element at the top of the stack by creating a new node and updating the `next` pointer to point to the current top.
- The `pop()` function removes the top element from the stack by updating the `top` pointer to the next node and returning the data of the removed node.

Code:
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class MyStack
{
    public:
    Node* topNode = NULL;

    void push(int x)
    {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
        cout<<topNode->data<<endl;
    }

    void pop()
    {
        Node* temp = topNode;
        cout<<temp->data<<endl;
        topNode = topNode->next;
        delete temp;
    }

    void top()
    {
        cout<<topNode->data<<endl;
    }

    void size()
    {
        int count=0;
        Node* curr = topNode;

        while(curr != NULL)
        {
            count++;
            curr = curr->next;
        }
        cout<<count<<endl;
    }
};

int main()
{
    MyStack st;
    st.push(13);
    st.push(26);
    st.push(39);
    st.push(52);
    st.pop();
    st.pop();
    st.top();
    st.size();
    st.push(65);
    st.size();

    return 0;
}

/*
Complexity Analysis:
- The `push()` operation has a time complexity of O(1) since we only need to create a new node and update the `top` pointer.
- The `pop()` operation has a time complexity of O(1) since we only need to update the `top` pointer and delete the node.
- The space complexity is O(N), where N is the total number of elements stored in the stack (linked list).
*/

