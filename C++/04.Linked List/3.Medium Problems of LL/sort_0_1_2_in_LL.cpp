/*
QUESTION:-
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. 
The task is to segregate 0s, 1s, and 2s in the linked list such that all zeros segregate to the head side, 2s at the end of the linked list, and 1s in the middle of 0s and 2s.

Example:
Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.

APPROACH:
Count the number of 0s, 1s, and 2s in the linked list.
Traverse the linked list and overwrite the nodes with 0s, 1s, and 2s based on their counts.

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)

*/

#include<iostream>
#include<algorithm>
#include<stack>
#include<unordered_map>
#include<vector>
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

Node* sort012BruteForce(Node* head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == 0)
        {
            zeroCount++;
        }
        else if(temp->data == 1)
        {
            oneCount++;
        }
        else
        {
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL)
    {
        if(zeroCount)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount)
        {
            temp->data = 1;
            oneCount--;
        }
        else
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }

    return head;
}

Node* sort012Optimal(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    Node* temp = head;

    while(temp != NULL)
    {
        if(temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }

        else if(temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }

        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    zero->next = (oneHead->next)?(oneHead->next):(twoHead->next);
    one->next = twoHead->next;
    two->next = NULL;

    Node* newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

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

    Node* head = convertArrToLL(arr);
    Node::printLL(head);
    cout<<endl;

    head = sort012BruteForce(head);
    Node::printLL(head);
    cout<<endl;

    head = sort012Optimal(head);
    Node::printLL(head);
    cout<<endl;

    return 0;
}