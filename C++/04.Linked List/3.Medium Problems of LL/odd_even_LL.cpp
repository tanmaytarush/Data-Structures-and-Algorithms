/*
QUESTION:-
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
*/

/*
APPROACH:
To group nodes with odd indices together followed by nodes with even indices, we can follow these steps:
1. Initialize two pointers, `odd` and `even`, to the first and second nodes respectively.
2. Save the starting node of the even list as `evenHead`.
3. Iterate while `odd->next` and `even` are not NULL.
4. Connect the odd list with the next odd node (`odd->next = even->next`).
5. Move the `odd` pointer to the next odd node (`odd = odd->next`).
6. Connect the even list with the next even node (`even->next = odd->next`).
7. Move the `even` pointer to the next even node (`even = even->next`).
8. Connect the end of the odd list with the starting node of the even list (`odd->next = evenHead`).
9. Return the head of the modified list.

This approach reorders the linked list in place without using any extra space.

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
*/

#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
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

Node* oddEvenLL(Node* head)
{
    Node* odd = head;
    Node* even = odd->next;
    Node* evenHead = even;

    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    while(even!=NULL && even->next!=NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;

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

    head = oddEvenLL(head);

    Node::printLL(head);

    return 0;
}