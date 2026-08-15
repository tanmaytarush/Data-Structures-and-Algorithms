/*

Palindrome Recursive Function

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
    bool isPalindrome(int i, vector<int>&arr)
    {
        if(i >= arr.size()/2)
        {
            return true;
        }

        if(arr[i] != arr[arr.size()-i-1])
        {
            return false;
        }

        return isPalindrome(i+1, arr);
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

    bool ans = sol.isPalindrome(0, arr);

    cout<<ans;

    return 0;
}