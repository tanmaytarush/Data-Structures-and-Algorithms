/*
QUESTION:-
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

APPROACH:
Traverse both linked lists simultaneously, starting from the heads.
At each step, add the corresponding digits from both linked lists along with the carry (initialized as 0).
Create a new node with the sum%10 and update the carry as sum/10.
Move to the next nodes in both linked lists.
Continue this process until both linked lists are traversed completely and there is no carry left.
If one linked list is shorter than the other, consider its remaining digits as 0.
If there is still a remaining carry, create a new node with the carry and append it to the result linked list.
Return the head of the result linked list.

TIME COMPLEXITY: O(max(N, M)), where N and M are the lengths of the two input linked lists.
SPACE COMPLEXITY: O(max(N, M)), as the length of the result linked list can be at most max(N, M)+1.

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
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

Node* AddNumToLL(Node* head, int num)
{
    head = revLL(head);

    int sum = 0;
    int carry = num;

    Node* temp = head;

    while(temp != NULL)
    {
        sum = temp->data + carry;
        temp->data = sum%10;
        carry = sum/10;

        if(temp == NULL && carry)
        {
            Node* newNode = new Node(carry);
            temp->next = newNode;
            carry = 0;
        }
        temp = temp->next;
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

    head = AddNumToLL(head, 5);
    Node::printLL(head);
    cout<<endl;

    return 0; 
}
