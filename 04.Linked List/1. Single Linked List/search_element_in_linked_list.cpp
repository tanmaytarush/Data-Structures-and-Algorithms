/*
QUESTION:-
Given a linked list of n nodes and a key , the task is to check if the key is present in the linked list or not.

Example:

Input:
n = 4
1->2->3->4
Key = 3
Output:
True
Explanation:
3 is present in Linked List, so the function returns true.

APPROCACH:-
Just traverse the entire Linked List and if node's data matches with the target return true else return false.

TIME COMPLEXITY:- O(N)
SPACE COMPLEXITY:- O(1)

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
        Node* tail = head;
        while(tail != nullptr)
        {
            cout<<tail->data<<" ";
            tail = tail->next;
        }
    }
};


Node* convertArrtoLL(vector<int> &arr)
{
    if(arr.size() == 0)
    {
        return nullptr;
    }
    
    int n = arr.size();

    Node* head = new Node(arr[0]);
    Node* tail = head;

    for(int i=1; i<n; ++i)
    {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }

    return head;
}


bool searchElement(Node* head, int val)
{
    Node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == val)
        {
            return true;
            break;
        }
        temp=temp->next;
    }
    return false;
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

    int val;
    cin>>val;

    Node* head = convertArrtoLL(arr);

    bool result = searchElement(head, val);

    cout<<result;

    return 0;
}