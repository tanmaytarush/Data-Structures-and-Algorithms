/*

Problem statement
Given an array of integers, find the Kth largest sum subarray For example, given the array [1, -2, 3, -4, 5] and K = 2, the 2nd largest sum subarray would be [3, -4, 5], which has a sum of 4.

Please note that a subarray is the sequence of consecutive elements of the array.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
2
3 3
3 -2 5
2 2
4 1
Sample output 1 :
3
4
Explanation of Sample output 1 :
For the first test case, 
Sum of [0, 0] = 3
Sum of [0, 1] = 1
Sum of [0, 2] = 6
Sum of [1, 1] = -2
Sum of [1, 2] = 3
Sum of [2, 2] = 5
All sum of subarrays are {6, 5, 3, 3, 1, -2} where the third largest element is 3.

For the second test case, 
Sum of [0, 0] = 4
Sum of [0, 1] = 5
Sum of [1, 1] = 1
All sum of subarrays are {5, 4, 1} where the second largest element is 4.
Sample Input 2 :
2
4 10
5 4 -8 6
3 1
1 2 3
Sample output 2 :
-8
6
Explanation of Sample output 2 :
For the first test case, among the sum of all the subarray, the tenth-largest sum will be -8.

For the second test case, among the sum of all the subarray, the largest sum will be 6.


INTUITION :-

1.  First generate all the subarrays.
2.  While the subarrays were generated, move further and declare a min-heap which will
    contain the subarrays sums for first k nodes.
3.  Since it is a min-heap, we get the kth largest at the top of the heap. Suppose k=4,
    so in the descending order the kth largest sum will be at the top.
4.  Finally, we keep poping and pushing if any sum found is greater than heap.top().

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;

int kthLargestSum(vector<int> &nums, int k)
{
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<n; ++i)
    {
        int sum = 0;
        for(int j=i; j<n; ++j)
        {
            sum += nums[j];

            if(pq.size() < k)
            {
                pq.push(sum);
            }   
            else
            {
                if(sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
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

    int result = kthLargestSum(arr, k);

    cout<<result<<endl;

    return 0;
}