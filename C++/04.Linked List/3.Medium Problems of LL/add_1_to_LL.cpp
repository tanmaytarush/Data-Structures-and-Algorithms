/*
QUESTION:-
A number N is represented in a linked list such that each digit corresponds to a node in the linked list. 
You need to add 1 to the number represented by the linked list.

APPROACH:
To add 1 to the number represented by the linked list, we can reverse the linked list, perform the addition, and then reverse it back.
First, reverse the linked list.
Traverse the reversed linked list while keeping track of the carry.
Add 1 to the least significant digit (head) and update the carry if necessary.
Continue traversing the linked list, adding the carry to each digit and updating the carry.
If there is still a remaining carry after traversing the linked list, create a new node with the carry as its value and append it to the end of the linked list.
Reverse the linked list again to restore its original order.

TIME COMPLEXITY: O(N), where N is the length of the linked list.
SPACE COMPLEXITY: O(1)

*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
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

Node* convertArrToLL(vector<int> &arr)
{
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* curr = head;
    Node* temp = curr;

    for(int i=1; i<n; ++i)
    {
        curr = new Node(arr[i]);
        temp->next = curr;
        temp = curr;
    }

    return head;
}

Node* revLL(Node* head)
{
    Node* temp = head;
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node* newHead = revLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

Node* Add1ToLL(Node* head)
{
    head = revLL(head);
    int sum = 0;
    int carry = 1;
    Node* temp = head;

    while(temp != NULL)
    {
        sum = temp->data + carry;
        if(sum == 10)
        {
            carry = 1;
            temp->data = 0;
        }
        else
        {
            carry = 0;
            temp->data = sum;
        }
        temp = temp->next;
    }

    if(carry)
    {
        Node* newNode = new Node(1);
        temp->next = newNode;
    }

    head = revLL(head);
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

    Node* head = convertArrToLL(arr);
    Node::printLL(head);
    cout<<endl;

    head = Add1ToLL(head);
    Node::printLL(head);
    cout<<endl;

    return 0; 
}
