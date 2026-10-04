/*
QUESTION:-
Given the head of a linked list, rotate the list to the right by k places.

APPROACH:
To rotate the linked list to the right by k places, we need to perform the following steps:
1. Find the length of the linked list and connect the last node to the head to form a circular linked list.
2. Calculate the actual number of rotations by taking the modulus of k with the length of the linked list.
3. Traverse to the (length - k - 1)th node, which will be the new tail of the rotated list.
4. Set the new head as the next node of the (length - k - 1)th node and disconnect it from the rest of the list.
5. Return the new head.

TIME COMPLEXITY: O(N), where N is the number of nodes in the linked list.
SPACE COMPLEXITY: O(1).
*/

#include<iostream>
#include<vector>
#include<stack>
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

Node* getKthNode(Node* head, int k)
{
    Node* temp = head;
    int count = 1;
    while(temp != NULL)
    {
        if(count == k) return temp;
        count++;
        temp = temp->next;
    }
    return temp;
}

Node* rotateKTimes(Node* head, int k)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node* tail = head;
    int len = 1;
    while(tail->next != NULL)
    {
        len++;
        tail = tail->next;
    }

    if(k % len == 0) return head;
    k = k%len;

    tail->next = head;
    Node* newTail = getKthNode(head, len-k);
    head = newTail->next;
    newTail->next = NULL;

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

    int k;
    cin>>k;

    Node* head = convertArrToLL(arr);
    Node::printLL(head);
    cout<<endl;

    head = rotateKTimes(head, k);
    Node::printLL(head);
    cout<<endl;

    return 0;
}
