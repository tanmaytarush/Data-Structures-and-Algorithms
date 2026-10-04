/*
QUESTION:-
Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the position just after pth node in the doubly linked list.

Example 1:

Input:
LinkedList: 2<->4<->5
p = 2, x = 6 
Output: 2 4 5 6
Explanation: p = 2, and x = 6. So, 6 is
inserted after p, i.e, at position 3
(0-based indexing).
Example 2:

Input:
LinkedList: 1<->2<->3<->4
p = 0, x = 44
Output: 1 44 2 3 4
Explanation: p = 0, and x = 44 . So, 44
is inserted after p, i.e, at position 1
(0-based indexing).

APPROACH:-
The approach to adding a node at a specific position in a doubly linked list is as follows:

1. Initialize a counter `cnt` to 0 and a pointer `curr` to the head of the linked list.
2. Traverse the linked list using the `curr` pointer until the `cnt` is less than the specified position.
3. Increment the `cnt` by 1 and move the `curr` pointer to the next node in each iteration.
4. Once the `cnt` reaches the desired position, create a new node with the given data.
5. Set the `next` pointer of the new node to the next node of the current node (`curr->next`) and the `prev` pointer of the new node to the current node (`curr`).
6. Update the `next` pointer of the current node (`curr->next`) to point to the new node.
7. If the new node is inserted in the middle of the list, update the `prev` pointer of the next node (`nxt`) to point to the new node.
8. The new node is successfully inserted into the linked list.

Time complexity of this approach is O(N), where N is the number of nodes in the doubly linked list. In the worst case, we may need to traverse the entire list to reach the desired position.
Space complexity is O(1) as we are using a constant amount of extra space to store temporary pointers during the insertion process.

CODE:-
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1)
    {
        this->data = data1;
        this->next = next1;
        this->prev = prev1;
    }

    Node(int data1)
    {
        this->data = data1;
        this->next = nullptr;
        this->prev = nullptr;
    }

    static void printLL(Node* head)
    {
        Node* tail = head;
        while(tail != NULL)
        {
            cout<<tail->data<<"->";
            tail=tail->next;
        }
    }
};

Node* convertArrtoDLL(vector<int> &arr)
{
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* curr = head;
    Node* tail = curr;

    for(int i=1; i<n; ++i)
    {
        tail = new Node(arr[i]);
        curr->next = tail;
        tail->prev = curr;
        curr = tail;
    }

    return head;
}

Node* insertBeforHead(Node* head, int value)
{   
    Node* newNode = new Node(value);
    newNode->next = head;
    head->prev = newNode;

    return newNode;
}

Node* insertAfterTail(Node* head, int value)
{
    Node* tail = head;
    while(tail->next != NULL) // stop at last node
    {
        tail=tail->next;
    }

    Node* newNode = new Node(value, nullptr, tail);
    tail->next = newNode;

    return head;
}

Node* insertAtK(Node* head, int value, int k)
{
    if(head==NULL)
    {
        return new Node(value, nullptr, nullptr);
    }

    if(head->next == nullptr) // after head
    {
        if(k==1)
        {
            Node* newNode = new Node(value, nullptr, head);
            head->next = newNode;
        }
        return head;
    }

    Node* temp = head;
    int count = 0;

    while(temp->next != NULL)
    {
        if(count == k-1)
        {
            Node* forward = temp->next;
            Node* newNode = new Node(value, forward, temp);
            temp->next = newNode;
            forward->prev = newNode;
        }
        temp = temp->next;
        count++;
    }

    return head;
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

    int value, k;
    cin>>value>>k;

    Node* head = convertArrtoDLL(arr);

    head = insertBeforHead(head, value);

    head = insertAfterTail(head, value);

    head = insertAtK(head, value, k);

    Node::printLL(head);

    return 0;
}