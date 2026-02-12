/*
Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order.

Examples

Input: N = 3, arr[] = {5,2,1}
Output: 0,1,2,3,5,6,7,8
Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8

Input: N=3,arr[]= {3,1,2}
Output: 0,1,2,3,3,4,5,6
Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the sums we get will be  0,1,2,3,3,4,5,6
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

void subsetSums(int index, int sum, vector<int> &arr, vector<int> &ds)
{
    if(index == arr.size())
    {
        ds.push_back(sum);
        return;
    }

    // pick the element
    subsetSums(index + 1, sum + arr[index], arr, ds);

    // not pick the element
    subsetSums(index + 1, sum, arr, ds);
}

vector<int> Result(vector<int> &arr, int n)
{
    vector<int> ds;
    subsetSums(0, 0, arr, ds);
    sort(ds.begin(), ds.end());
    return ds;
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

    vector<int> result = Result(arr, n);
    for(vector<int>::iterator it = result.begin(); it != result.end(); ++it)
    {
        cout<<*it<<" ";
    }

    return 0;
} 