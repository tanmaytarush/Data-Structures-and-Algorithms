/*
QUESTION:- 
Construct the linked list from arr and return the head of the linked list.

Example 1:

Input:
n = 5
arr = [1,2,3,4,5]
Output:
1 2 3 4 5
Explanation: Linked list for the given array will be 1->2->3->4->5.
Example 2:

Input:
n = 2
arr = [2,4]
Output:
2 4
Explanation: Linked list for the given array will be 2->4.

APPROACH:- 
The approach to construct a linked list from an array is as follows:

1. Create the head node of the linked list using the first element of the array.
2. Initialize a current pointer to the head node.
3. Traverse the array starting from the second element.
4. For each element in the array, create a new node and assign the element as its data.
5. Set the `next` pointer of the current node to the newly created node.
6. Update the current pointer to the newly created node.
7. Repeat steps 4-6 until all elements in the array are processed.
8. Return the head node of the constructed linked list.

CODE:-
*/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Node     // declaration of a linkedlist 
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

int main()
{
    // create a new array
    vector<int> arr = {2, 4, 6, 8};

    // creating a new node
    Node* y = new Node(arr[0]);

    // printing the memory location of the Node
    cout<<y<<endl;

    // printing the data in the memory location
    cout<<y->data<<endl;
}



/*
TIME COMPLEXITY:- O(n)
SPACE COMPLEXITY:- O(n)
*/