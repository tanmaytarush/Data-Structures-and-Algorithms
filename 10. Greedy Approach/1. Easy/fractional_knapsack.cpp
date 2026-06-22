/*
Question:
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item.

Example:
Input:
N = 3, W = 50
values[] = {60, 100, 120}
weight[] = {10, 20, 30}
Output:
240.00
Explanation: Total maximum value of items
we can have is 240.00 from the given
capacity of the sack.

Approach:
1. We will define a comparator function that compares items based on their value/weight ratio in descending order.
2. We will sort the items array based on the comparator function.
3. Initialize a variable loot to keep track of the total value in the knapsack.
4. Iterate over the items array, starting from the item with the highest value/weight ratio.
5. If the weight of the current item is greater than the remaining capacity W, we take a fraction of the item to fill the remaining capacity.
   The fraction is determined by the remaining capacity divided by the weight of the current item.
6. Add the fraction of the item's value to the loot.
7. Reduce the remaining capacity by the weight of the item.
8. Repeat steps 5-7 until the remaining capacity becomes zero or all items are considered.
9. Finally, return the loot, which represents the maximum total value in the knapsack.

Complexity Analysis:
- The sorting step takes O(n log n) time, where n is the number of items.
- The iteration over the items takes O(n) time.
- Therefore, the overall time complexity is O(n log n).

Code:
*/

#include<iostream>
#include<iomanip> // for fixed setprecision(2)
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;

class Item
{
    public:
    int value;
    int weight;
};

class Solution
{
    public:
    static bool compare(const Item& a, const Item& b)
    {
        double r1 = double(a.value) / double(a.weight);
        double r2 = double(b.value) / double(b.weight);

        return r1 > r2;
    }

    double fractionalKnapsack(int W, vector<Item>&arr, int n)
    {
        sort(arr.begin(), arr.end(), compare);
        double answer = 0.0;

        for(int i=0; i<n && W>0; ++i)
        {
            if(arr[i].weight <= W)
            {
                answer += arr[i].value;
                W -= arr[i].weight;
            }
            else
            {
                answer += (double)arr[i].value * W / arr[i].weight;
                W=0;
            }
        }

        return answer;
    }
};

int main()
{
    Solution sol;
    int n, W;
    cin>>n>>W;

    vector<Item> arr(n);
    for(int i=0; i<n; ++i)
    {
        cin >> arr[i].value >> arr[i].weight;
    }

    double ans = sol.fractionalKnapsack(W, arr, n);
    cout<<fixed<<setprecision(2)<<ans<<endl;

    return 0;
}
