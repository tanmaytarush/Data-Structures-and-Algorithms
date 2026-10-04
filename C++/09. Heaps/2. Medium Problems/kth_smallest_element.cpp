/*
QUESTION:
Given an array arr[] and an integer K, where K is smaller than the size of the array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

APPROACH:
To find the Kth smallest element in the array, we can use a max-heap of size K.
1. Initialize a max-heap (priority queue) of size K.
2. Insert the first K elements of the array into the max-heap.
3. For the remaining elements in the array, if an element is smaller than the top element of the max-heap, replace the top element with the current element and heapify to maintain the max-heap property.
4. After processing all the elements, the top element of the max-heap will be the Kth smallest element in the array.

The findKthLargest function implements this approach. It uses a max-heap (priority queue) to find the Kth smallest element in the array without sorting the entire array.

TIME COMPLEXITY:
The time complexity of the findKthLargest function is O(N log K), where N is the size of the array. Inserting elements into the max-heap and heapifying take O(log K) time, and we do this for N-K elements. The overall time complexity is dominated by the heap operations.

SPACE COMPLEXITY:
The space complexity is O(K) as we need to store K elements in the max-heap.
*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<queue>
using namespace std;

int kthSmallestElement(vector<int>&arr, int l, int r, int k)
{
    int n = arr.size();

    // max-heap by default
    priority_queue<int> pq;

    // Step-1 -> Push first k elements in the given max-heap
    for(int i=0; i<k; ++i)
    {
        pq.push(arr[i]);
    }

    // Step-2 -> Push remaining by checking if curr_element < pq.top(), then pq.pop() 
    // and later pq.push(curr_element)
    for(int i=k; i<=r; ++i)
    {
        if(arr[i]<pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
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

    int result = kthSmallestElement(arr, 0, n-1, k);

    cout<<result<<endl;

    return 0;
}
