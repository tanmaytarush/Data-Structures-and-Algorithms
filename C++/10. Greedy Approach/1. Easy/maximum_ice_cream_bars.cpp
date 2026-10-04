/*

Counting Sort
Last Updated : 29 Sep, 2025
Counting Sort is a non-comparison-based sorting algorithm. It is particularly efficient when the range of input values is small compared to the number of elements to be sorted.

The basic idea behind Counting Sort is to count the frequency of each distinct element in the input array and use that information to place the elements in their correct sorted positions.
It works well when the range of input elements is small and comparable to the size of the array. For example, for input [1, 4, 0, 2, 1, 1], the size of array is 6 and range of elements is from 0 to 4
If range of input array is of order more than n Log n where n is size of the array, then we can better sort the array using a standard comparison based sorting algorithm like Merge Sort.
Counting Sort Algorithm
Declare a count array cntArr[] of size max(arr[])+1 and initialize it with 0.
Traverse input array arr[] and map each element of arr[] as an index of cntArr[] array, i.e., execute cntArr[arr[i]]++ for 0 <= i < N.
Calculate the prefix sum at every index of cntArr[].
Create an array ans[] of size N.
Traverse array arr[] from end and update ans[ cntArr[ arr[i] ] - 1] = arr[i]. Also, update cntArr[ arr[i] ] = cntArr[ arr[i] ]- - .
Why do we compute Prefix Sums?
We could simply count occurrences of all elements and one by one put them in the output array, but we computer prefix sums to achieve stability in the algorithm. Note that, after building the prefix sum cntArr[], we traverse the array from right end to ensure that the last occurrence moves to the last correct position in the sorted array.

Working of Counting Sort
Counting-Sort--10.webpCounting-Sort--10.webp
Try It Yourself
redirect icon



#include <iostream>
#include <vector>
using namespace std;
​
vector<int> countsort(vector<int>& arr) {
    int n = arr.size();
​
    // find the maximum element
    int maxval = 0;
    for (int i = 0; i < n; i++)
        maxval = max(maxval, arr[i]);
​
    // create and initialize cntArr array
    vector<int> cntArr(maxval + 1, 0);
​
    // count frequency of each element
    for (int i = 0; i < n; i++)
        cntArr[arr[i]]++;
​
    // compute prefix sum
    for (int i = 1; i <= maxval; i++)
        cntArr[i] += cntArr[i - 1];
​
    // build output array
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[cntArr[arr[i]] - 1] = arr[i];
        cntArr[arr[i]]--;
    }
​
    return ans;
}
​
int main() {
    vector<int> arr = {2,5,3,0,2,3,0,3};
    vector<int> ans = countsort(arr);
​
    for (int x : ans)
        cout << x << " ";
​
    return 0;
}

Output
0 0 2 2 3 3 3 5 
Complexity Analysis of Counting Sort:
Time Complexity: O(N+M) in all cases, where N and M are the size of inputArray[] and countArray[] respectively.
Auxiliary Space: O(N+M), where N and M are the space taken by outputArray[] and countArray[] respectively.
Advantage, of Counting Sort:
Counting sort generally performs faster than all comparison-based sorting algorithms, such as merge sort and quicksort, if the range of input is of the order of the number of input.
Stable Algorithm
Disadvantage of Counting Sort:
Does not work on decimal values.
Inefficient if the range of values to be sorted is very large.
Not an In-place sorting algorithm, It uses extra space for sorting the array elements.
Applications of Counting Sort:
It is a commonly used algorithm for the cases where we have limited range items. For example, sort students by grades, sort a events by time, days, months, years, etc
It is used as a subroutine in Radix Sort
The idea of counting sort is used in Bucket Sort to divide elements into different buckets.



PROBLEM :-

It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

Note: The boy can buy the ice cream bars in any order.

Return the maximum number of ice cream bars the boy can buy with coins coins.

You must solve the problem by counting sort.

 

Example 1:

Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
Example 2:

Input: costs = [10,6,8,7,7,8], coins = 5
Output: 0
Explanation: The boy cannot afford any of the ice cream bars.
Example 3:

Input: costs = [1,6,3,1,2,5], coins = 20
Output: 6
Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.
 

Constraints:

costs.length == n
1 <= n <= 105
1 <= costs[i] <= 105
1 <= coins <= 108

*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

class Solution
{
    public:
    vector<int> countSort(vector<int>&arr)
    {
        int n = arr.size();
        int maxVal = INT_MIN;

        // get maximum from the input array
        for(int i=0; i<n; ++i)
        {
            maxVal = max(maxVal, arr[i]);
        }

        vector<int> cntArr(maxVal+1, 0);
        // get frequency of each element stored
        for(int i=0; i<n; ++i)
        {
            cntArr[arr[i]]++; 
        }

        // get prefixSum of all cntArr elements
        for(int i=1; i<=maxVal; ++i)
        {
            cntArr[i] = cntArr[i] + cntArr[i-1];
        }

        // get the final sorted structure
        vector<int> ans(n);
        for(int i=n-1; i>=0; --i)
        {
            ans[cntArr[arr[i]] - 1] = arr[i];
            cntArr[arr[i]]--;
        }
        return ans;
    }

    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();

        vector<int> sortedCosts = countSort(costs);
        int count = 0;

        int i=0;
        while(i<n && coins>=0)
        {
            if(sortedCosts[i] <= coins)
            {
                count+=1;
                coins -= sortedCosts[i];
            }
            i++;
        }

        return count;
    }
};


int main()
{
    Solution sol;
    int n;
    cin>>n;

    vector<int> costs(n);
    for(int i=0; i<n; ++i)
    {
        cin>>costs[i];
    }

    int coins;
    cin>>coins;

    int totalIcecreams = sol.maxIceCream(costs, coins);

    cout<<totalIcecreams<<endl;

    return 0;
}