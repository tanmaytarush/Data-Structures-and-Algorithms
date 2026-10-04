/**QUESTION:**

Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is the head.
Each of the sub-linked lists is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.

Note: The flattened list will be printed using the bottom pointer instead of the next pointer.

**APPROACH:**

To flatten the linked list, we can use a recursive approach. The idea is to flatten the list from right to left. Starting from the last node, we recursively flatten the sublist pointed by the bottom pointer and merge it with the current node. We continue this process until we reach the head of the original linked list. Finally, we return the flattened list.

**TIME COMPLEXITY:** The time complexity is O(N), where N is the total number of nodes in the linked list.

**SPACE COMPLEXITY:** The space complexity is O(1) since we are modifying the given linked list in-place without using any extra space.

**CODE:**/

#include<iostream>
#include<stack>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* bottom;

    Node(int data1, Node* next1, Node* bottom1)
    {
        this->data = data1;
        this->next = next1;
        this->bottom = bottom1;
    }

    Node(int data1)
    {
        this->data = data1;
        this->next = nullptr;
        this->bottom = nullptr;
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

// Node* convertArrToLL(vector<int> &arr)
// {
//     int n = arr.size();
//     Node* head = new Node(arr[0]);
//     Node* curr = head;
//     Node* temp = curr;

//     for(int i=1; i<n; ++i)
//     {
//         curr = new Node(arr[i]);
//         temp->bottom = curr;
//         temp->next = NULL;
//         temp = curr;
//     }
//     return head;
// }

Node* buildListwithBottom()
{
    int n;
    cin>>n;

    Node* head = nullptr;
    Node* prev = nullptr;

    for(int i=0; i<n; ++i)
    {
        int m;
        cin>>m; // number of nodes in the bottom list

        int x;
        cin>>x;

        Node* mainNode = new Node(x);
        if(!head) head = mainNode;
        if(prev) prev->next = mainNode;
        prev = mainNode;

        Node* curr = mainNode;
        for(int j=1; j<m; ++j)
        {
            cin>>x;
            curr->bottom = new Node(x);
            curr = curr->bottom;
        }
    }
    return head;
}

void printFlattened(Node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->bottom;
    }
}

Node* merge2LL(Node* list1, Node* list2)
{
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->data < list2->data)
        {
            res->bottom = list1;
            // res = list1;
            list1 = list1->bottom;
        }
        else
        {
            res->bottom = list2;
            // res = list2;
            list2 = list2->bottom;
        }
        res = res->bottom;
        res->next = nullptr; // point to nullptr
    }

    res->bottom = (list1 ? list1 : list2);  // temp->bottom to list1 if list1 exists, else list2
    return dummyNode->bottom;
}

Node* flattenLL(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    head->next = flattenLL(head->next);
    head = merge2LL(head, head->next);
    return head;
}

int main()
{
    Node* head = buildListwithBottom();
    head = flattenLL(head);
    printFlattened(head);

    return 0;
}