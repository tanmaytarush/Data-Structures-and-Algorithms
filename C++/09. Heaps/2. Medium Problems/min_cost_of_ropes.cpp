/*

Minimum Cost of ropes
Difficulty: MediumAccuracy: 42.73%Submissions: 279K+Points: 4

Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. 

Examples:

Input: arr[] = [4, 3, 2, 6]
Output: 29
Explanation: First connect 2 and 3 to get [4, 5, 6] with a cost of 5, then connect 4 and 5 to get [9, 6] with a cost of 9, and finally connect 9 and 6 to get one rope with a cost of 15, giving a total minimum cost of 29. Any other order, such as connecting 4 and 6 first, results in a higher total cost of 38.
Input: arr[] = [4, 2, 7, 6, 9]
Output: 62 
Explanation: First, connect ropes 4 and 2, which makes the array [6, 7, 6, 9]. Cost of this operation 4 + 2 = 6. Next, add ropes 6 and 6, which results in [12, 7, 9]. Cost of this operation 6 + 6 = 12. Then, add 7 and 9, which makes the array [12,16]. Cost of this operation 7 + 9 = 16. And finally, add these two which gives [28]. Hence, the total cost is 6 + 12 + 16 + 28 = 62.
Input: arr[] = [10]
Output: 0
Explanation: Since there is only one rope, no connections are needed, so the cost is 0.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104


INTUITION:-

1.  Consider an array of rope lengths provided as input.
2.  We need to add two minimum elements and get the cost until size==1.
3.  We declare a min-heap priority_queue and get top 2 min elements and add it to cost.
4.  This goes on until we reach the final element in the input array.

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;

long long minCost(vector<long long> nums)
{
    int n = nums.size();
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for(int i=0; i<n; ++i)
    {
        pq.push(nums[i]);
    }

    long long cost = 0;
    while(pq.size() > 1) 
    {
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        long long sum = a + b;
        cost += sum;

        pq.push(sum);
    }

    return cost;
}

int main()
{
    int n;
    cin>>n; 

    vector<long long> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    long long ans = minCost(arr);

    cout<<ans<<endl;

    return 0;
}