/*

You are given a circular array nums and an array queries.

For each query i, you have to find the following:

The minimum distance between the element at index queries[i] and any other index j in the circular array, where nums[j] == nums[queries[i]]. If no such index exists, the answer for that query should be -1.
Return an array answer of the same size as queries, where answer[i] represents the result for query i.

 

Example 1:

Input: nums = [1,3,1,4,1,3,2], queries = [0,3,5]

Output: [2,-1,3]

Explanation:

Query 0: The element at queries[0] = 0 is nums[0] = 1. The nearest index with the same value is 2, and the distance between them is 2.
Query 1: The element at queries[1] = 3 is nums[3] = 4. No other index contains 4, so the result is -1.
Query 2: The element at queries[2] = 5 is nums[5] = 3. The nearest index with the same value is 1, and the distance between them is 3 (following the circular path: 5 -> 6 -> 0 -> 1).
Example 2:

Input: nums = [1,2,3,4], queries = [0,1,2,3]

Output: [-1,-1,-1,-1]

Explanation:

Each value in nums is unique, so no index shares the same value as the queried element. This results in -1 for all queries.

 

Constraints:

1 <= queries.length <= nums.length <= 105
1 <= nums[i] <= 106
0 <= queries[i] < nums.length

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;

#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution
{
    public:
    vector<int> minElementQueriesBF(vector<int> &arr, vector<int> &queries)
    {
        int n = arr.size();
        int m = queries.size();
        vector<int> result;

        for(int q : queries)
        {
            int dist = n+1;
            int ans = n+1;

            for(int i=0; i<n; ++i)
            {
                if(arr[i] == arr[q] && i != q)
                {
                    dist = abs(i - q);
                    ans = min(ans, min(dist, abs(n - dist)));
                }
            }

            result.push_back(ans > n ? -1 : ans);
        }
        return result; 
    }


    /*

    OPTIMIZED APPROACH :-
            
    Full Dry Run: `nums = [1,3,1,4,1,3,2]`, `queries = [0,3,5]`

        n = 7, m = 3

        ---

        ### Phase 1 — Build Position Map

        ```
        numsPos[1] = [0, 2, 4]
        numsPos[3] = [1, 5]
        numsPos[4] = [3]
        numsPos[2] = [6]
        ```

        ---

        ### Phase 2 — Pad Each List

        For every value, prepend `last - n` and append `first + n`:

        | Value | Real positions | ghost_L | ghost_R | Padded list |
        |-------|---------------|---------|---------|-------------|
        | 1 | [0, 2, 4] | 4−7 = **−3** | 0+7 = **7** | [**−3**, 0, 2, 4, **7**] |
        | 3 | [1, 5] | 5−7 = **−2** | 1+7 = **8** | [**−2**, 1, 5, **8**] |
        | 4 | [3] | 3−7 = **−4** | 3+7 = **10** | [**−4**, 3, **10**] |
        | 2 | [6] | 6−7 = **−1** | 6+7 = **13** | [**−1**, 6, **13**] |

        ---

        ### Phase 3 — Answer Each Query

        ---

        **Query 0** → index `0`, value `nums[0] = 1`

        Padded list for `1`: `[-3, 0, 2, 4, 7]`, size = 5 ≠ 3 → not unique

        `lower_bound` for `0` → **pos = 1**

        ```
                pos-1  pos  pos+1
                [-3,   0,   2,  4, 7]
                        ↑
        left  gap:  0 − (−3) = 3
        right gap:  2 −   0  = 2
        answer = min(3, 2) = 2 ✓
        ```

        Visually on the circle: `0 → 1 → 2` = 2 steps right, `0 → 6 → ... → 4` = 3 steps left.

        ---

        **Query 1** → index `3`, value `nums[3] = 4`

        Padded list for `4`: `[-4, 3, 10]`, **size = 3** → only 1 real occurrence

        ```
        answer = -1 ✓
        ```

        ---

        **Query 2** → index `5`, value `nums[5] = 3`

        Padded list for `3`: `[-2, 1, 5, 8]`, size = 4 ≠ 3 → not unique

        `lower_bound` for `5` → **pos = 2**

        ```
                pos-1  pos  pos+1
                [-2,   1,   5,   8]
                            ↑
        left  gap:  5 −  1  = 4
        right gap:  8 −  5  = 3
        answer = min(4, 3) = 3 ✓
        ```

        Visually on the circle: `5 → 6 → 0 → 1` = 3 steps clockwise, `5 → 4 → 3 → 2 → 1` = 4 steps counter-clockwise.

        ---

        ### Final Output

        ```
        queries = [2, -1, 3] ✓
        ```

        ---

        ### Why the Ghost Indices Work

        The key insight is that the **ghost indices encode wrap-around distances as plain subtraction**:

        ```
        ghost_L = last_pos - n   →  "where last occurrence would be in the previous copy"
        ghost_R = first_pos + n  →  "where first occurrence would be in the next copy"

        Circular distance  =  min(forward linear gap, backward linear gap)
                        =  min(pos[i+1] - pos[i], pos[i] - pos[i-1])
                            with ghost neighbours absorbing the wrap
        ```

        No `% n` needed anywhere — the padding converts a circular problem into a linear one.

    */

    vector<int> minElementQueriesOpt(vector<int> &arr, vector<int> &queries)
    {
        int n = arr.size();
        int m = queries.size();
        
        unordered_map<int, vector<int>> numPos;
        for(int i=0; i<n; ++i) // add array of elements with their positions in a map
        {
            numPos[arr[i]].push_back(i);
        }

        for(auto &[_, pos] : numPos) // adding all possible index poinsts for an element
        {
            int x = pos[0];
            pos.insert(pos.begin(), pos.back()-n); // entering last index - n to the beginning
            pos.push_back(x + n); // adding x+n to the end
        }

        for(int i=0; i<m; ++i)
        {
            int x = arr[queries[i]];
            if(numPos[x].size() == 3)
            {
                queries[i] = -1;
                continue;
            }

            int pos = lower_bound(numPos[x].begin(), numPos[x].end(), queries[i]) - numPos[x].begin();
            queries[i] = min(numPos[x][pos+1] - numPos[x][pos], numPos[x][pos] - numPos[x][pos-1]);
        }

        return queries;
    }
};

int main()
{
    Solution sol;
    
    int n, m;
    cin>>n>>m;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    vector<int> queries(m);
    for(int i=0; i<m; ++i)
    {
        cin>>queries[i];
    }

    vector<int> result1 = sol.minElementQueriesBF(arr, queries);
    
    for(vector<int>::iterator it = result1.begin(); it!=result1.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    vector<int> result2 = sol.minElementQueriesOpt(arr, queries);
    
    for(vector<int>::iterator it = result2.begin(); it!=result2.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;


    return 0;
}