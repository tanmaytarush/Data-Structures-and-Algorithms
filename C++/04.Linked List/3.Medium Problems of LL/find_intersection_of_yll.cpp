/*

Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

Examples

Example 1:

Input: List 1 = [1,3,1,2,4], List 2 = [3,2,4]
Output: 2
Explanation: Here, both lists intersecting nodes start from node 2.

Example 2:

Input: List1 = [1,2,7], List 2 = [2,8,1]
Output: Null
Explanation: Here, both lists do not intersect and thus no intersection node is present.

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>
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
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

Node* convertArrtoLL(vector<int> &arr)
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

Node* findIntersectionBruteForce(Node* head1, Node* head2)
{
    int len1 = 0;
    int len2 = 0;

    unordered_map<Node*, int> mpp;
    Node* temp1 = head1;
    while(temp1 != NULL)
    {
        mpp[temp1] = 1;
        temp1 = temp1->next;
    }

    Node* temp2 = head2;
    while(temp2 != NULL)
    {
        if(mpp.find(temp2) != mpp.end())
        {
            return temp2;
        }
        temp2 = temp2->next;
    }
    return NULL;
}

int findDifference(Node* head1, Node* head2)
{
    int len1 = 0;
    int len2 = 0;

    while(head1 != NULL)
    {
        len1++;
        head1 = head1->next;
    }

    while(head2 != NULL)
    {
        len2++;
        head2 = head2->next;
    }

    return len1 - len2;
}

Node* findIntersectionOptimal1(Node* head1, Node* head2)
{
    int diff = findDifference(head1, head2);

    if(diff<0)
    {
        while(diff++ != 0) head2 = head2->next;
    }

    else
    {
        while(diff-- != 0) head1 = head1->next;
    }

    while(head1 != head2)
    {
        if(head1 == head2)
        {
            return head1;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

Node* findIntersectionOptimal2(Node* head1, Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 != temp2)
    {
        temp1 = temp1==NULL ? head2 : temp1->next;
        temp2 = temp2==NULL ? head1 : temp2->next;
    }

    return temp1;
}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<int> arr1(n);

    for(int i=0; i<n; ++i)
    {
        cin>>arr1[i];
    }

    vector<int> arr2(m);
    for(int i=0; i<m; ++i)
    {
        cin>>arr2[i];
    }

    Node* head1 = convertArrtoLL(arr1);

    Node* head2 = convertArrtoLL(arr2);

    Node::printLL(head1);
    cout<<endl;

    Node::printLL(head2);
    cout<<endl;

    Node* result1 = findIntersectionBruteForce(head1, head2);
    cout<<result1->data<<endl;

    Node* result2 = findIntersectionOptimal1(head1, head2);
    cout<<result2->data<<endl;

    Node* result3 = findIntersectionOptimal2(head1, head2);
    cout<<result3->data<<endl;

    return 0;
}