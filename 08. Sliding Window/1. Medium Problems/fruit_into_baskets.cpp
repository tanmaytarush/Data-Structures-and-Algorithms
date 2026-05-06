/*QUESTION:
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits of size N, where fruits[i] is the type of fruit the ith tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
1. You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
2. Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of the baskets.
3. Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array fruits, return the maximum number of fruits you can pick.

Example 1:
Input: N = 3, fruits[] = {2, 1, 2}
Output: 3
Explanation: We can pick fruits from all three trees.


INTUITION BRUTE FORCE:

1.  Let us consider a set data structure which will store unique elements in a given range inside
    the movement in the fruits array. 

2.  We could inside the given spectrum, easily calculate and keep a track that the set size doesn't
    move beyond 2.

3.  Within each set range we would calculate the maximum length induced, and when the set length
    goes beyond the specified range, we simply break and move towards next iteration.


INTUITION OPTIMAL :-

1. Initialize an unordered_map mp to track the frequency of fruit types.
2. Initialize variables ans and start to keep track of the maximum number of fruits and the start index of the subarray.
3. Iterate through the fruit trees using a sliding window approach:
   - Increment the frequency of the current fruit type in the map.
   - Enter a while loop to adjust the start index until the number of fruit types in the map becomes more than 2.
   - During the adjustment, decrement the frequency of the fruit type at the start index and remove it from the map if the frequency becomes 0.
   - Update the ans by taking the maximum of the current ans and the length of the current subarray if the number of fruit types in the map is at most 2.
4. Return the maximum number of fruits (ans).

*/

#define LOG(x) cerr<<#x<<" "<<x<<endl;
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    int fruitIntoBasketBF(vector<int> &arr)
    {
        int n = arr.size();
        int maxLength = 0;

        for(int i=0; i<n; ++i)
        {
            unordered_set<int> st;
            for(int j=i; j<n; ++j)
            {
                st.insert(arr[j]);
                if(st.size() <= 2)
                {
                    maxLength = max(maxLength, j-i+1);
                }
                else
                {
                    break;
                }
            }
        }
        return maxLength;
    }

    int fruitIntoBasketBetter(vector<int> &arr)
    {
        int l = 0;
        int r = 0;
        int maxLength = 0;
        unordered_map<int, int> mpp;

        while(r < arr.size())
        {
            mpp[arr[r]]++;

            // first handle the false conditions
            while(mpp.size() > 2)
            {
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0)
                {
                    mpp.erase(arr[l]);
                }
                l++;
            }
            

            if(mpp.size() <= 2)
            {
                maxLength = max(maxLength, r-l+1);
            }

            r++;
        }

        return maxLength;
    }

    int fruitIntoBasket(vector<int> &arr)
    {
        int l=0;
        int r=0;
        int maxLength = 0;
        unordered_map<int, int> mpp;

        while(r < arr.size())
        {
            mpp[arr[r]]++;

            if(mpp.size() > 2)
            {
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0)
                {
                    mpp.erase(arr[l]);
                }
                l++;
            }

            if(mpp.size() <= 2)
            {
                maxLength = max(maxLength, r-l+1);
            }

            r++;
        }

        return maxLength;
    }
};  

int main()
{
    Solution sol;

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin>>arr[i];
    }

    int result_bf = sol.fruitIntoBasketBF(arr);
    int result_better = sol.fruitIntoBasketBetter(arr);
    int result_opt = sol.fruitIntoBasket(arr);

    cout<<result_bf<<endl;
    cout<<result_better<<endl;
    cout<<result_opt<<endl;

    return 0;
}

/*
COMPLEXITY ANALYSIS:
- Time complexity: O(N), where N is the number of fruit trees. We iterate through the fruit trees once using the sliding window approach.
- Space complexity: O(1) or O(2), as the size of the map can be at most 2 since we only have two baskets.
*/
