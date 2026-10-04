/*
QUESTION:
Given K sorted arrays arranged in the form of a matrix of size K*K, the task is to merge them into one sorted array.

APPROACH:
To merge K sorted arrays, we can use a min-heap (priority queue) to store the smallest elements from each array.
1. Create a min-heap of size K to store the current smallest elements from each array.
2. Initialize the min-heap with the first element from each array.
3. While the min-heap is not empty, extract the smallest element from the min-heap, add it to the merged array, and replace it with the next element from the same array.
4. Repeat step 3 until all elements from all arrays are processed.

The mergeKArrays function implements this approach. It uses a min-heap (priority queue) to merge K sorted arrays into one sorted array.

TIME COMPLEXITY:
The time complexity of the mergeKArrays function is O(K^2 log K), where K is the size of each array. Inserting elements into the min-heap and extracting the minimum element take O(log K) time, and we do this for K^2 elements. The overall time complexity is dominated by the heap operations.

SPACE COMPLEXITY:
The space complexity is O(K) as we need to store K elements in the min-heap.

INTUITION:-

1. Create a min-heap of size K to store the current smallest elements from each array.
2. Initialize the min-heap with the first element from each array.
3. While the min-heap is not empty, extract the smallest element from the min-heap, add it to the merged array, and replace it with the next element from the same array.
4. Repeat step 3 until all elements from all arrays are processed.

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
#include<algorithm>
using namespace std;

class node
{
    public:
    int data;
    int i;
    int j;

    node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};

class compare
{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare> pq;

    // put first element of all k-arrays into the heap
    for(int i=0; i<k; ++i)
    {
        node* tmp = new node(kArrays[i][0], i, 0);
        pq.push(tmp);
    }

    // compare and put in the resultant array
    vector<int> ans;
    while(pq.size() > 0)
    {
        node* tmp = pq.top();
        ans.push_back(tmp->data);
        pq.pop();

        int i = tmp->i;
        int j = tmp->j;

        if(j+1 < kArrays.size())
        {
            node* next = new node(kArrays[i][j+1], i, j+1);
            pq.push(next);
        }
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;

    int m;
    cin>>m;

    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cin>>arr[i][j];
        }
    }

    int k;
    cin>>k;

    vector<int> answer = mergeKSortedArrays(arr, k);

    for(vector<int>::iterator it = answer.begin(); it!=answer.end(); ++it)
    {
        cout<<*it<<" ";
    }

    return 0;
}
