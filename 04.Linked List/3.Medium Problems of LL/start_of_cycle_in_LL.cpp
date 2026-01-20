/*
QUESTION:-
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
*/

/*
APPROACH:
To find the node where the cycle begins in a linked list, we can use the Floyd's cycle-finding algorithm, also known as the "tortoise and hare" algorithm.
Initialize two pointers, slow and fast, to the head of the linked list.
Move the slow pointer one step at a time and the fast pointer two steps at a time.
If the linked list has a cycle, the fast pointer will eventually catch up to the slow pointer.
In other words, if there is a cycle, the two pointers will meet at some point.
Once the two pointers meet, move one of the pointers back to the head of the linked list.
Then, move both pointers one step at a time until they meet again.
The point at which they meet is the node where the cycle begins.
Return this node.
If the fast pointer reaches the end of the list (i.e., it becomes NULL or reaches a node with a NULL next pointer), then there is no cycle in the linked list, and we can return NULL.
*/

#include<iostream>
#include<unordered_map>
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

Node* createCircularLoop(vector<int> &arr, int pos)
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

    if(index == pos) join = tail;   // last node, pos == len(linked_list)

    tail->next = join;

    return head;
}

Node* startOfLoopMap(Node* head)
{
    unordered_map<Node*, int> mpp;
    Node* temp = head;

    while(temp != NULL)
    {
        if(mpp.find(temp) != mpp.end())
        {
            return temp;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }

    return NULL;
}

Node* startOfLoopOptimal(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            slow = head;
            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
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

    Node::printLL(head);

    head = createCircularLoop(arr, pos);

    cout<<endl;

    Node* temp1 = startOfLoopMap(head);

    Node* temp2 = startOfLoopOptimal(head);

    cout<<temp1<<" "<<temp2;

    return 0;
}


// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)
