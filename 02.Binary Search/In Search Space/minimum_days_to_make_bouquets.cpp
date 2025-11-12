/*
Question:
You are given an integer array bloomDay, an integer m, and an integer k. You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, where the i-th flower will bloom on the bloomDay[i] day and can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets, return -1.

Example:

Input:
bloomDay = [1,10,3,10,2]
m = 3
k = 1

Output:
3

Explanation:
Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
*/

/*
Approach:
- Use binary search to find the minimum number of days required to make m bouquets.
- The search space will be between the minimum and maximum bloom day.
- For each mid value, simulate the process of making bouquets.
- Count the number of bouquets that can be made using k adjacent flowers on or after the current day.
- If the count is equal to or greater than m, update the answer and search in the lower half of the search space.
- If the count is less than m, search in the upper half of the search space.
*/

#include<iostream>
using namespace std;
#include<vector>
#include<map>

bool isPossible(vector<int> &arr, int day, int m, int k)
{
    int count = 0;
    int no_of_bouquets = 0;
    int n = arr.size();
    
    for(int i=0; i<n; ++i)
    {
        if(arr[i] <= day)
        {
            count ++;
        }
        else
        {
            no_of_bouquets += (count / k);
            count = 0;
        }
    }
    no_of_bouquets += (count / k);
    return no_of_bouquets >= m;  // true or false
}

int maxElement(vector<int> &arr)
{
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i=0; i<n; ++i)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int minElement(vector<int> &arr)
{
    int n = arr.size();
    int mini = INT_MAX;
    for(int i=0; i<n; ++i)
    {
        mini = min(mini, arr[i]);
    }
    return mini;
}

int minDaysBouquetsBF(vector<int> &arr, int m, int k)
{
    int minimum = minElement(arr);
    int maximum = maxElement(arr);

    for(int i = minimum; i<=maximum; ++i)
    {
        if(isPossible(arr, i, m, k) == 1)
        {
            return i;
        }
    }
    return -1;
}


int minDaysBouquetsOpt(vector<int> &arr, int m, int k)
{
    int low = minElement(arr);
    int high = maxElement(arr);
    int ans = 1;
    int n = arr.size();

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(n < m*k) return -1;

        if(isPossible(arr, mid, m, k) == 1)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;

    int m;
    cin>>m;

    int k;
    cin>>k;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    int result1 = minDaysBouquetsBF(arr, m, k);
    int result2 = minDaysBouquetsOpt(arr, m, k);

    cout<<result1<<" "<<result2;

    return 0;
}

// Time Complexity: The binary search approach takes O(log n), where n is the number of elements in the `bloomDay` array.
// Space Complexity: The space complexity is O(1) since we are using a constant amount of extra space.