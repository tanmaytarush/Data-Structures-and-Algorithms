/*
QUESTION:- 
Given a singly linked list and an integer x.Delete xth node from the singly linked list.

Example 1:

Input: 1 -> 3 -> 4 
       x = 3
Output: 1 -> 3
Explanation:
After deleting the node at 3rd
position (1-base indexing), the
linked list is as 1 -> 3. 
Example 2:

Input: 1 -> 5 -> 2 -> 9 
x = 2
Output: 1 -> 2 -> 9
Explanation: 
After deleting the node at 2nd
position (1-based indexing), the
linked list is as 1 -> 2 -> 9.

APPROACH:- 
1. If the given position is 1, it means the node to be deleted is the first node. In this case, we simply update the head pointer to the next node and return the new head.
2. Initialize a counter `cnt` to 1 and a pointer `curr` to the head of the linked list.
3. Traverse the linked list by moving the `curr` pointer to the next node until the counter `cnt` reaches the position just before the node to be deleted.
4. Once we reach the position just before the node to be deleted, we update the `next` pointer of the current node to skip the next node and point to the node after it.
5. Return the head pointer of the modified linked list.



Time complexity of this approach is O(N), where N is the number of nodes in the linked list. We may need to traverse the linked list until we reach the desired position.
Space complexity is O(1) as we are not using any extra space that grows with the input size. We only need a constant amount of space to store the counter variable and the temporary pointer.

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
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

Node* convertArrToLL(vector<int> arr)
{
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i=1; i<n; ++i)
    {
        temp->next = new Node(arr[i]); // assign next node onwards
        temp = temp->next;
    }
    return head;
}

Node* deleteNode(Node* head, int k)
{
    Node* temp = head;
    Node* mover = head;
    int count = 0;

    Node* prev = NULL;

    while(temp != NULL)
    {
        count++;

        if(count == k)
        {
            prev->next = temp->next;
            free(temp);
        }
        prev = temp;
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

    int k;
    cin>>k;

    Node* head = convertArrToLL(arr);

    Node* temp = deleteNode(head, k);

    Node::printLL(head);

    return 0;
}