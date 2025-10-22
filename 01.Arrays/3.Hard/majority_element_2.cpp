/*
QUESTION:
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

APPROACH:
To find all elements that appear more than ⌊ n/3 ⌋ times, we can use the Boyer-Moore Majority Vote algorithm. This algorithm helps us find potential candidates that could appear more than ⌊ n/3 ⌋ times in a single pass. After finding the candidates, we count their occurrences and return the elements that meet the criteria.

1. Initialize two candidate variables, c1 and c2, and their corresponding vote counters, vote1 and vote2.
2. Iterate through the array:
   - If the current element matches c1, increment vote1.
   - Else if the current element matches c2, increment vote2.
   - Else if vote1 is 0, assign the current element to c1 and set vote1 to 1.
   - Else if vote2 is 0, assign the current element to c2 and set vote2 to 1.
   - Else, decrement both vote1 and vote2.
3. After finding the potential candidates, count the occurrences of each candidate using cnt1 and cnt2.
4. If cnt1 is greater than ⌊ n/3 ⌋, add c1 to the result vector.
5. If cnt2 is greater than ⌊ n/3 ⌋ and c2 is different from c1, add c2 to the result vector.
6. Return the result vector containing the elements that appear more than ⌊ n/3 ⌋ times.


*/

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>

vector<int> majorityElementBF(vector<int> nums)
{
    int n = nums.size();
    vector<int> list;
    for(int i=0; i<n; ++i)
    {
        if(list.size() == 0 || list[i] != nums[i])
        {
            int count = 0;
            for(int j=0; j<n; ++j)
            {
                if(nums[j] == nums[i])
                    count ++;
            }
            if(count > (n/3))
                list.push_back(nums[i]);
        }
        if(list.size() == 2)
        {
            break;
        }
    }
    return list;
}

vector<int> majorityElementBetter(vector<int> nums)
{
    unordered_map<int, int> mpp;
    vector<int> list;
    int n = nums.size();
    for(int i=0; i<n; ++i)
    {
        mpp[nums[i]]++;
        if(mpp[nums[i]] > (n/3))
        {
            list.push_back(nums[i]);
        }
    }
    return list;
}

vector<int> majorityElementOptimal(vector<int> nums)
{
    int count1 = 0;
    int count2 = 0;
    int element1 = INT_MIN;
    int element2 = INT_MIN;

    int n = nums.size();

    for(int i=0; i<n; ++i)
    {
        if(count1 == 0 && element2 != nums[i])
        {
            count1 = 1;
            element1 = nums[i];
        }

        else if(count2 == 0 && element1 != nums[i])
        {
            count2 = 1;
            element2 = nums[i];
        }

        else if(element1 == nums[i]) count1++;
        else if(element2 == nums[i]) count2++;

        else
        {
            count1 --;
            count2 --;
        }
    }

    vector<int> list;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0; i<n; ++i)
    {
        if(nums[i] == element1) cnt1++;
        if(nums[i] == element2) cnt2++;
    }
    int minimum = int(n/3) + 1;
    if(cnt1 >= minimum) list.push_back(element1);
    if(cnt2 >= minimum) list.push_back(element2);

    return list;
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

    vector<int> result1 = majorityElementBF(arr);
    vector<int> result2 = majorityElementBetter(arr);
    vector<int> result3 = majorityElementOptimal(arr);

    for(vector<int>:: iterator it = result1.begin(); it!=result1.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    for(vector<int>:: iterator it = result2.begin(); it!=result2.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    for(vector<int>:: iterator it = result3.begin(); it!=result3.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}


// TIME COMPLEXITY: O(n), where n is the size of the input array.
// SPACE COMPLEXITY: O(1), as we are using a constant amount of extra space.
