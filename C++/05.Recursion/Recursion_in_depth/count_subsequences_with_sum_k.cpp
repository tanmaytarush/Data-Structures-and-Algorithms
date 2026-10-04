#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

int count_subsequences_with_sum_k(int index, vector<int> &arr, int s, int sum, int n)
{
    // Important for N-Queen Method
    if(s > sum) // Don't go deeper into recursion tree
    {
        return 0;
    }
    if(index == n)
    {
        return sum==s;
    }

    int l = count_subsequences_with_sum_k(index + 1, arr, s + arr[index], sum, n);

    int r = count_subsequences_with_sum_k(index + 1, arr, s, sum, n);

    return l + r;
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

    int sum; 
    cin>>sum;

    cout<<count_subsequences_with_sum_k(0, arr, 0, sum, n);

    return 0;
}