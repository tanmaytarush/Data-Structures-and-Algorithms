/*
Find K-th Permutation Sequence

Problem Statement: Given N and K, where N is the sequence of numbers from 1 to N([1,2,3..... N]) find the Kth permutation sequence.

For N = 3  the 3!  Permutation sequences in order would look like this:-

Note: 1<=K<=N! Hence for a given input its Kth permutation always exists

Examples
Example 1:
Input:
 N = 3, K = 3
Output:
 “213”
Explanation:
 The sequence has 3! permutations as illustrated in the figure above. K = 3 corresponds to the third sequence.

Example 2:
Input:
 N = 3, K = 5 
Result:
 “312”
Explanation:
 The sequence has 3! permutations as illustrated in the figure above. K = 5 corresponds to the fifth sequence.
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

string kthPermutation(int n, int k)
{
    int fact = 1;
    vector<int> numbers;

    for(int i=1; i<n; ++i)
    {
        fact = fact*i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    k = k - 1;
    while(true)
    {
        ans += to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + (k / fact));
        if(numbers.size() == 0)
        {
            break;
        }

        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;

    int k;
    cin>>k;

    string result = kthPermutation(n, k);

    for(auto &c : result)
    {
        cout<<c<<" ";
    }

    return 0;
}