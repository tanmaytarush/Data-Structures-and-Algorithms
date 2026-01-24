/**QUESTION:**

You are given the head of a doubly Linked List and a key. Your task is to delete all occurrences of the given key and return the new doubly Linked List.

**Example:**

Input: 
2 <-> 2 <-> 10 <-> 8 <-> 4 <-> 2 <-> 5 <-> 2
Key: 2
Output: 
10 <-> 8 <-> 4 <-> 5
Explanation: 
All occurrences of 2 have been deleted.

**APPROACH:**

To delete all occurrences of the given key from a doubly linked list, we can traverse the list and check each node's data. If the data matches the key, we handle three cases: deleting the first node, deleting the last node, and deleting a middle node. We update the pointers accordingly to remove the node from the list.

**TIME COMPLEXITY:** The time complexity is O(N), where N is the number of nodes in the doubly linked list.

**SPACE COMPLEXITY:** The space complexity is O(1) since we are modifying the given linked list in-place without using any extra space.

**CODE:**/

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
    Node* prev;

    Node(int data1, Node* next1, Node* prev1)
    {
        this->data = data1;
        this->next = next1;
        this->prev = prev1;
    }

    Node(int data1)
    {
        this->data = data1;
        this->next = nullptr;
        this->prev = nullptr;
    }

    static void printDLL(Node* head)
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

Node* convertArrToDLL(vector<int> &arr)
{
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* curr = head;
    Node* last = head;

    for(int i=1; i<n; ++i)
    {
        curr = new Node(arr[i]);
        curr->prev = last;
        last->next = curr;
        last = curr;
    }

    return head;
}

Node* deleteAllOccurences(Node* head, int k)
{
    Node* curr = head;

    while(curr != NULL)
    {
        if(curr->data == k)
        {
            Node* temp = curr;

            // first node
            if(curr->prev == NULL)
            {
                head = curr->next;
                if(head) head->prev = NULL;
                curr = head;
            }

            // middle node or last node
            else
            {
                curr->prev->next = curr->next;
                if(curr->next) curr->next->prev = curr->prev;
                curr = curr->next; // else reaches null if last node
            }

            delete temp;
        }

        else
        {
            curr = curr->next;
        }
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

    Node* head = convertArrToDLL(arr);
    Node::printDLL(head);
    cout<<endl;

    head = deleteAllOccurences(head, 10);
    Node::printDLL(head);

    return 0;
}
