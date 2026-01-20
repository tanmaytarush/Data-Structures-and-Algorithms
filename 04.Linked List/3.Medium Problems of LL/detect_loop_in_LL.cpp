/*
QUESTION:-
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
*/

/*
APPROACH:
To determine if a linked list has a cycle, we can use the two-pointer technique.
Initialize two pointers, slow and fast, to the head of the linked list.
Move the slow pointer one step at a time and the fast pointer two steps at a time.
If the linked list has a cycle, the fast pointer will eventually catch up to the slow pointer.
In other words, if there is a cycle, the two pointers will meet at some point.
If the fast pointer reaches the end of the list (i.e., it becomes NULL or reaches a node with a NULL next pointer), then there is no cycle in the linked list.
Return true if the two pointers meet (indicating a cycle), and false otherwise.
*/

// CODE:-

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

Node* createCircularNode(vector<int> &arr, int pos)
{
    Node* head = convertArrToLL(arr);

    Node* tail = head;
    Node* join = nullptr;

    int index = 0;
    while(tail->next != NULL)
    {
        if(index == pos)
        {
            join = tail;
        }
        tail = tail->next;
        index++;
    }

    if(index == pos) join = tail; // last index

    tail->next = join;

    return head;
}

bool directLoopMap(Node* head)
{
    unordered_map<Node*, int> mpp;
    Node* temp = head;

    while(temp != NULL)
    {
        if(mpp.find(temp) != mpp.end())
        {
            return true;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }

    return false;
}

bool directLoopOptimized(Node* head)
{
    if(head == NULL) return false;

    Node* slow = head;
    Node* fast = head;

    Node* temp = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            return true;
        }
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

    int pos;
    cin>>pos;

    Node* head = convertArrToLL(arr);

    head = createCircularNode(arr, pos);

    bool result1 = directLoopMap(head);

    bool result2 = directLoopOptimized(head);

    cout<<result1<<" "<<result2;

    // Node::printLL(head);  temp is never null

    return 0;
}

// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)
