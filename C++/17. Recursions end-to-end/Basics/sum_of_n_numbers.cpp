/*

Sum of first N natural numbers

*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    int sumofN(int sum, int i, vector<int>&arr)
    {
        if(i==arr.size())
        {
            return sum;
        }

        return sumofN(sum+arr[i], i+1, arr);
        // return, because chain doesn't follow back from base condition
    }
};  

int main()
{
    Solution sol;

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int res = sol.sumofN(0, 0, arr);

    cout<<res<<endl;

    return 0;
}