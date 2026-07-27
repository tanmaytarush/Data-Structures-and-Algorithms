/*
Reverse a linked list
*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    static void printLL(Node* head)
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
    }
};

class Solution
{
    public:
    Node* convertArrToLL(vector<int> &nums)
    {
        if(nums.empty()) return nullptr;

        int n = nums.size();
        Node* head = new Node(nums[0]);
        Node* temp = head;
        for(int i=1; i<n; i++)
        {
            temp->next = new Node(nums[i]);
            temp = temp->next;   
        }
        return head;
    }

    Node* reverseLL(Node* head)
    {
        Node* prev = nullptr;
        Node* temp = head;

        while(temp != nullptr)
        {
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }
};

int main()
{
    Solution sol;

    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }

    Node* head = sol.convertArrToLL(nums);

    Node* result = sol.reverseLL(head);

    Node::printLL(result);

    return 0;
}