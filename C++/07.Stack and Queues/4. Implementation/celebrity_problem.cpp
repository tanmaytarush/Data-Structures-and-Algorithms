/*
QUESTION:
Given a square NxN matrix representing people at a party, determine if there is a celebrity in the party. A celebrity is defined as a person who is known to all but does not know anyone at the party.

APPROACH:
To solve this problem, we can use a stack to keep track of potential celebrity candidates.
1. Initially, push all the people (indices) onto the stack.
2. While the stack size is greater than 1, do the following:
   - Pop two people 'a' and 'b' from the stack.
   - Check if 'a' knows 'b' and 'b' does not know 'a'. If true, push 'b' back onto the stack.
   - Check if 'b' knows 'a' and 'a' does not know 'b'. If true, push 'a' back onto the stack.
3. After the above loop, if the stack is empty, there is no celebrity, so return -1.
4. Otherwise, get the potential celebrity from the top of the stack.
5. Check if the potential celebrity is known by everyone else and does not know anyone else.
   - If true, return the potential celebrity index.
   - If false, return -1.

Example:
Input: N = 3, M[][] = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}}
Output: 1
Explanation: Both person 0 and person 2 know person 1. Therefore, person 1 is the celebrity.


INTUITION BRUTE FORCE (ITERATIVE) :-

1.  We are given a matrix of 0's and 1's having elements in order of NxM. So, by definition, in
    a celebrity matrix, an element is known by every other ith element so arr[i][element] = 1, 
    but in vice-versa fashion arr[element][i] = 0.

                    Example Input -> {{0, 1, 0}, 
                                      {0, 0, 0},   (NxN)
                                      {0, 1, 0}}

2.  We can have a minimum of 0 celebrities in a case where every adjacent column has 1. And, at max
    there can be 1 celebrity because all other elements need to know the current element.

3.  So we'll maintain two arrays, KnowsMe[] and IKnow[], and at any index of KnowMe[] if the value 
    is (n-1), and for the same index in IKnow[] the value is 0, then that index is considered to    
    be a celebrity.

4.  Time Complexity -> O(N2) and Space Complexity -> O(2N)


INTUITION OPTIMAL (TWO-POINTER) :-

1.  We can implement a two pointer approach for solving the same problem in which top pointer is at
    first row and bottom pointer is at the last row.

2.  The same logic applies here that at minimum, the total celebrities will be 0 and at the 
    maximum, the total celebrities will be 1, because all other elements need to know the current 
    one.

3.  If at any instance we would check that the given top and bottom are 1, i.e. arr[top][bottom] = 1,  
    then top cannot be a valid celebrity so in that case move top += 1. Similarly if arr[bottom][top] = 1,
    then bottom cannot be a valid celebrity, thus move bottom up so bottom -= 1.

4.  When top == bottom then check all rows at that index needs to be 0, and columns should be 1 except
    the current one. In this case, top is the celebrity answer.

5.  Time Complexity -> O(N) and Space Complexity -> O(1).

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

class Solution
{
    public:
    int celebrityVal(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<int> KnowsMe(n);
        vector<int> IKnow(n);
        int ans = 0;

        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(arr[i][j] == 1)
                {
                    IKnow[i] += 1;
                    KnowsMe[j] += 1; // 1 is known by someone
                }
            }
        }

        for(int i=0; i<n; ++i)
        {
            if(IKnow[i] == 0 && KnowsMe[i] == (n-1))
            {
                ans = i;
                break;
            }
        }

        return ans;
    }


    int CelebrityValOpt(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int top = 0;
        int bottom = n-1;

        while(top < bottom)
        {
            if(arr[top][bottom] == 1)
            {
                top++;
            }

            else if(arr[bottom][top] == 1)
            {
                bottom--;
            }

            else
            {
                top++;
                bottom--;
            }
        }

        int ans = 0;

        for(int i=0; i<n; ++i)
        {
            if(i == top) continue;
            if(arr[top][i] == 0 && arr[i][top] == 1)
            {
                ans = top;
            }
            else
            {
                return -1;
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

    vector<vector<int>> arr(n, vector<int>(n));
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cin>>arr[i][j];
        }
    }

    int result1 = sol.celebrityVal(arr);
    int result2 = sol.CelebrityValOpt(arr);

    cout<<result1<<endl;
    cout<<result2<<endl;

    return 0;
}  

/*
COMPLEXITY ANALYSIS:
- The time complexity is O(N) because each person is pushed onto and popped from the stack at most once.
- The space complexity is O(N) because the stack can store at most N elements.
*/
