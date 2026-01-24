/*
Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in the doubly linked list whose sum is equal to a given value `target`.

Example 1:
Input:  
1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
Target: 7
Output: (1, 6), (2, 5)
Explanation: We can see that there are two pairs (1, 6) and (2, 5) with a sum of 7.

Example 2:
Input: 
1 <-> 5 <-> 6
Target: 6
Output: (1, 5)
Explanation: We can see that there is one pair (1, 5) with a sum of 6.

Approach:
1. Initialize two pointers, `start` and `end`, pointing to the beginning and end of the doubly linked list, respectively.
2. While the `start` pointer's data is less than the `end` pointer's data:
   - Calculate the sum of the data at the `start` and `end` pointers.
   - If the sum is equal to the target value, add the pair (start->data, end->data) to the result vector and move both the `start` and `end` pointers.
   - If the sum is less than the target value, move the `start` pointer to the next node.
   - If the sum is greater than the target value, move the `end` pointer to the previous node.
3. Return the result vector containing all the pairs whose sum is equal to the target.

Time Complexity: O(N), where N is the number of nodes in the doubly linked list.
Space Complexity: O(1).

CODE:
*/

#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
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
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

Node* convertArrToDLL(vector<int> &arr)
{
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* curr = head;
    Node* last = curr;

    for(int i=1; i<n; ++i)
    {
        curr = new Node(arr[i]);
        curr->prev = head;
        last->next = curr;
        last = curr;
    }

    return head;
}

vector<pair<int, int>> pairSumBF(Node* head, int sum)    // O(N^2)
{
    Node* temp1 = head;
    vector<pair<int, int>> ans;

    while(temp1 != NULL)
    {
        Node* temp2 = temp1->next;
        while((temp2 != NULL) && (temp1->data + temp2->data <= sum))
        {
            if(temp1->data + temp2->data == sum)
            {
                ans.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return ans;
}

Node* calculateTail(Node* head)
{
    Node* tail = head;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    return tail;
}

vector<pair<int, int>> pairSumOpt(Node* head, int sum)
{
    vector<pair<int, int>> ans;

    Node* left = head;
    Node* right = calculateTail(head);

    while(left->data < right->data)
    {
        if(left->data + right->data < sum)
        {
            left = left->next;
        }
        else if(left->data + right->data > sum)
        {
            right = right->prev;
        }
        else
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
    }
    return ans;
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

    int sum;
    cin>>sum;

    Node* head = convertArrToDLL(arr);
    Node::printLL(head);
    cout<<endl;

    vector<pair<int, int>> ans1 = pairSumBF(head, sum);
    for(auto it : ans1)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }

    cout<<"Optimized : "<<endl;
    
    vector<pair<int, int>> ans2 = pairSumOpt(head, sum);
    for(vector<pair<int, int>>::iterator it = ans1.begin(); it != ans1.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    return 0;
}