/*

Q.) Problem Statement: Given an array of size N. Find the highest and lowest frequency element.

Pre-requisite: Hashing Theory and  Counting frequencies of array elements

Examples:

Example 1:
Input: array[] = {10,5,10,15,10,5};
Output: 10 15
Explanation: The frequency of 10 is 3, i.e. the highest and the frequency of 15 is 1 i.e. the lowest.

Example 2:

Input: array[] = {2,2,3,4,4,2};
Output: 2 3
Explanation: The frequency of 2 is 3, i.e. the highest and the frequency of 3 is 1 i.e. the lowest.

*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Frequency{
public:
    // Returns tuple: (minEle, minFreq, maxEle, maxFreq)
    tuple<int, int, int, int> freq_min_max_vector(int arr[], int n)
    {
        vector<bool> visited(n, false);
        int maxEle = 0;
        int minEle = 0;
        int maxCount = 0;
        int minCount = n;

        for(int i=0; i<n; ++i)
        {
            if(visited[i] == true)
                continue;

            int count = 1;
            for(int j=i+1; j<n; ++j)
            {
                if(arr[i] == arr[j]) {
                    visited[j] = true;
                    count++;
                }
            }

            if(count > maxCount) {
                maxCount = count;
                maxEle = arr[i];
            }
            if(count < minCount) {
                minCount = count;
                minEle = arr[i];
            }
        }
        return make_tuple(minEle, minCount, maxEle, maxCount);
    }

    tuple<int, int, int, int> freq_min_max_map(int arr[], int n)
    {
        map<int, int> mpp;
        for(int i=0; i<n; ++i)
        {
            mpp[arr[i]]++;
        }

        int maxFreq = 0;
        int minFreq = n;
        int maxEle = 0;
        int minEle = 0;

        for(auto it : mpp)
        {
            int count = it.second;
            int element = it.first;

            if(count > maxFreq) {
                maxFreq = count;
                maxEle = element;
            }
            if(count < minFreq) {
                minFreq = count;
                minEle = element;
            }
        }
        return make_tuple(minEle, minFreq, maxEle, maxFreq);
    }
};

int main()
{
    Frequency f1;
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    auto result1 = f1.freq_min_max_vector(arr, n);
    auto result2 = f1.freq_min_max_map(arr, n);

    cout << "Vector method: minEle=" << get<0>(result1) << ", minFreq=" << get<1>(result1)
         << ", maxEle=" << get<2>(result1) << ", maxFreq=" << get<3>(result1) << endl;
    cout << "Map method: minEle=" << get<0>(result2) << ", minFreq=" << get<1>(result2)
         << ", maxEle=" << get<2>(result2) << ", maxFreq=" << get<3>(result2) << endl;
    return 0;
}