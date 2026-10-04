/*
QUESTION:
Given an array of integers arr, replace each element with its rank.

APPROACH:
To assign ranks to the elements in the array, we can use a min-heap (priority queue) to sort the elements in ascending order along with their indices.
1. Create a min-heap to store pairs of (element, index) in ascending order.
2. Push each element along with its index into the min-heap.
3. Initialize the rank as 0 and the previous element as INT_MIN (an arbitrary value that never matches any element).
4. While the min-heap is not empty, extract the minimum element from the min-heap.
5. If the current element is different from the previous element, increment the rank.
6. Assign the rank to the element at its corresponding index in the result array.
7. Repeat steps 4-6 until all elements are processed.

The arrayRankTransform function implements this approach. It uses a min-heap to assign ranks to the elements in the array.

TIME COMPLEXITY:
The time complexity of the arrayRankTransform function is O(N log N), where N is the size of the array. Inserting elements into the min-heap and extracting the minimum element take O(log N) time, and we do this for N elements. The overall time complexity is dominated by the heap operations.

SPACE COMPLEXITY:
The space complexity is O(N) as we need to store N elements in the min-heap and the result array.

⸻

QUESTION:

Given an array of integers arr, replace each element with its rank.

The rank represents the position of the element in the sorted unique order of the array.

Rules:

1. Rank starts from 1.
2. If two elements are equal, they receive the same rank.
3. Rank should be as small as possible.
4. Larger elements receive larger ranks.

Return the transformed array after replacing each element with its rank.

⸻

INPUT FORMAT:

First line contains an integer N
→ Size of the array
Second line contains N space-separated integers
→ Elements of the array

⸻

OUTPUT FORMAT:

Print N space-separated integers representing
the rank of each element in the original order.

⸻

CONSTRAINTS:

1 ≤ N ≤ 10^5
-10^9 ≤ arr[i] ≤ 10^9

⸻

EXAMPLE 1:

Input:

5
40 10 20 30 20

Explanation:

Unique sorted elements:

10 20 30 40

Ranks:

10 → 1
20 → 2
30 → 3
40 → 4

Transform array:

40 → 4
10 → 1
20 → 2
30 → 3
20 → 2

Output:

4 1 2 3 2

⸻

EXAMPLE 2:

Input:

4
100 100 100 100

Explanation:

Only one unique element exists.

100 → Rank 1

Output:

1 1 1 1

⸻

EXAMPLE 3:

Input:

6
37 12 28 9 100 56

Sorted unique elements:

9 12 28 37 56 100

Ranks:

9 → 1
12 → 2
28 → 3
37 → 4
56 → 5
100 → 6

Output:

4 2 3 1 6 5

⸻

EXAMPLE 4:

Input:

7
20 15 20 30 10 15 40

Sorted unique elements:

10 15 20 30 40

Ranks:

10 → 1
15 → 2
20 → 3
30 → 4
40 → 5

Output array:

3 2 3 4 1 2 5

Output:

3 2 3 4 1 2 5

⸻

APPROACH:

Use a min-heap (priority queue) to store:

(element, original_index)

Process elements in ascending order:

1. Insert all elements with their indices into the min-heap.
2. Pop smallest element repeatedly.
3. If current value differs from previous value:
    * Increase rank.
4. Store rank at original index.
5. Return transformed array.

⸻

TIME COMPLEXITY:

Heap insertion  : O(N log N)
Heap extraction : O(N log N)
Overall         : O(N log N)

⸻

SPACE COMPLEXITY:

Min Heap : O(N)
Result Array : O(N)
Overall : O(N)

This matches the Leetcode problem Rank Transform of an Array and fits well with your heap-based implementation.
*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Solution
{
    public:
    vector<int> arrangeByRank(vector<int> &arr)
    {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<n; ++i)
        {
            pq.push(arr[i]);
        }

        unordered_map<int, int> rankMap;
        int rank = 1;

        while(!pq.empty())
        {
            int top = pq.top();
            if(rankMap.find(top) == rankMap.end())
            {
                rankMap[top] = rank++;
            }
            pq.pop();
        }

        vector<int> ans;
        for(auto it : arr)
        {
            ans.push_back(rankMap[it]);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    vector<int> answer = sol.arrangeByRank(arr);

    for(vector<int>::iterator it = answer.begin(); it != answer.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}
