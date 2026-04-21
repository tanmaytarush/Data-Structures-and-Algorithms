/*
QUESTION:
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
return the area of the largest rectangle in the histogram.

Example:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where the width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
*/

/*
APPROACH:
To find the largest rectangle area, we can use the concept of a stack.
The idea is to maintain a stack of indices of the heights in non-decreasing order.
For each height, we compare it with the top of the stack.
If the current height is greater than the top of the stack, we push its index onto the stack.
Otherwise, we keep popping elements from the stack and calculate the area using the popped index as the right boundary.
The left boundary can be obtained from the new top of the stack.
By doing this, we ensure that the heights in the stack are always in non-decreasing order.
Finally, we calculate the area for each popped element and update the maximum area found so far.
*/

/*

INTUITION BRUTE FORCE :-

1. Consider an example case, in which a heights array is provided as follows [2,1,5,6,2,3]. First of all,
   we need to figure out the NSE (Next Smaller Element) and PSE(Previous Smaller Element) for each element.

2. Now, since we know the indexes for NSE and PSE, then in that case, the area can be traced out as the 
   area = arr[i] * (nse - pse - 1).

3. The maximum area out of all the combinations can be traced out the answer.

4. Time Complexity -> O(3N) and Space Complexity -> O(N).


INTUITION OPTIMAL (CALCULATING THE NSE AND PSE ON THE GO) :-

1. Consider an example case, in which a heights array is provided as follows [2,1,5,6,2,3]. First of all,
   we need to figure out the NSE (Next Smaller Element) and PSE(Previous Smaller Element) for each element.
   
2. Consider a scenario in which we are pushing all the elements to the stack, and at any instance the st.top()
   > arr[i], we need to move back because that's my calculation point and I do need to move back.

3. The ith element is the NSE and st.top() after the popping out is PSE.

4. Final area now can be calculated as maxArea = max(maxArea, (arr[i] * (nse - pse - 1))).

5. Time Complexity -> O(N) and Space Complexity -> O(N).

*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    vector<int> findNSE(vector<int>& arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);

        for(int i=n-1; i>=0; --i)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            
            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nse;
    }

    vector<int> findPSE(vector<int>& arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n);

        for(int i=0; i<n; ++i)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            
            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return pse;
    }

    int largestRectangleBF(vector<int>& height)
    {
        int n = height.size();

        int maxArea = 0;

        vector<int> pse = findPSE(height);
        vector<int> nse = findNSE(height);

        for(int i=0; i<n; ++i)
        {
            // int left = i - pse[i];
            // int right = nse[i] - i;

            maxArea = max(maxArea, height[i]*(nse[i] - pse[i] - 1));
        }

        return maxArea;
    }


    int largestRectangleOpt(vector<int>& height)
    {
        int n = height.size();
        int maxArea = 0;
        stack<int> st;
        vector<int> arr;

        for(int i=0; i<n; ++i)
        {
            int pse = 0;
            int nse = 0;
            int element = height[i];
            while(!st.empty() && height[st.top()] > height[i])
            {
                element = st.top();
                st.pop();

                pse = st.empty() ? -1 : st.top();
                nse = i;

                maxArea = max(maxArea, height[element] * (nse - pse - 1));
            }

            st.push(i);
        }

        return maxArea;
    }
};

int main()
{
    Solution sol;

    int n;
    cin>>n;

    vector<int> height(n);
    for(int i=0; i<n; ++i)
    {
        cin>>height[i];
    }

    int result1 = sol.largestRectangleBF(height);
    int result2 = sol.largestRectangleOpt(height);

    cout<<result1<<endl;
    cout<<result2<<endl;

    return 0;
}

/*
COMPLEXITY ANALYSIS:
- The time complexity of the solution is O(n), where n is the number of elements in the heights array.
  This is because we iterate through the array once to calculate the previous and next smaller elements.
- The space complexity is O(n) as well since we use two additional arrays to store the previous and next smaller elements.
*/

