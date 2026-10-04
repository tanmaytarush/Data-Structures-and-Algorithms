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
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* newHead = revLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

Node* Add2LL(Node* head1, Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;

    int sum = 0;
    int carry = 0;
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;

    while(temp1 != NULL || temp2 != NULL)
    {
        sum = carry;
        if(temp1) sum += temp1->data;
        if(temp2) sum += temp2->data;

        Node* newNode = new Node(sum % 10);
        carry = sum/10;
        curr->next = newNode;
        curr = newNode;

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }

    if(carry)
    {
        Node* lastNode = new Node(carry);
        curr->next = lastNode;
        curr = lastNode;
        carry = 0;
    }

    return dummyNode->next;
}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<int> arr1(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr1[i];
    }

    vector<int> arr2(m);
    for(int i=0; i<m; ++i)
    {
        cin>>arr2[i];
    }

    Node* head1 = convertArrToLL(arr1);
    Node::printLL(head1);
    cout<<endl;

    Node* head2 = convertArrToLL(arr2);
    Node::printLL(head2);
    cout<<endl;

    Node* head = Add2LL(head1, head2);
    Node::printLL(head);
    cout<<endl;

    return 0; 
}
