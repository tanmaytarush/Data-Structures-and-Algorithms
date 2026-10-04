/*
QUESTION:-
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

Example:
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node.

APPROACH:
To delete the middle node of a linked list, we can use the slow and fast pointer technique.
1. Initialize three pointers: slow, fast, and prev.
2. Move the slow pointer one step at a time and the fast pointer two steps at a time.
3. Keep track of the previous node using the prev pointer.
4. When the fast pointer reaches the end of the linked list, the slow pointer will be at the middle node.
5. Update the next pointer of the previous node to skip the middle node.
6. Return the head of the modified linked list.

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
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

Node* deleteMidNode(Node* head)
{
    Node* dummy = new Node(0, head);
    Node* fast = dummy;
    Node* slow = dummy;

    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = slow->next->next;
    return dummy->next;
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
    Node::printLL(head);
    cout<<endl;

    head = deleteMidNode(head);
    Node::printLL(head);
    cout<<endl;

    return 0;
}