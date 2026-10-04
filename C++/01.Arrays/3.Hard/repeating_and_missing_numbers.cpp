/*
QUESTION:
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in the array. Find these two numbers.

Example:
Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and the smallest positive missing number is 1.

APPROACH:
To find the missing and repeating numbers in the given unsorted array, we can utilize the properties of summation and sum of squares. Let's denote the missing number as 'x' and the repeating number as 'y'.

1. Calculate the optimal sum 'optSum' using the formula: optSum = N * (N + 1) / 2, where N is the size of the array.
2. Calculate the optimal sum of squares 'opt2Sum' using the formula: opt2Sum = N * (N + 1) * (2 * N + 1) / 6.
3. Calculate the actual sum 'actSum' and actual sum of squares 'act2Sum' of the given array.
4. Find the difference between the optimal sum and the actual sum: xMinusY = optSum - actSum.
5. Find the difference between the optimal sum of squares and the actual sum of squares: x2MinusY2 = opt2Sum - act2Sum.
6. Calculate the sum of 'x' and 'y': xPlusY = x2MinusY2 / xMinusY.
7. Calculate 'x' and 'y' using the equations: x = (xPlusY + xMinusY) / 2 and y = xPlusY - x.

CODE:
*/

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>

pair<int, int> repeatingMissingBF(vector<int> &arr, int n)
{
    int repeating = -1;
    int missing = -1;
    for(int i=1; i<=n; ++i)
    {
        int count = 0;
        for(int j=0; j<=n-1; ++j)
        {
            if(arr[j] == i)
            {
                count ++;
            }
        }
        if(count == 2) repeating = i;
        else if(count == 0) missing = i;

        if(repeating!=-1 && missing!=-1)
        {
            break;
        }
    }
    return {repeating, missing};
}

pair<int, int> repeatingMissingBetter(vector<int> &arr, int n)
{
    vector<int> hash(n+1, 0);
    int repeating = -1;
    int missing = -1;
    for(int i=0; i<n; ++i)
    {
        hash[arr[i]]++;
    }
    for(int i=1; i<=n; ++i)
    {
        if(hash[i] == 0)
        {
            missing = i;
        }
        else if(hash[i] == 2)
        {
            repeating = i;
        }
    }
    return {repeating, missing};
}

pair<int, int> repeatingMissingOptimal(vector<int> &arr, int n)
{
    long long Sn = (n * (n+1))/2;
    long long S2n = (n * (n+1) * (2*n+1))/6;
    long long S = 0, S2 = 0;
    for(int i=0; i<n; ++i)
    {
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }

    long long val1 = S - Sn; // x - y
    long long val2 = S2 - S2n; // x2 - y2
    val2 = val2 / val1; // x + y

    long long x = (val1 + val2)/2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

pair<int, int> repeatingMissingBitManip(vector<int> &arr, int n)
{
    int xr = 0;
    for(int i=0; i<n; ++i)
    {
        xr = xr ^ arr[i];
        xr = xr ^ (i+1);
    }

    // Finding the differentiating bit number
    int number = xr & ~(xr - 1);

    int one = 0;
    int zero = 0;
    for(int i=0; i<n; ++i)
    {
        // Part of ones club
        if((arr[i] & number) != 0)
        {
            one = one ^ arr[i];
        }
        else
        {
            zero = zero ^ arr[i];
        }
    }

    // Xor all the elements in ones and zero club
    for(int i=1; i<=n; ++i)
    {
        if((i & number) != 0)
        {
            one = one ^ i;
        }
        else
        {
            zero = zero ^ i;
        }
    }

    // Finding the numbers
    int cnt = 0;
    for(int i=0; i<n; ++i)
    {
        if(arr[i] == zero) cnt++;
    }

    if(cnt == 2) return {zero, one};
    else return {one, zero};
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

    pair<int, int> result1 = repeatingMissingBF(arr, n);
    pair<int, int> result2 = repeatingMissingBetter(arr, n);
    pair<int, int> result3 = repeatingMissingOptimal(arr, n);
    pair<int, int> result4 = repeatingMissingBitManip(arr, n);

    cout<<result1.first<<" "<<result1.second<<" ";
    cout<<endl;
    
    cout<<result2.first<<" "<<result2.second<<" ";
    cout<<endl;
    
    cout<<result3.first<<" "<<result3.second<<" ";
    cout<<endl;

    cout<<result4.first<<" "<<result4.second<<" ";
    cout<<endl;

    return 0;
}

/*
TIME COMPLEXITY: O(N), where N is the size of the array.
SPACE COMPLEXITY: O(1).
*/
