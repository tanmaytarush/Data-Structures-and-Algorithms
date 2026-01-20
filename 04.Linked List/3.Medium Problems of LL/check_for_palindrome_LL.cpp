/*
QUESTION:-
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false
*/

/*
APPROACH:
To determine if a linked list is a palindrome, we can follow these steps:
1. Find the middle node of the linked list using the slow and fast pointer technique.
2. Reverse the second half of the linked list.
3. Compare the first half of the original linked list with the reversed second half.
4. If all nodes match, the linked list is a palindrome.
5. If any node does not match, the linked list is not a palindrome.
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

bool checkPalindromeStack(Node* head)
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
        if(temp->data != st.top())
        {
            return false;
        }
        st.pop();
        temp = temp->next;
    }
    return true;
}

Node* reverseLL(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* newHead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

bool checkPalindromeOptimal(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newHead = reverseLL(slow->next);
    Node* first = head;
    Node* second = newHead;

    while(second != NULL)
    {
        if(first->data != second->data)
        {
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
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

    bool result1 = checkPalindromeStack(head);

    bool result2 = checkPalindromeOptimal(head);

    cout<<result1<<" "<<result2;

    return 0;
}


// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)


