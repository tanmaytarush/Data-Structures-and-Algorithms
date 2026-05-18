/*
QUESTION:
Given an array A of size N, the task is to check if the given array represents a Binary Max Heap.

APPROACH:
1. Start from the root node and recursively check if the current node satisfies the max-heap property.
2. The max-heap property states that every node should be greater than all of its descendants.
3. Check if the current node is greater than its left and right children.
4. Recursively check the max-heap property for the left and right subtrees.
5. If the current node is greater and the left and right subtrees also satisfy the max-heap property, then the array represents a binary max heap.

The solve function is implemented to recursively check the max-heap property for each node. It checks if the current node is greater than its left and right children. If the current node is greater and the left and right subtrees also satisfy the max-heap property, then the array represents a binary max heap.

The isMaxHeap function is the main function that calls the solve function with the root node (index 0) and the size of the array. It returns true if the array represents a binary max heap, and false otherwise.

TIME COMPLEXITY:
The time complexity of the isMaxHeap function is O(N), where N is the size of the array. This is because we need to check the max-heap property for each node in the array.

SPACE COMPLEXITY:
The space complexity is O(N) due to the recursive calls in the solve function.
*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool solve(vector<int>&arr, int index, int n)
{
    if(index > n)
    {
        return true;
    }

    int leftIndex = 2*index + 1;
    int rightIndex = 2*index + 2;

    return (leftIndex<n && rightIndex<n && (arr[index]>arr[leftIndex] && arr[index]>arr[rightIndex]));
}

bool maxHeap(vector<int>&arr, int n)
{
    return solve(arr, 0, n);
}

int main()
{
    int capacity;
    cin>>capacity;

    int size;
    cin>>size;

    vector<int> arr(size);
    for(int i=0; i<size; ++i)
    {
        cin>>arr[i];
    }

    bool result = maxHeap(arr, size);

    cout<<result<<endl;

    return 0;
}
