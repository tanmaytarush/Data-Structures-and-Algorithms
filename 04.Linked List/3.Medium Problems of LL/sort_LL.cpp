/*
QUESTION:-
Given the head of a linked list, return the list after sorting it in ascending order.

Example:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

APPROACH:
To sort a linked list, we can use the merge sort algorithm.
1. Implement a function to merge two sorted linked lists.
2. Implement a function to recursively divide the linked list into two halves.
3. Apply merge sort on each half.
4. Merge the sorted halves using the merge function.
5. Return the head of the sorted linked list.

TIME COMPLEXITY: O(NlogN)
SPACE COMPLEXITY: O(logN) - Recursive stack space
*/

#include<iostream>
#include<vector>
#include<algorithm>
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

Node* findMiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head->next; // mid reached (N/2) not (N/2 + 1)

    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* merge2LL(Node* list1, Node* list2)
{
    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while(list1 != NULL && list2 != NULL)
    {
        if(list1->data < list2->data)
        {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }

        else
        {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }

    }
    
    if(list1) temp->next = list1;
    else temp->next = list2;

    return dummy->next;
}

Node* sortLL(Node* head)
{
    Node* temp = head;
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node* middle = findMiddle(head);
    Node* right = middle->next;
    middle->next = nullptr;
    Node* left = head;

    left = sortLL(left);
    right = sortLL(right);

    return merge2LL(left, right);
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

    head = sortLL(head);

    Node::printLL(head);

    return 0;
}