/*
QUESTION:-
Given a singly linked list. The task is to find the length of the linked list, where length is defined as the number of nodes in the linked list.

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 5
Explanation: Count of nodes in the 
linked list is 5, which is its length.
Example 2:

Input:
LinkedList: 2->4->6->7->5->1->0
Output: 7
Explanation: Count of nodes in the
linked list is 7. Hence, the output
is 7.

APPROACH:-

1. Initialize a variable `cnt` to 0 to keep track of the count.
2. Start with the `curr` pointer pointing to the head of the linked list.
3. Iterate through the linked list by moving the `curr` pointer to the next node in each iteration.
4. Increment the count `cnt` by 1 for each node encountered.
5. Continue the iteration until the `curr` pointer becomes NULL, indicating the end of the linked list.
6. Return the final count `cnt` as the result.

Time complexity of this approach is O(N), where N is the number of nodes in the linked list. We need to visit each node once to count them.
Space complexity is O(1) as we are not using any extra space that grows with the input size. We only need a constant amount of space to store the count variable and the temporary pointer.

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
        while(temp != nullptr)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
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
    Node* temp = head;
    Node* curr = head;

    for(int i=1; i<n; ++i)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    return head;
}

int countNodes(Node* head)
{
    Node* temp = head;
    Node* curr = head;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
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

    int result = countNodes(head);

    cout<<result<<endl;

    return 0;
}
