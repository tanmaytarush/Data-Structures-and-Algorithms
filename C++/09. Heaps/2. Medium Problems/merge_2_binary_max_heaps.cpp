/*

Merge Two Binary Max Heaps
Last Updated : 23 Jul, 2025

Given two binary max heaps, the task is to merge the given heaps to form a new max heap.

Examples : 

Input: a[] = {10, 5, 6, 2}, b[] = {12, 7, 9}
Output: {12, 10, 9, 2, 5, 7, 6}

Merge-two-max-heaps-(1)
Merge Two Binary Max Heaps
Input: a[] = {2, 5, 1, 9, 12}, b[] = {3, 7, 4, 10}
Output: {12, 10, 7, 9, 5, 3, 1, 4, 2}

Table of Content

[Naive Approach] Using Max Heap - O((N + M)*log(N + M)) Time and O(N + M) Space:
[Expected Approach] Merge and Build Heap- O(N + M) Time and O(N + M) Space:
[Naive Approach] Merge using extra Max Heap - O((N + M)*log(N + M)) Time and O(N + M) Space:
The property of Max Heap is that the top of any Max Heap is always the largest element. We will use this property to merge the given binary Max Heaps.

To do this:

Create another Max Heap, and insert the elements of given binary max heaps into this one by one.
Now repeat above step until all the elements from both given Max Heaps are merged into the third one, ensuring the property of largest element on top (max heapify).
The third Max Heap will be the required merged Binary Max Heap.


INTUITION :-

1.  There are two input arrays nums1 and nums2 provided as the foundation.
2.  We need to merge the two arrays in the same order.
3.  Once merging is done, then further perform heapify for the answer array.

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

void heapify(vector<int>&arr, int size, int index)
{
    int left = 2*index+1;
    int right = 2*index+2;
    int largest = index;

    if(left < size && arr[largest] < arr[left])
    {
        largest = left;
    }

    if(right < size && arr[largest] < arr[right])
    {
        largest = right;
    }

    if(largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest);
    }
}

vector<int> mergeHeaps(vector<int>&arr1, vector<int>&arr2, int n, int m)
{
    vector<int> ans;
    for(auto it : arr1)
    {
        ans.push_back(it);
    }

    for(auto it : arr2){
        ans.push_back(it);
    }

    // heapify on ans
    int size = ans.size();
    for(int i=(size/2 - 1); i>=0; --i)
    {
        heapify(ans, size, i);
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<int> nums1(n);
    for(int i=0; i<n; ++i){
        cin>>nums1[i];
    }

    int m;
    cin>>m;

    vector<int> nums2(m);
    for(int i=0; i<m; ++i)
    {
        cin>>nums2[i];
    }

    vector<int> answer = mergeHeaps(nums1, nums2, n, m);

    for(vector<int>::iterator it = answer.begin(); it != answer.end(); ++it)
    {
        cout<<*it<<" ";
    }

    return 0;
}