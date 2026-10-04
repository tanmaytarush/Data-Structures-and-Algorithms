/*
QUESTION:
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

EXAMPLES:
Input: piles = [3,6,7,11], h = 8
Output: 4

Input: piles = [30,11,23,4,20], h = 5
Output: 30

APPROACH:
- We can apply binary search to find the minimum eating speed.
- The eating speed can range from 1 to the maximum number of bananas in a pile.
- For each eating speed, we check if it is possible to finish eating all the bananas within h hours.
- We calculate the required time based on the eating speed, considering the number of bananas in each pile.
- If the required time is less than or equal to h, it means it is possible to finish eating all the bananas within h hours.
- We update the answer accordingly and continue the binary search.


CODE:
*/

#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
#include<math.h>

int findMax(vector<int> &arr)
{
    int maxi = INT_MIN;
    int n = arr.size();
    for(int i=0; i<n; ++i)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int countHours(vector<int> &arr, int hourly)
{
    int n = arr.size();
    int maximum = findMax(arr);
    int totalHours = 0; 
    for(int i=0; i<n; ++i)
    {
        totalHours += ceil((double)arr[i] / hourly);
    }
    return totalHours;
}

int KokoBananas(vector<int> &arr, int h)
{
    int n = arr.size();
    int low = 1;
    int high = findMax(arr);
    long long ans = 1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        int totalHours = countHours(arr, mid);

        if(totalHours <= h)
        {
            ans = mid;
            high = mid - 1;  // move left and increase the total hours from lower values
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

    int h;
    cin>>h;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    int result = KokoBananas(arr, h);
    cout<<result;
    return 0;
}

// TIME COMPLEXITY: O(N log M), where N is the number of piles and M is the maximum number of bananas in a pile.
// SPACE COMPLEXITY: O(1)