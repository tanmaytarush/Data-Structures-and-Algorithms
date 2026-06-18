/*
Question:
Given two integer arrays A and B of size N each. A sum combination is made by adding one element from array A and another element from array B. Return the maximum K valid distinct sum combinations from all the possible sum combinations. Output array must be sorted in non-increasing order.

Example:
Input:
N = 2
K = 2
A[] = {3, 2}
B[] = {1, 4}
Output: {7, 6}
Explanation: 
7 -> (A: 3) + (B: 4)
6 -> (A: 2) + (B: 4)
*/

/*
Approach:
1. Sort arrays A and B in non-increasing order.
2. Initialize a min-heap (priority_queue) to store the sum combinations.
3. Iterate over each element in array A.
4. For each element in A, iterate over each element in array B.
5. Calculate the sum of the current pair (A[i] + B[j]).
6. If the heap size is less than K, push the sum into the heap.
7. If the heap size is already K and the current sum is greater than the smallest element in the heap, pop the smallest element and push the current sum into the heap.
8. After iterating over all elements, the heap will contain the K maximum valid sum combinations in non-increasing order.
9. Store the elements of the heap in a vector and return it as the result.

COMPLEXITY ANALYSIS:-
TIME COMPLEXITY - 
Sorting the arrays A and B takes O(N log N) time.
Building the max heap takes O(N) time.
Extracting the maximum sum K times takes O(K log N) time.
Overall, the time complexity of the solution is O(N log N + K log N).
CODE:-
*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    vector<int> maxSumCombinationBF(vector<int> &nums1, vector<int> &nums2, int k, int n)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> allSums;
        vector<int> ans;

        for(int i=0; i<n; ++i)
        {
            for(int j=i; j<n; ++j)
            {
                allSums.push_back(nums1[i] + nums2[j]);
            }
        } // O(n2)

        for(int &num : allSums)
        {
            pq.push(num);

            if(pq.size() > k)
            {
                pq.pop();
            }
        } // O(n)

        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        } // O(n)

        return ans;
    }

    vector<int> maxSumCombinationOpt(vector<int> &A, vector<int> &B, int K, int N)
    {
        sort(A.rbegin(), A.rend()); // O(n log(n))
        sort(B.rbegin(), B.rend()); // O(n log(n))

        priority_queue<tuple<int, int, int>> pq;
        set<pair<int, int>> vis;

        pq.push({A[0] + B[0], 0, 0});
        vis.insert({0, 0});

        vector<int> ans;

        while(K-- && !pq.empty()) // O(n)
        {
            auto [sum, i, j] = pq.top();
            pq.pop();
            ans.push_back(sum);

            if(i+1<N && !vis.count({i+1, j}))
            {
                pq.push({A[i+1] + B[j], i+1, j});
                vis.insert({i+1, j});
            }

            if(j+1<N && !vis.count({i, j+1}))
            {
                pq.push({A[i] + B[j+1], i, j+1});
                vis.insert({i, j+1});
            }
        }

        return ans;
    }
};


int main()
{
    Solution sol;
    int n;
    cin>>n;

    vector<int> nums1(n);
    for(int i=0; i<n; ++i)
    {
        cin>>nums1[i];
    }

    vector<int> nums2(n);
    for(int i=0; i<n; ++i)
    {
        cin>>nums2[i];
    }

    int k;
    cin>>k;

    vector<int> answerbf = sol.maxSumCombinationBF(nums1, nums2, k, n);
    reverse(answerbf.begin(), answerbf.end());

    for(vector<int>::iterator it = answerbf.begin(); it != answerbf.end(); ++it)
    {
        cout<<*it<<" ";
    }

    cout<<endl;

    vector<int> answeropt = sol.maxSumCombinationOpt(nums1, nums2, k, n);

    for(vector<int>::iterator it = answeropt.begin(); it != answeropt.end(); ++it)
    {
        cout<<*it<<" ";
    }

    return 0;
}
