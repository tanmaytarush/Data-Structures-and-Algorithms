/*
QUESTION:-
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
*/

/*
APPROACH:
-> To find the middle node of a linked list, we can use the two-pointer technique.
-> Initialize two pointers, slow and fast, to the head of the linked list.
-> Move the slow pointer one step at a time and the fast pointer two steps at a time.
-> When the fast pointer reaches the end of the list, the slow pointer will be at the middle node.
-> If the total number of nodes in the list is even, there will be two middle nodes, and the slow pointer will be at the first middle node.
-> To return the second middle node, we need to move the slow pointer one more step.
-> Finally, return the node pointed to by the slow pointer.
*/

// CODE:-

#include<iostream>
#include<vector>
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
            cout<<temp->data<<"->";
            temp = temp->next;
        }
    }
};

Node* convertArrtoLL(vector<int> &arr)
{
    Node* head = new Node(arr[0]);
    Node* temp = head;
    Node* curr = head;

    for(int i=1; i<arr.size(); ++i)
    {
        Node* curr = new Node(arr[i]);
        temp->next = curr;
        temp = curr;
    }
    return head;
}

Node* findMidLLBruteForce(Node* head)
{
    Node* temp = head;
    Node* tail = head;
    int count = 0;

    while(tail != NULL)
    {
        count++;
        tail = tail->next;
    }

    int midCount = (count/2) + 1;
    while(temp != NULL)
    {
        midCount = midCount - 1;
        if(midCount == 0)
        {
            break;
        }
        temp = temp->next;
    }
    return temp;
}

Node* findMidLLOptimal(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

    Node* result1 = findMidLLBruteForce(head);

    Node* result2 = findMidLLOptimal(head);

    cout<<result1->data<<" "<<result2->data;

    return 0;
}

// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)
