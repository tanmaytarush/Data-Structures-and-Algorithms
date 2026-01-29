/*
QUESTION:
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

APPROACH:
To create a deep copy of a linked list with random pointers, we can follow these steps:
1. Traverse the original linked list and create a new node for each node in the original list. Insert the new node between the original node and its next node.
2. Set the random pointer of the new node by mapping it to the corresponding random node in the original list.
3. Separate the original list and the copied list by updating the next pointers of nodes in both lists.
4. Return the head of the copied list.

TIME COMPLEXITY:
The time complexity of this approach is O(n) since we traverse the original list once to create the copied list.

SPACE COMPLEXITY:
The space complexity is also O(n) because we create a new node for each node in the original list.

CODE:
*/

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stack>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int data1, Node* next1, Node* random1)
    {
        this->data = data1;
        this->next = next1;
        this->random = random1;
    }

    Node(int data1)
    {
        this->data = data1;
        this->next = nullptr;
        this->random = nullptr;
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
    Node* temp = head;
    Node* curr = temp;

    for(int i=1; i<n; ++i)
    {
        curr = new Node(arr[i]);
        temp->next = curr;
        temp = curr;
    }

    temp = head;
    while(temp->next->next != NULL)
    {
        temp->random = temp->next->random;
        temp = temp->next;
    }

    return head;
}

Node* copyRandomLLMap(Node* head)
{
    Node* temp = head;
    map<Node*, Node*> mpp;

    while(temp != NULL)
    {
        Node* newNode = new Node(temp->data);
        mpp[temp] = newNode;
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL)
    {
        Node* copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }

    return mpp[head];
}

void createCopyLL(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        Node* copyNode = new Node(temp->data);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }
}

void connectRandom(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        Node* copyNode = temp->next;
        if(temp->random) copyNode->random = temp->random->next; // if random points to nullptr
        else copyNode->random = nullptr;
        temp = temp->next->next;
    }
}

Node* returnNewLL(Node* head)
{
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    Node* temp = head;

    while(temp != NULL)
    {
        res->next = temp->next;
        temp->next = temp->next->next;

        res = res->next;
        temp = temp->next;
    }

    return dummyNode->next;
}

Node* deepCopyLL(Node* head)
{
    createCopyLL(head);
    connectRandom(head);
    return returnNewLL(head);
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

    head = copyRandomLLMap(head);
    Node::printLL(head);
    cout<<endl;

    head = deepCopyLL(head);
    Node::printLL(head);
    cout<<endl;
}