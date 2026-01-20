/*
QUESTION:-
Given a linked list of size N. The task is to complete the function countNodesinLoop() that checks whether a given Linked List contains a loop or not and if the loop is present then return the count of nodes in a loop or else return 0. C is the position of the node to which the last node is connected. If it is 0 then no loop.

Example 1:
Input: N = 10
value[]={25,14,19,33,10,21,39,90,58,45}
C = 4
Output: 7
Explanation: The loop is 45->33. So
length of loop is 33->10->21->39->
90->58->45 = 7. The number 33 is
connected to the last node to form the
loop because according to the input the
4th node from the beginning(1 based
index) will be connected to the last
node for the loop.

Example 2:
Input: N = 2
value[] = {1,0}
C = 1
Output: 2
Explanation: The length of the loop
is 2.
*/

/*
APPROACH:
To detect a loop in a linked list, we can use the Floyd's cycle-finding algorithm, also known as the "tortoise and hare" algorithm.
Initialize two pointers, slow and fast, to the head of the linked list.
Move the slow pointer one step at a time and the fast pointer two steps at a time.
If the linked list has a loop, the fast pointer will eventually catch up to the slow pointer.
In other words, if there is a loop, the two pointers will meet at some point.
Once the two pointers meet, move one of the pointers back to the meeting point and start counting the number of nodes in the loop.
Continue moving the pointer until it reaches the meeting point again, counting the nodes along the way.
Return the count of nodes in the loop.
If the fast pointer reaches the end of the list (i.e., it becomes NULL or reaches a node with a NULL next pointer), then there is no loop in the linked list, and we can return 0.
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
            cout<<temp->data;
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

Node* formRotatedLL(vector<int> &arr, int pos)
{
    Node* head = convertArrToLL(arr);

    Node* temp = head;
    Node* join = nullptr;

    int index = 0;

    while(temp->next != NULL) // move to last node, not to nullptr out of scope
    {
        if(index == pos)
        {
            join = temp;
        }
        index++;
        temp = temp->next;
    }

    if(index == pos) join = temp;

    temp->next = join;

    return head;
}

int countNodesinLoopMap(Node* head)
{
    int count=1;
    Node* temp = head;
    unordered_map<Node*, int> mpp;

    while(temp != NULL)
    {
        if(mpp.find(temp) != mpp.end())
        {
            Node* countNode = temp->next;
            while(countNode != temp)
            {
                count++;
                countNode = countNode->next;
            }
            return count;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return 0;
}

int countNodesinLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast)
        {
            int count = 1;
            Node* temp = slow->next;

            while(temp != slow)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    return 0;
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

    Node* head = formRotatedLL(arr, pos);

    //Node::printLL(head);

    int result = countNodesinLoop(head);

    cout<<result<<endl;

    int map_ans = countNodesinLoopMap(head);

    cout<<map_ans<<endl;

    return 0;
}

// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)


