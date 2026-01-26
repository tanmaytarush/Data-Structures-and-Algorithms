/*
QUESTION:-
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

APPROACH:
The idea is to reverse the nodes of the linked list in groups of size k.
First, we need to check if there are at least k nodes remaining in the linked list. If not, we return the head as it is.
Next, we reverse the first k nodes of the linked list. To do this, we maintain three pointers: prev, curr, and frwd.
We iterate through the first k nodes and at each step, we reverse the links between the nodes.
After reversing the first k nodes, prev becomes the new head, and curr becomes the new tail of the reversed group.
We recursively call the function on the remaining linked list starting from frwd (which points to the (k+1)-th node).
Finally, we update the next pointer of the original head to point to the reversed group obtained from the recursive call.

TIME COMPLEXITY: O(N), where N is the number of nodes in the linked list.
SPACE COMPLEXITY: O(1).
*/

#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
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
    Node* temp = head;

    for(int i=1; i<n; ++i)
    {
        curr = new Node(arr[i]);
        temp->next = curr;
        temp = curr;
    }

    return head;
}

Node* reverseLL(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* newHead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

Node* getKthNode(Node* temp, int k)
{
    k -= 1;
    while(temp!=NULL && k>0)
    {
        k--;
        temp = temp->next;
    }

    return temp;
}

Node* reverseKGroups(Node* head, int k)
{
    Node* temp = head;
    Node* prevNode = NULL;
    Node* nextNode = NULL;

    while(temp != NULL)
    {
        Node* KthNode = getKthNode(temp, k);
        if(KthNode == NULL)
        {
            if(prevNode) prevNode->next = temp;
            break;
        }

        Node* nextNode = KthNode->next;
        KthNode->next = NULL;
        reverseLL(temp);
        if(temp == head)
        {
            head = KthNode;
        } 
        else
        {
            prevNode->next = KthNode;
        }

        prevNode = temp;
        temp = nextNode;
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
    Node::printLL(head);
    cout<<endl;

    head = reverseKGroups(head, k);
    Node::printLL(head);
    cout<<endl;

    return 0;
}