/*
QUESTION:
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order. Merge all the linked-lists into one sorted linked-list and return it.

APPROACH:
To merge K sorted linked lists, we can use a min-heap (priority queue) to store the smallest nodes from each list.
1. Create a min-heap of size K to store the current smallest nodes from each list.
2. Initialize the min-heap with the head node from each list.
3. While the min-heap is not empty, extract the smallest node from the min-heap, add it to the merged linked list, and replace it with the next node from the same list.
4. Repeat step 3 until all nodes from all lists are processed.

The mergeKLists function implements this approach. It uses a min-heap (priority queue) to merge K sorted linked lists into one sorted linked list.

TIME COMPLEXITY:
The time complexity of the mergeKLists function is O(N log K), where N is the total number of nodes across all lists and K is the number of linked lists. Inserting nodes into the min-heap and extracting the minimum node take O(log K) time, and we do this for N nodes. The overall time complexity is dominated by the heap operations.

SPACE COMPLEXITY:
The space complexity is O(K) as we need to store K nodes in the min-heap.
*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }    

    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }

    static void print(Node* head)
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

class compare
{
    public:
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};

class Solution
{
    public:
    Node* mergeKSortedLists(vector<Node*> &lists)
    {
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        int k = lists.size();

        for(int i=0; i<k; ++i)
        {
            if(lists[i] != NULL)
            {
                minHeap.push(lists[i]);
            }
        }

        Node* head = NULL;
        Node* tail = NULL;

        while(minHeap.size() > 0)
        {
            Node* top = minHeap.top();
            minHeap.pop();

            if(top->next != NULL)
            {
                minHeap.push(top->next);
            }

            if(head == NULL)
            {
                head = top;
                tail = top;
            }

            else
            {
                tail->next = top;
                tail = tail->next;
            }
        }
        return head;
    }
};

int main()
{

    Node* a = new Node(1, new Node(4, new Node(5)));
    Node* b = new Node(1, new Node(3, new Node(4)));
    Node* c = new Node(2, new Node(6));

    vector<Node*> lists = {a, b, c};
    Solution solver;
    Node* merged = solver.mergeKSortedLists(lists);

    cout<<"Merged List : "<<endl;
    Node::print(merged);

    return 0;
}
