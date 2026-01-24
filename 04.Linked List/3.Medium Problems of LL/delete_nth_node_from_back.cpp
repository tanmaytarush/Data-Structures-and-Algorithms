/*
QUESTION:-
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
*/

/*
APPROACH:
To remove the nth node from the end of the linked list, we can follow these steps:
1. Initialize two pointers, `left` and `right`, to the head of the linked list.
2. Move the `right` pointer n nodes ahead.
3. If `right` becomes NULL, it means the first node needs to be removed. Return head->next.
4. Iterate until `right->next` becomes NULL.
5. Move both `left` and `right` pointers one node ahead in each iteration.
6. Once `right->next` becomes NULL, `left` will be pointing to the (n-1)th node from the end.
7. Update `left->next` to skip the nth node from the end.
8. Return the head of the modified linked list.

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
*/


#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
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
            cout<<temp->data;
            temp = temp->next;
        }
    }
};

Node* convertArrtoLL(vector<int> &arr)
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

Node* deleteNthNodeBF(Node* head, int k)
{
    int count = 0;
    Node* temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if(count == k)
    {
        Node* newHead = head->next;
        return newHead;
    }

    int res = count - k;
    temp = head;
    while(temp != NULL)
    {
        res--;
        if(res == 0)
        {
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            free(delNode);
        }
        temp = temp->next;
    }

    return head;
}

Node* deleteNthNodeOptimal(Node* head, int k)
{
    Node* temp = head;
    Node* fast = head;

    if(k==0)
    {
        return head->next;
    }

    for(int i=0; i<k; ++i)
    {
        fast = fast->next;
    }

    Node* slow = head;
    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node* delNode = slow->next;
    slow->next = slow->next->next;
    free(delNode);

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

    Node* head = convertArrtoLL(arr);
    Node::printLL(head);
    cout<<endl;

    head = deleteNthNodeBF(head, k);
    Node::printLL(head);
    cout<<endl;

    head = deleteNthNodeOptimal(head, k);
    Node::printLL(head);
    cout<<endl;

    return 0;
}