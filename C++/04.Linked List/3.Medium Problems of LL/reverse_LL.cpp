/*
QUESTION:-
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]
*/

/*
APPROACH:
To reverse a singly linked list, we can use an iterative approach.
Initialize three pointers: prev as NULL, curr as head, and frwd as NULL.
Iterate through the linked list until curr becomes NULL:
    - Store the next node of curr in frwd.
    - Set the next of curr to prev, reversing the link.
    - Move prev and curr one step forward.
    - Move curr to the next node (frwd) to continue the iteration.
Return prev, which will be the new head of the reversed list.
*/

// CODE:-

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1)
    {
        this->data = data1;
        this->next = next1;
    }

    Node(int data1)
    {
        this->data = data1;
        this->next = nullptr;
    }

    static void printLL(Node* head)
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

Node* convertArrtoLL(vector<int> &arr)
{
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* temp = head;
    Node* curr = head;

    for(int i=1; i<n; ++i)
    {
        temp = new Node(arr[i]);
        curr->next = temp;
        curr = temp;
    }

    return head;
}

Node* reverseLLStack(Node* head)
{
    stack<int> st;
    Node* temp = head;

    while(temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

Node* reverseLLIterative(Node* head)
{
    Node* prev = NULL;
    Node* temp = head;

    while(temp != NULL)
    {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev; // previous points to last node, rest pointers to nullptr
}

Node* reverseLLRecursive(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node* newHead = reverseLLRecursive(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    Node* head = convertArrtoLL(arr);

    head = reverseLLStack(head);

    Node::printLL(head);

    cout<<endl;

    head = reverseLLRecursive(head);

    Node::printLL(head);

    cout<<endl;

    head = reverseLLIterative(head);

    Node::printLL(head);

    return 0;
}


// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)
