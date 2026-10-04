/*
QUESTION:
Given a binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

APPROACH:
To solve this problem, we can use a variation of the Largest Rectangle in Histogram problem.
1. First, we will calculate the heights of the histogram for each row in the matrix.
   - If the current element is '1', we increment the height of the histogram at that column by 1.
   - If the current element is '0', we reset the height of the histogram at that column to 0.
2. For each row, we calculate the largest rectangle area using the heights calculated in step 1.
   - We use the largestRectangleArea function, which calculates the largest rectangle area in a histogram.
   - The histogram heights are the heights of the current row up to that column.
3. Finally, we return the maximum area obtained from step 2.

Example:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
*/

/*

INTUITION :-

1.  Consider a scenario in which I am given an input matrix for which I need to calculate the maximum reactangle
    area. A sample matrix is as provided below:
                    [["1","0","1","0","0"],
                     ["1","0","1","1","1"],     (4x5)
                     ["1","1","1","1","1"],
                     ["1","0","0","1","0"]]

2.  Now from the above example we can consider each row an exception histogram, where 1 represents the height at
    that instance. With consequent movement across rows, I get to a point where if same column encounters 1, then 
    we add up to the final histogram, whereas if 0 is attained then we set it to 0 again.

3.  Further, with each addition over rows call out the maxAreaOfHistogram logic and store the maxArea in a 
    variable which would return the final answer.

4. Time Complexity -> O(N2) for Matrix and Space Complexity -> O(N).

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;

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
    int maxAreaHistogram(vector<int>& heights)
    {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        vector<int> result(n);

        for(int i=0; i<n; ++i)
        {
            while(!st.empty() && (i==n || heights[st.top()] > heights[i]))
            {
                int current = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxArea = max(maxArea, heights[current] * (nse - pse - 1));
            }

            st.push(i);
        }

        while(!st.empty())  // Process remaining stack for which nse is 'n'
        {
            int current = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, heights[current] * (nse - pse - 1));
        }

        return maxArea;
    }

    int maxAreaMatrix(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxArea = 0;
        vector<int> heights(m, 0);

        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(matrix[i][j] == 1)
                {
                    heights[j]++;
                }
                else
                {
                    heights[j] = 0;
                }
            }

            int area = maxAreaHistogram(heights);
            
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

int main()
{
    Solution sol;

    int n;
    cin>>n;

    int m;
    cin>>m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cin>>matrix[i][j];
        }
    }

    int result = sol.maxAreaMatrix(matrix);

    cout<<result<<endl;

    return 0;
}


/*
COMPLEXITY ANALYSIS:
- Let n be the total number of elements in the matrix, and m be the number of columns.
- The time complexity of the solution is O(n*m) because we iterate through each element of the matrix once.
- The space complexity is O(m) since we use additional arrays to store the heights and indices during the calculation.
  However, the space complexity can be considered O(1) if we modify the input matrix directly.
*/

