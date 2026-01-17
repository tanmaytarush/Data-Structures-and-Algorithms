/*
Given a doubly linked list of n elements. The task is to reverse the doubly linked list.

Example 1:

Input:
LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3
Example 2:

Input:
LinkedList: 75 <--> 122 <--> 59 <--> 196
Output: 196 59 122 75

APPROACH:-
1. The function `reverseDLL` takes in one parameter: `head`, which is a pointer to the head of the doubly linked list.
2. The variable `curr` is initialized with the `head` pointer, which represents the current node being processed.
3. The variable `ans` is initialized as `NULL`. It will store the new head of the reversed linked list.
4. The code enters a `while` loop, which continues until `curr` becomes `NULL`, indicating that all nodes have been processed.
5. Inside the loop, the variable `nxt` is assigned the value of `curr->next`, which represents the next node in the original list.
6. The next and previous pointers of the current node (`curr->next` and `curr->prev`) are swapped to reverse the links.
7. The `if` condition checks if `curr->prev` is `NULL`, indicating that `curr` is the last node in the original list (now the first node in the reversed list). In this case, the `ans` pointer is updated to store the new head of the reversed list.
8. The `curr` pointer is updated to `curr->prev`, which moves it to the previous node in the original list.
9. After the loop, the `ans` pointer now holds the new head of the reversed list. It is returned as the result.

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

    static void printLL(Node* head)
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
    }
};

Node* convertArrtoDLL(vector<int> &arr)
{
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* curr = head;
    Node* temp = head;

    for(int i=1; i<n; ++i)
    {
        Node* temp = new Node(arr[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }

    return head;
}

Node* reverseDLL(Node* head)
{
    Node* curr = head;
    Node* temp = nullptr;

    while(curr != nullptr)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // move forward, i.e. new previous
        curr = curr->prev;
    }

    // point to new head
    if(temp != nullptr)
    {
        head = temp->prev;
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

    Node* head = convertArrtoDLL(arr);

    head = reverseDLL(head);

    Node::printLL(head);

    return 0;
}

/*
Time Complexity:
- The code iterates over each node of the doubly linked list exactly once, performing a constant number of operations for each node. Therefore, the time complexity is O(n), where n is the number of nodes in the linked list.
Space Complexity:
- The code uses a constant amount of extra space for variables (`curr`, `nxt`, `ans`). Hence, the space complexity is O(1).
*/