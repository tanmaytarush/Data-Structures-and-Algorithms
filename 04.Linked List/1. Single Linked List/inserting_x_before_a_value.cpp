/*

📌 Problem: Insert Value x Before a Given Value in a Linked List

You are given the head of a singly linked list, an integer target, and an integer x.

Your task is to insert a new node with value x immediately before the first occurrence of target in the linked list.

🔹 Rules
	•	If target does not exist in the list, return the list unchanged.
	•	If target is the head node, insert x before the head and return the new head.
	•	The linked list contains non-negative integers.

⸻

🔹 Function Signature

ListNode* insertBeforeValue(ListNode* head, int target, int x);


⸻

🔹 Input
	•	head: Head of the singly linked list
	•	target: Value before which x should be inserted
	•	x: Value to be inserted

⸻

🔹 Output
	•	Return the head of the modified linked list

⸻

🔹 Examples

Example 1

Input:  head = [1, 2, 3, 4], target = 3, x = 10
Output: [1, 2, 10, 3, 4]

Example 2

Input:  head = [5, 6, 7], target = 5, x = 1
Output: [1, 5, 6, 7]

Example 3

Input:  head = [1, 2, 3], target = 8, x = 4
Output: [1, 2, 3]


⸻

🔹 Constraints
	•	0 ≤ Number of nodes ≤ 10⁴
	•	0 ≤ Node.val, target, x ≤ 10⁴

⸻

🔹 Follow-up
	•	Can you solve this in O(n) time and O(1) extra space?

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
        while(tail != NULL)
        {
            cout<<tail->data<<"->";
            tail = tail->next;
        }
        cout<<endl;
    }
};

Node* convertArrtoLL(vector<int> &arr)
{
    int n = arr.size();
    
    if(n==0)
    {
        return nullptr;
    }

    Node* head = new Node(arr[0]);
    Node* tail = head;
    Node* curr = head;

    for(int i=1; i<n; ++i)
    {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

Node* insertXBeforeA(Node* head, int x, int a)
{
    if(head == NULL)
    {
        return nullptr;
    }

    if(head->data == a)
    {
        Node* newHead = new Node(x);
        newHead->next = head;

        return newHead;
    }

    Node* temp = head;
    while(temp->next != NULL)
    {
        if(temp->next->data == a)
        {
            Node* newNode = new Node(x);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
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

    int x;
    int a;
    cin>>x>>a;

    Node* head = convertArrtoLL(arr);

    head = insertXBeforeA(head, x, a);

    Node::printLL(head);

    return 0;
}