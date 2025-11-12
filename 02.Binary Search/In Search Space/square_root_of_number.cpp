/*
QUESTION:
Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).

Example:

Input:
x = 5
Output: 2
Explanation: Since 5 is not a perfect square, the floor of the square root of 5 is 2.

Input:
x = 4
Output: 2
Explanation: Since 4 is a perfect square, the square root of 4 is 2.

APPROACH:
We can use binary search to find the square root of x. 
1. Initialize the search space with low = 1 and high = x.
2. While low is less than or equal to high:
     - Calculate the mid of the search space.
     - If the square of mid is equal to x, return mid as the square root.
     - If the square of mid is less than x, update the answer to mid and set low = mid + 1 to search for a larger value.
     - If the square of mid is greater than x, set high = mid - 1 to search for a smaller value.
3. Return the answer, which represents the floor of the square root of x.

CODE:
*/
#include<iostream>
#include<vector>
using namespace std;

int floorSquare(int n)
{
    int low = 1;
    int high = n;
    long long ans = 1;
    while(low <= high)
    {
        long long mid = (low + high)/2;
        if(mid * mid <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int result = floorSquare(n);
    cout<<result;
    return 0;
}


/*
Time Complexity: O(log(x))
Space Complexity: O(1)
*/