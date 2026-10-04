/*Given a doubly linked list of n nodes sorted by values, the task is to remove duplicate nodes present in the linked list.

Example 1:
Input:
n = 6
1<->1<->1<->2<->3<->4
Output:
1<->2<->3<->4
Explanation:
Only the first occurrence of the node with value 1 is retained, and the rest of the nodes with value 1 are deleted.

Example 2:
Input:
n = 7
1<->2<->2<->3<->3<->4<->4
Output:
1<->2<->3<->4
Explanation:
Only the first occurrence of nodes with values 2, 3, and 4 are retained, and the rest of the repeating nodes are deleted.

Approach:
1. Initialize a variable `dupli` with the value of the head node.
2. Start from the next node, `curr`, and iterate until the end of the linked list.
3. For each node, check if its data is equal to `dupli`.
   - If it is equal, remove the node by updating the `next` and `prev` pointers of its neighboring nodes.
   - Continue removing all consecutive nodes with the same value.
4. If `curr` is not null, update `dupli` with the data of `curr`.
5. Repeat steps 3-4 until the end of the linked list is reached.
6. Return the head of the modified linked list.

Time Complexity: O(N), where N is the number of nodes in the linked list.
Space Complexity: O(1).

CODE:
*/

#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
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

Node* convertArrToLL(vector<int> arr)
{
    Node* head = new Node(arr[0]);
    Node* curr = head;
    Node* last = head;
    int n = arr.size();

    for(int i=1; i<n; ++i)
    {
        curr = new Node(arr[i]);
        curr->prev = last;
        last->next = curr;
        last = curr;
    }

    return head;
}

Node* removeDuplicates(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        Node* newNode = temp->next;
        while(newNode != NULL && newNode->data == temp->data)
        {
            Node* duplicate = newNode;
            newNode = newNode->next;
            free(duplicate); // free memory spaces
        }
        
        temp->next = newNode;
        if(newNode) newNode->prev = temp;
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

    Node* head = convertArrToLL(arr);
    Node::printLL(head);
    cout<<endl;

    head = removeDuplicates(head);
    Node::printLL(head);
    cout<<endl;

    return 0;
}